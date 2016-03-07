#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
#define INF 2000000000
double dp[1020][1020];
struct ac
{
	int x, y;
}t[1020];
struct acm
{
	double dis;
	int i, j;
};
queue<acm>que;
int n;
double GetDis(int i, int j)
{
	double ans = (t[i].x - t[j].x) * (t[i].x - t[j].x) +
		(t[i].y - t[j].y) * (t[i].y - t[j].y);
	ans = sqrt(ans);
	return ans;
}
void Input()
{
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &t[i].x, &t[i].y);
	}
}
void Solve()
{
	acm p, q;
	double ans = INF;
	while (!que.empty())
	{
		que.pop();
	}
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			dp[i][j] = INF;
		}
	}
	p.i = 1;
	p.j = 0;
	p.dis = GetDis(0, 1);
	dp[1][0] = p.dis;
	que.push(p);
	while (!que.empty())
	{
		p = que.front();
		que.pop();
		if (p.dis > dp[p.i][p.j])
		{
			continue;
		}
		if (p.i + 1 < n)
		{
			q.i = p.i + 1;
			q.j = p.j;
			q.dis = p.dis + GetDis(p.i, p.i+1);
			if (dp[q.i][q.j] > q.dis)
			{
				dp[q.i][q.j] = q.dis;
				que.push(q);
			}
			q.j = p.i;
			q.dis = p.dis + GetDis(p.j, p.i+1);
			if (dp[q.i][q.j] > q.dis)
			{
				dp[q.i][q.j] = q.dis;
				que.push(q);
			}
		}
		else
		{
			p.dis += GetDis(p.j, p.i);
			if (p.dis < ans)
			{
				ans = p.dis;
			}
		}
	}
	printf("%.2lf\n", ans);
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		Input();
		Solve();
	}
	return 0;
}
