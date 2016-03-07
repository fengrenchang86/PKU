#include <iostream>
using namespace std;
int t[2][600];
int a[11000];
int n,m;
void init ()
{
	int i;
	for ( i = 0; i < 600; i++ )
	{
		t[0][i] = -1;
		t[1][i] = -1;
	}
}
void solve ()
{
	int i,j,x;
	scanf("%d%d",&n,&m);
	for ( i = 0; i < n; i++ )
		scanf("%d",&a[i]);
	t[0][0] = 0;
	t[0][1] = a[0];
	for ( i = 1; i < n; i++ )
	{
		for ( j = 0; j <= m; j++ )
		{
			t[i%2][j] = t[(i+1)%2][j+1];
			if ( j == 0 && t[(i+1)%2][0] > t[i%2][0] )
				t[i%2][0] = t[(i+1)%2][0];
			if ( j > 0 && t[(i+1)%2][j-1]+a[i] > t[i%2][j] )
				t[i%2][j] = t[(i+1)%2][j-1]+a[i];
		}
	}
	printf("%d\n",t[(n+1)%2][0]);
}
int main ()
{
	solve();
	return 0;
}