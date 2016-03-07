#include <iostream>
#include <queue>
using namespace std;
char chInput[500];
int val[300][10];
bool use[260][1000010];
short path[260][1000010];
short dist[260][1000010];
int n, m;
struct ac
{
	int pos;
	int data;
	int add;
};
queue<ac>que;
void Init()
{
	int i, j;
	n = 0;
	m = 0;
	while (chInput[n] != '=')
	{
		n++;
	}
	i = n + 1;
	while (chInput[i] != NULL)
	{
		m *= 10;
		m += (chInput[i] - '0');
		i++;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= m; j++)
		{
			dist[i][j] = 0;
		}
	}
	for (i = 0; i < n; i++)
	{
		val[i][1] = chInput[i] - '0';
		for (j = 2; j <= 5; j++)
		{
			val[i][j] = val[i][j-1] * 10 + chInput[i+j-1] - '0';
		}
	}
}
void PrintAns(int pos, int data)
{
	int pre = path[pos][data] + 1;
	int num = pos - pre + 1;
	if (pre != 0)
	{
		PrintAns(path[pos][data], data - val[pre][num]);
		printf("+");
	}
	printf("%d", val[pre][num]);
}
void Solve()
{
	ac p, q;
	int i;
	while (!que.empty())
	{
		que.empty();
	}
	p.pos = -1;
	p.data = 0;
	p.add = 0;
	que.push(p);
	while (!que.empty())
	{
		p = que.front();
		que.pop();
		if (p.pos > 0 && dist[p.pos][p.data] < p.add || chInput[p.pos + 1] == '0')
		{
			continue;
		}
		for (i = 1; i <= 5; i++)
		{
			q.data = p.data + val[p.pos + 1][i];
			if (q.data <= m && p.pos + i < n && 
				(dist[p.pos + i][q.data] == 0 || dist[p.pos + i][q.data] > p.add + 1))
			{
				dist[p.pos + i][q.data] = p.add + 1;
				q.pos = p.pos + i;
				q.add = p.add + 1;
				que.push(q);
				path[q.pos][q.data] = p.pos;
			}
		}
	}
	if (!dist[n-1][m])
	{
		printf("IMPOSSIBLE\n");
		return;
	}
	PrintAns(n-1, m);
	printf("=%d\n", m);
}
int main()
{
	int tc = 1;
	while (scanf(" %s", &chInput) != EOF)
	{
		if (strcmp(chInput, "0=0") == 0)
		{
			break;
		}
		Init();
		printf("%d. ", tc++);
		Solve();
	}
	return 0;
}