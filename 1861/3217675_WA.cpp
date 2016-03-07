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
bool canNet ( int tmax )
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
		if ( t[i].len > tmax )
			return false;
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
			j++;
		}
		if ( j == n )
			return true;
		i++;
	}
	return false;
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
	int begin = t[0].len;
	int end = t[m-1].len;
	int mid;
	while ( begin < end )
	{
		mid = (begin+end)/2;
		if ( !canNet(mid) )
			begin = mid+1;
		else
			end = mid;
	}
//	printf("begin=%d\n",begin);
//	printf("mid = %d\n",mid);
//	printf("end = %d\n",end);
	if ( !canNet(mid))
		mid++;
	for ( i = 0; i < m; i++ )
	{
		if ( t[i].len > mid )
			break;
	}
	j = i;
	printf("%d\n%d\n",mid,j);
	for ( i = 0; i < j; i++ )
		printf("%d %d\n",t[i].x,t[i].y);
}
int main ()
{
	input();
	return 0;
}