#include <iostream>
#include <queue>
using namespace std;
#define INF 1000000000
bool v[30000];
struct ac
{
	int pos;
	int val;
	int op;
};
int a[120];
int n, m;
queue<ac>que;
int path[120][30000];
bool oper[120];
void MakeOper(int pos, int val)
{
	if (pos == 1)
	{
		return;
	}
	int x = path[pos][val];
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
		if (q.pos == n)
		{
			v[q.val+10000] = 1;
		}
		else
		{
			que.push(q);
		}
		q.val = p.val + a[q.pos];
		path[q.pos][q.val+10000] = p.val+10000;
		if (q.pos == n)
		{
			v[q.val+10000] = 1;
		}
		else
		{
			que.push(q);
		}
	}
	if (v[m+10000])
	{
		MakeOper(n, m+10000);
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
	else
	{
		printf("NO\n");
	}
}
void Input()
{
	int i;
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