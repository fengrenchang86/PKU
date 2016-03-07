#include<iostream>
using namespace std;
#define N 110
#define inf 20000000000000.000
double c[N][N], r[N][N];
bool visit[N];
double dis[N];
int n, beginP;
double beginMoney;
bool BellmanFord()
{
	bool tag;
	int i, j, k;
	for(i = 0; i <= n; i++)
	{
		dis[i] = inf;
		visit[i] =false;
	}
	dis[beginP] = beginMoney;
	for(j = 0; j < n; j++)
	{
		k = -1;
		for(i = 0; i < n; i++)
		{
			if(!visit[i] && (k == -1 || dis[i] < dis[k]))
				k = i;
		}
		visit[k] = true;
		for(i = 0; i < n; i++)
		{
			if(!visit[i] && r[i][k] > 0 && dis[i] - (dis[k]/r[i][k]+c[i][k]) >= 0.00000001)
				dis[i] = (dis[k]/r[i][k]+c[k][i]);
		}
	}
	tag = true;
	for(j = 0; tag && j <= n; j++)
	{
		tag = false;
		for(i = 0; i < n; i++)
		{
			for(k = 0; k < n; k++)
			{
				if(r[i][k] > 0 && dis[i] - (dis[k]/r[i][k]+c[i][k]) >= 0.00000001)
				{
					dis[i] = (dis[k]/r[i][k]+c[k][i]);
					tag = true;
				}
			}
		}
	}
	return beginMoney - dis[beginP] >= 0.00000001;
}
void input()
{
	int i, j, m, x, y;
	double r1, c1, r2, c2;
	scanf("%d %d %lf", &m, &beginP, &beginMoney);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			r[i][j] = c[i][j] = -1.0;
	}
	for(i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		x--;
		y--;
		scanf("%lf %lf %lf %lf", &r1, &c1, &r2, &c2);
		r[x][y] = r1;
		r[y][x] = r2;
		c[x][y] = c1;
		c[y][x] = c2;
	}
}
void solve()
{
	input();
	if(BellmanFord())
		printf("YES\n");
	else
		printf("NO\n");
}
int main()
{
	while(scanf("%d", &n) != EOF)
		solve();
	return 0;
}