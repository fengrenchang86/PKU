#include <iostream>
using namespace std;
int a[20];
int que[200];
int n,m;
void input()
{
	int i;
	scanf("%d%d",&n,&m);
	for ( i = 0; i < m; i++ )
		scanf("%d",&que[i]);
	for ( i = 0; i < n; i++ )
		a[i] = -1;
}
int insert( int p, int k )
{
	int i,j,tmax,pi;
	for ( i = 0; i < n; i++ )
	{
		if ( a[i] == k )
			return 0;
		else if ( a[i] == -1 )
		{
			a[i] = k;
			return 1;
		}
	}
	pi = 0;
	tmax = -1;
	for ( i = 0; i < n; i++ )
	{
		for ( j = p; j < m; j++ )
		{
			if ( a[i] == que[j] )
				break;
		}
		if ( j > tmax )
		{
			pi = i;
			tmax = j;
		}
	}
	if ( tmax == -1 )
		a[0] = k;
	else
		a[pi] = k;
	return 1;
}
void solve ()
{
	int i,j=0;
	for ( i = 0; i < m; i++ )
		j += insert(i,que[i]);
	printf("%d\n",j);
}
int main ()
{
	int tc;
	cin>>tc;
	while ( tc-- )
	{
		input();
		solve();
	}
	return 0;
}