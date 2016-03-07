#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;
#define INF 2000000000

struct STOP
{
	int x, y;
	int type;
}kstop[210];

double c[210][210];
bool visit[210];
double dis[210];
int n;
void Init()
{
	int i, j;
	for(i = 0; i < 210; i++)
	{
		for(j = 0; j < 210; j++)
			c[i][j] = INF;
	}
}
void Input()
{
	int i, j, k = 2;
	n = 2;
	double fDis;
	Init();
	scanf("%d %d %d %d", &kstop[0].x, &kstop[0].y, &kstop[1].x, &kstop[1].y);
	while(scanf("%d %d", &kstop[n].x, &kstop[n].y) != EOF)
	{
		if(kstop[n].x == -1 && kstop[n].y == -1)
		{
			for(i = k+1; i < n ;i++)
			{
				j = i-1;
				fDis = sqrt(double(kstop[i].x-kstop[j].x)*double(kstop[i].x-kstop[j].x) + 
					double(kstop[i].y-kstop[j].y)*double(kstop[i].y-kstop[j].y)) / 4.0;
				if(c[i][j] > fDis)
				{
					c[i][j] = c[j][i] = fDis;
				}
			}
			k = n;
		}
		else
		{
			n++;
		}
	}
}
void dij()
{
	int i, j, k;
	int tMin;
	memset(visit, false, sizeof(visit));
	for(i = 1; i < n; i++)
	{
		dis[i] = INF;
	}
	dis[0] = 0.0;
	for(i = 0; i < n; i++)
	{
		tMin = INF;
		for(j = 0; j < n; j++)
		{
			if(!visit[j] && dis[j] < tMin)
			{
				tMin = dis[j];
				k = j;
			}
		}
		if(visit[k] || dis[k] == INF)
			break;
		visit[k] = true;
		for(j = 0; j < n; j++)
		{
			if(!visit[j] && c[j][k] != INF && dis[j] > dis[k] + c[j][k])
			{
				dis[j] = dis[k] + c[j][k];
				if(j == 1)
					dis[j] = dis[k] + c[j][k];
			}
		}
	}
	printf("%d\n", int(60.0*dis[1]/10000.0));
}
void Solve()
{
	int i, j;
	double fDis;
	for(i = 0; i < n; i++)
	{
		c[i][i] = 0;
	}
	for(i = 0; i < n; i++)
	{
		for(j = i+1; j < n; j++)
		{
			fDis = sqrt((kstop[i].x-kstop[j].x)*(kstop[i].x-kstop[j].x) + 
				(kstop[i].y-kstop[j].y)*(kstop[i].y-kstop[j].y));
			if(c[i][j] > fDis)
			{
				c[i][j] = c[j][i] = fDis;
			}
		}
	}
	dij();
}
int main()
{
	Input();
	Solve();
	return 0;
}