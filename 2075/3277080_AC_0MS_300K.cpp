#include <map>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
map<string,int>t;
bool visit[10000];
int father[1000];
int getfather ( int x )
{
	while ( x != father[x] )
		x = father[x];
	return x;
}
struct node
{
	int x,y;
	double dist;
}v[10000];
int cmp ( const void*a, const void*b )
{
	struct node*c=(node*)a;
	struct node*d=(node*)b;
	return c->dist > d->dist ? 1:-1;
}
int main ()
{
	double len,dist,sum;
	char a[30],b[30];
	int n,m,i,j;
	int x,y,fx,fy;
	while ( cin>>len>>n )
	{
		t.clear();
		sum = 0.0;
		for ( i = 1; i <= n; i++ )
		{
			cin>>a;
			t[a] = i;
			visit[i] = false;
			father[i] = i;
		}
		cin>>m;
		for ( i = 0; i < m; i++ )
		{
			cin>>a>>b>>dist;
			v[i].x = t[a];
			v[i].y = t[b];
			v[i].dist = dist;
		}
		qsort(v,m,sizeof(v[0]),cmp);
		j = 0;
		for ( i = 0; i < m; i++ )
		{
			if ( visit[v[i].x] == false )
				fx = -1;
			else
				fx = getfather(v[i].x);
			if ( visit[v[i].y] == false )
				fy = -1;
			else
				fy = getfather(v[i].y);
			if ( fx == -1 && fy == -1 )
			{
				j++;
				father[v[i].x] = v[i].y;
				visit[v[i].x] = visit[v[i].y] = true;
				sum += v[i].dist;
			}
			else if ( fx == -1 )
			{
				j++;
				father[v[i].x] = fy;
				visit[v[i].x] = true;
				sum += v[i].dist;
			}
			else if ( fy == -1 )
			{
				j++;
				father[v[i].y] = fx;
				visit[v[i].y] = true;
				sum += v[i].dist;
			}
			else
			{
				if ( fx != fy )
				{
					father[fx] = fy;
					j++;
					sum += v[i].dist;
				}
			}
		}
		if ( sum > len)
			printf("Not enough cable\n");
		else
			printf("Need %.1lf miles of cable\n",sum);
	}
	return 0;
}