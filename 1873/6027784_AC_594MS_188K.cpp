#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

struct point
{
	int x;
	int y;
	int val;
	int len;
}a[50], p[50],up[50],down[50];//分别保存：所有的点，上凸包，下凸包
int n;
bool use[30];
bool visit[30];
double g_ansVal;
int g_ansNumber;
double g_ansRestLen;

int cmp( const void *a , const void *b ) 
{ 
	struct point *c = (point *)a; 
	struct point *d = (point *)b; 
	if(c->x != d->x) return c->x - d->x; 
	else return d->y - c->y; 
}
int right ( point t[], int a, int b, int c )//判断t[a],t[b],t[c]是否右拐
{
	int m = (t[b].x-t[a].x)*(t[c].y-t[a].y)-(t[c].x-t[a].x)*(t[b].y-t[a].y);
	if ( m < 0 )
		return 1;
	else
		return 0;
	return 0;
}
int make_up ( int n )
{
	int k,i;
	up[0] = p[0];
	up[1] = p[1];
	i = 2;
	k = 2;
	while ( i < n )
	{
		up[k] = p[i];
		while ( k > 1 && right(up,k-2,k-1,k) == 0 )
		{
			up[k-1] = up[k];
			k--;
		}
		k++;
		i++;
	}
	return k;
}
int make_down ( int n )
{
	int k,i;
	down[0] = p[n-1];
	down[1] = p[n-2];
	k = 2;
	i = n-3;
	while ( i >= 0 )
	{
		down[k] = p[i];
		while ( k > 1 && right(down,k-2,k-1,k) == 0 )
		{
			down[k-1] = down[k];
			k--;
		}
		k++;
		i--;
	}
	return k;
}
int IsFit()
{
	double dLen = 0.0;
	int nValue = 0;
	int i, j = 0;
	int n1, n2;
	int k;
	double dNeed = 0.0;
	for (i = 0; i < n; i++)
	{
		if (visit[i] == 0)
		{
			p[j] = a[i];
			j++;
		}
		else
		{
			dLen += a[i].len;
			nValue += a[i].val;
		}
	}
	if (j > 1)
	{
		qsort(p, j, sizeof(p[0]), cmp);
		n1 = make_up(j);
		n2 = make_down(j);
		for (k = 1; k < n2; k++)
		{
			up[n1++] = down[k];
		}
		for (i = 1; i < n1; i++)
		{
			dNeed += sqrt(double(up[i].x - up[i-1].x)*(up[i].x-up[i-1].x) + (up[i].y - up[i-1].y) * (up[i].y - up[i-1].y));
		}
	}

	if (dNeed <= dLen)
	{
		if (nValue < g_ansVal || nValue == g_ansVal && j < g_ansNumber)
		{
			g_ansVal = nValue;
			g_ansNumber = j;
			g_ansRestLen = dLen - dNeed;
			for (i = 0; i < n; i++)
			{
				use[i] = visit[i];
			}
		}
	}
	return 0;
}
void dfs(int lay)
{
	if (lay == n)
	{
		IsFit();
		return;
	}
	visit[lay] = true;
	dfs(lay+1);
	visit[lay] = false;
	dfs(lay+1);
}
void Solve(int tc)
{
	int i;
	for (i =0 ; i < n; i++)
	{
		scanf("%d %d %d %d", &a[i].x, &a[i].y, &a[i].val, &a[i].len);
	}
	memset(visit, 0, sizeof(visit));
	g_ansNumber = n + 1;
	g_ansVal = 2000000000;
	dfs(0);
	if (tc != 1)
	{
		printf("\n");
	}
	printf("Forest %d\n", tc);
	printf("Cut these trees:");
	for (i = 0; i < n; i++)
	{
		if (use[i])
		{
			printf(" %d", i+1);
		}
	}
	printf("\nExtra wood: %.2lf\n", g_ansRestLen);
}
int main()
{
	int tc = 1;
	while(scanf("%d",&n) != EOF && n != 0)
	{
		Solve(tc);
		tc++;
	}
	return 0;
}