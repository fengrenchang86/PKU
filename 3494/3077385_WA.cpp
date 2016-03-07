#include <iostream>
using namespace std;
const int N = 3300;
char a[N][N];
int h[N][N];
struct ac
{
	int x,y;
}stack[N*N];
int tmax,n,m;
void input ()
{
	int i,j;
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < m; j++ )
			scanf(" %c",&a[i][j]);
	}
	for ( i = 0; i < m; i++ )
	{
		h[0][i] = a[0][i]-'0';
	}
	for ( i = 1; i < n; i++ )
	{
		for ( j = 0; j < m; j++ )
		{
			if ( a[i][j] == '0' )
				h[i][j] = 0;
			else
				h[i][j] = h[i-1][j] + 1;
		}
	}
	for ( i = 0; i < n; i++ )
		h[i][m] = -1;
}
void solve ()
{
	tmax = 0;
	int i,j,k,head=-1;
	for ( i = 0; i < n; i++ )
	{
		j = 0;
		head=0;
		stack[head].x = i;
		stack[head].y = 0;
		head++;
		while ( head != -1 && j != m+1 )
		{
			k = h[stack[head].x][stack[head].y];
			if ( h[i][j] > k )
			{
				head++;
				stack[head].x = i;
				stack[head].y = j;
				j++;
			}
			else if ( h[i][j] == k )
				j++;
			else
			{
				if ( k * (j-stack[head].y) > tmax )
					tmax = k*(j-stack[head].y);
				head--;
			}
		}
	}
	cout<<tmax<<endl;
}
int main ()
{
	while ( scanf("%d%d",&n,&m) != EOF )
	{
		input();
		solve();
	}
	return 0;
}