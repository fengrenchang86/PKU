#include <iostream>
using namespace std;
int a[120][120];
int b[120][120];
int t[10003];
int h[10003];
int max = 1;
void bfs ( int x, int y, int lay )
{
	if ( lay > max )
	{
		max = lay;
	}
	if ( lay + h[a[x][y]] <= max )
		return;
	if ( a[x-1][y] < a[x][y]  )
	{
			b[x-1][y] = 1;
			bfs(x-1,y,lay+1);
	}
	if ( a[x][y-1] < a[x][y] )
	{
			b[x][y-1] = 1;
			bfs ( x, y-1 ,lay+1);
	}
	if ( a[x][y+1] < a[x][y] )
	{
			b[x][y+1] = 1;
			bfs ( x, y+1 ,lay+1);
	}
	if ( a[x+1][y] < a[x][y] ) 
	{
			b[x+1][y] = 1;
			bfs ( x+1, y ,lay+1);
	}
}
int main ()
{
	int m,n,i,j,c = 0;
	int k;
	cin>>m>>n;
	memset(t,0,sizeof(t));
	memset(h,0,sizeof(h));
	for ( i = 1; i <= m; i++ )
		for ( j = 1; j<=n; j++ )
			b[i][j] = 0;
	for ( i = 1; i <= m; i++ )
		a[i][0] = a[i][n+1] = 10002;
	for ( j = 1; j <= n; j++ )
		a[0][j] = a[m+1][j] = 10002;
	for ( i = 1; i <= m; i++ )
	{
		for ( j = 1;  j<= n; j++ )
		{
			cin>>a[i][j];
			t[c++] = a[i][j];
		}
	}
	for ( i = 0; i < c-1; i++ )
	{
		for ( j = i+1; j < c; j++ )
		{
			if ( t[i] > t[j] )
			{
				k = t[i];
				t[i] = t[j];
				t[j] = k;
			}
		}
	}
	for ( i = 0; i < c; i++ )
	{
		h[t[i]] = i;
//		printf("%d(%d):  %d\n",i,t[i],h[t[i]]);
	}
	for ( i = m; i >= 1; i-- )
	{
		for ( j = 1; j <= n ;j++ )
		{
			if ( b[i][j] == 0 )
			{
				bfs(i,j,1);
			}
		}
	}
	cout<<max<<endl;
	return 0;
}