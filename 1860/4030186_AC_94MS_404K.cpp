#include<iostream>
using namespace std;
#define N 110
#define ACM 1e-8
const double inf = 20000000000000.000;
double c[N][N], r[N][N];
double dis[N];
int n, beginP;
double beginMoney;
void init()
{
//	int i;
//	for(i = 0; i < n; i++)
//		list[i] = NULL;
}
/*
void insert(int x, int y, double r, double c)
{
	ac *p = new ac;
	p->c = c;
	p->r = r;
	p->v = y;
	p->next = list[x];
	list[x] = p;
}
*/
bool BellmanFord()
{
	bool tag;
	double temp;
	int i, j, k;
	for(i = 0; i <= n; i++)
	{
		dis[i] = 0.0;
	}
	dis[beginP] = beginMoney;
/*
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
			temp = (dis[k] - c[k][i]) * r[k][i];
			if(!visit[i] && temp - dis[i] >= ACM)
				dis[i] = temp;
		}
	}
	*/
	tag = true;
	while(tag)
	{
		tag = false;
		for(i = 0; i < n; i++)
		{
			if(dis[i] < ACM)
				continue;
/*
			p = list[i];
			while(p != NULL)
			{
				temp = (dis[i] - p->c) * p->r;
				if(temp - dis[p->v] >= ACM)
				{
					dis[p->v] = temp;
					tag = true;
				}
				p = p->next;
			}
			*/
			for(j = 0; j < n; j++)
			{
				for(k = 0; k < n; k++)
				{
					if(c[j][k] < 0)
						continue;
					temp = (dis[j] - c[j][k]) * r[j][k];
					if(dis[k] < temp - ACM)
					{
						dis[k] = temp;
						tag = true;
					}
				}
			}
		}

		if(dis[beginP] - beginMoney >= ACM)
			return true;
	}
	return dis[beginP] - beginMoney >= ACM;
}
void input()
{
	int i,  m, x, y;
	double r1, c1, r2, c2;
	scanf("%d %d %lf", &m, &beginP, &beginMoney);
	beginP--;
	init();
	for(i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		x--;
		y--;
		scanf("%lf %lf %lf %lf", &r1, &c1, &r2, &c2);
//		insert(x, y, r1, c1);
//		insert(y, x, r2, c2);
		c[x][y] = c1;
		r[x][y] = r1;
		c[y][x] = c2;
		r[y][x] = r2;
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