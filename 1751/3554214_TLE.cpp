#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int x,y;
	int len;
}a[600000];
struct point
{
	int x,y;
}p[1000];
bool visit[1000];
int father[1000];
int n,m;
int cmp ( const void*a, const void*b )
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	return c->len - d->len;
}
int getfather ( int k )
{
	while ( father[k] != k )
		k = father[k];
	return k;
}
void input()
{
	int i,j,k=0;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
		scanf("%d%d",&p[i].x,&p[i].y);
	for ( i = 0; i < n; i++ )
	{
		for ( j = i+1; j < n; j++ )
		{
			a[k].x = i;
			a[k].y = j;
			a[k].len = (p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y);
			k++;
		}
	}
	m = k;
}
void solve ()
{
	int i,num,x,y,fx,fy;
	for ( i = 0; i < n; i++ )
	{
		father[i] = i;
		visit[i] = false;
	}
	qsort(a,m,sizeof(a[0]),cmp);
	scanf("%d",&num);
	for ( i = 0; i < num; i++ )
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		if ( visit[x] == false && visit[y] == false )
		{
			visit[x] = visit[y] = true;
			father[x] = y;
		}
		else if ( visit[x] == false )
		{
			visit[x] = true;
			father[x] = getfather(y);
		}
		else if ( visit[y] == false )
		{
			visit[y] = true;
			father[y] = getfather(x);
		}
		else
		{
			fx = getfather(x);
			fy = getfather(y);
			if ( fx != fy )
				father[fx] = fy;
		}
	}
	int j = 0,k = 0;
	for ( i = 0; i < m; i++ )
	{
		if ( visit[a[i].x] == false )
			fx = -1;
		else
			fx = getfather(a[i].x);
		if ( visit[a[i].y] == false )
			fy = -1;
		else
			fy = getfather(a[i].y);
		if ( fx == -1 && fy == -1 )
		{
			p[k].x = a[i].x;
			p[k].y = a[i].y;
			k++;
			visit[a[i].x] = true;
			visit[a[i].y] = true;
			father[a[i].x] = a[i].y;
		}
		else if ( fx == -1 )
		{
			p[k].x = a[i].x;
			p[k].y = a[i].y;
			k++;
			visit[a[i].x] = true;
			father[a[i].x] = fy;
		}
		else if ( fy == -1 )
		{
			p[k].x = a[i].x;
			p[k].y = a[i].y;
			k++;
			visit[a[i].y] = true;
			father[a[i].y] = fx;
		}
		else
		{
			if ( fx != fy )
			{
				p[k].x = a[i].x;
				p[k].y = a[i].y;
				k++;
				father[fx] = fy;
			}
		}
	}
	for ( i = 0; i < k; i++ )
	{
		printf("%d %d\n",p[i].x+1,p[i].y+1);
	}
}
int main ()
{
	input();
	solve();
	return 0;
}