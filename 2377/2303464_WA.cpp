#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int x;
	int y;
	int d;
}a[20100];
int p[1001][1001];
int v[1010];
bool visit[1010];
int cmp( const void *a ,const void *b) 
{ 
     return (*(ac *)b).d - (*(ac *)a).d; 
} 
int find ( int x )
{
	int i = x;
	while ( i != -1 )
	{
		x = i;
		i = v[i];
	}
	return x;
}
void join( int x, int y )
{
	x = find(x);
	y = find(y);
	v[x] = y;
}
int main ()
{
	int m,n;
	int i,j;
	int cost = 0;
	cin>>n>>m;
	for ( i = 0; i <= n; i++ )
	{
		v[i] = -1;
		visit[i] = false;
	}
	for ( i = 0; i < m; i++ )
		cin>>a[i].x>>a[i].y>>a[i].d;
	qsort(a,m,sizeof(a[0]),cmp);
	j = 0;
	for ( i = 1; i < n && j < m; i++ )
	{
			if ( visit[a[j].x] == false || visit[a[j].y] == false )
			{
				join(a[j].x,a[j].y);
				cost+=a[j].d;
				visit[a[j].x] = true;
				visit[a[j].y] = true;
				break;
			}
			else if ( visit[a[j].x] == true && visit[a[j].y] == true && find(a[j].x)!=find(a[j].y))
			{
				join(a[j].x,a[j].y);
				cost+=a[j].d;
				break;
			}
			j++;
	}
	if ( j == m ) 
		cout<<"-1"<<endl;
	else
		cout<<cost<<endl;
	return 0;
}