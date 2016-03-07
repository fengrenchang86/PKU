#include <iostream>
#include <queue>
using namespace std;
#define INF 1000000000
struct ac
{
	int pos;
	int val;
};
int a[120];
int n, m, sum;
queue<ac>que;
short path[120][20010];
bool v[120][20010];
bool oper[120];
void MakeOper(int pos, short val)
{
	if (pos == 1)
	{
		return;
	}
	short x = path[pos][val];
	if (x < val)
	{
		oper[pos] = 1;
	}
	else
	{
		oper[pos] = 0;
	}
	MakeOper(pos-1, x);
}
void ShowAns()
{
	int i, j = 0;
	for (i = 1; i < n; i++)
	{
		if (oper[i+1])
		{
			printf("%d\n", i-j);
			j++;
		}
	}
	while (j < n - 1)
	{
		printf("1\n");
		j++;
	}
}
void Solve()
{
	memset(v, 0, sizeof(v));
	while (!que.empty())
	{
		que.pop();
	}
	ac p, q;
	p.pos = 2;
	p.val = a[1]-a[2];
	path[2][p.val+10000] = a[1] + 10000;
	que.push(p);
	while (!que.empty())
	{
		p = que.front();
		que.pop();
		q.pos = p.pos + 1;
		q.val = p.val - a[q.pos];
		path[q.pos][q.val+10000] = p.val+10000;
		if (q.pos < n && !v[q.pos][q.val + 10000])
		{
			v[q.pos][q.val + 10000] = 1;
			que.push(q);
		}
		q.val = p.val + a[q.pos];
		path[q.pos][q.val+10000] = p.val+10000;
		if (q.pos < n && !v[q.pos][q.val + 10000])
		{
			v[q.pos][q.val + 10000] = 1;
			que.push(q);
		}
	}
		MakeOper(n, short(m+10000));
// 		printf("%d", a[1]);
// 		int i, j = a[1];
// 		for (i = 2; i <= n; i++)
// 		{
// 			if (oper[i])
// 			{
// 				j += a[i];
// 				printf("+");
// 			}
// 			else
// 			{
// 				j -= a[i];
// 				printf("-");
// 			}
// 			printf("%d", a[i]);
// 		}
// 		printf("=%d\n", j);
// 		printf("YES\n");
		ShowAns();
}
void Input()
{
	int i;
	sum = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
}
int main()
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		Input();
		Solve();
	}
	return 0;
}