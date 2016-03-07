#include <map>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
map<string,int>t;
bool visit[10000];
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
	int x,y;
	while ( cin>>len>>n )
	{
		t.clear();
		sum = 0.0;
		for ( i = 1; i <= n; i++ )
		{
			cin>>a;
			t[a] = i;
			visit[i] = false;
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
		visit[1] = true;
		j = 1;
		for ( i = 0; i < m && j < n; i++ )
		{
			if ( visit[v[i].x] == true && visit[v[i].y] == false )
			{
				j++;
				visit[v[i].y] = true;
				sum += v[i].dist;
				i = 0;
			}
			else if ( visit[v[i].x] == false && visit[v[i].y] == true )
			{
				j++;
				visit[v[i].x] = true;
				sum += v[i].dist;
				i = 0;
			}
		}
		if ( sum > len )
			printf("Not enough cable\n");
		else
			printf("Need %.1lf miles of cable\n",sum);
	}
	return 0;
}