#include <iostream>
using namespace std;
int t[11000][600];
int a[11000];
int n,m;
void init ()
{
	int i,j;
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j <= m; j++ )
			t[i][j] = -1;
	}
}
void solve ()
{
	int i,j,x;
	scanf("%d%d",&n,&m);
	for ( i = 0; i < n; i++ )
		scanf("%d",&a[i]);
	init();
	t[0][0] = 0;
	t[0][1] = a[0];
	for ( i = 1; i < n; i++ )
	{
		for ( j = 0; j <= m; j++ )
		{
			if ( j < m && t[i-1][j+1] != -1 )
				t[i][j] = t[(i-1)][j+1];
			if ( t[i-1][0] != -1 && j == 0 && t[(i-1)][0] > t[i][0] )
				t[i][0] = t[(i-1)][0];
			if ( t[i-1][j-1] != -1 && j > 0 && t[(i-1)][j-1]+a[i] > t[i][j] )
				t[i][j] = t[(i-1)][j-1]+a[i];
		}
	}
	printf("%d\n",t[(n-1)][0]);
}
int main ()
{
	solve();
	return 0;
}