#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int x,y,len;
	bool v;
}t[1100000];
int father[1100];
bool visit[1100];
int n,m,Sum;
int cmp ( const void*a, const void*b )
{
	struct ac* c= (ac*)a;
	struct ac* d = (ac*)b;
	return c->len-d->len;
}
int getfather ( int k )
{
	while ( father[k] != k )
		k = father[k];
	return k;
}
int canNet (  )
{
	int i,j=0;
	int fx,fy;
	for ( i = 1; i <= n; i++ )
	{
		father[i] = i;
		visit[i] = false;
	}
	i = 0;
	while ( i < m )
	{
		if ( visit[t[i].x] == false )
			fx = -1;
		else
			fx = getfather(t[i].x);
		if ( visit[t[i].y] == false )
			fy = -1;
		else
			fy = getfather(t[i].y);
		if ( fx == -1 && fy == -1 )
		{
			visit[t[i].x] = visit[t[i].y] = true;
			father[t[i].x] = t[i].y;
			j+=2;
		}
		else if ( fx == -1 )
		{
			visit[t[i].x] = true;
			father[t[i].x] = t[i].y;
			j++;
		}
		else if ( fy == -1 )
		{
			visit[t[i].y] = true;
			father[t[i].y] = t[i].x;
			j++;
		}
		else if ( fx != fy )
		{
			father[fx] = fy;
		}
		if ( j == n )
			break;
		i++;
	}
	return i;
}
void input ()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d%d",&t[i].x,&t[i].y,&t[i].len);
		t[i].v = false;
	}
	qsort(t,m,sizeof(t[0]),cmp);
	j = canNet();
	printf("%d\n",t[j].len);
	printf("%d\n",j+1);
	for ( i = 0; i <= j; i++ )
		printf("%d %d\n",t[i].x,t[i].y);
}
int main ()
{
	input();
	return 0;
}