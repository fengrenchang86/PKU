#include <iostream>
using namespace std;
const int N = 2100;
char a[N][N];
int h[N][N];
struct ac
{
	int x,y;
}stack[N];
int tmax,n,m;
void input ()
{
	int i,j,t;
	a[0][0] = '0';
	for ( i = 1; i <= n; i++ )
	{
		a[i][0] = '0';
		for ( j = 1; j <= m; j++ )
		{
/*			t = rand()%3;
			if ( t == 0 )
				a[i][j] = '0';
			else
				a[i][j] = '1';
			cout<<a[i][j]<<" ";
*/			scanf(" %c",&a[i][j]);
		}
	//	cout<<endl;
	}
	for ( i = 1; i <= m; i++ )
	{
		h[1][i] = a[1][i]-'0';
	}
	for ( i = 2; i <= n; i++ )
	{
		for ( j = 1; j <= m; j++ )
		{
			if ( a[i][j] == '0' )
				h[i][j] = 0;
			else
				h[i][j] = h[i-1][j] + 1;
		}
	}
	for ( i = 1; i <= n; i++ )
	{
		h[i][0] = -1;
		h[i][m+1] = -1;
	}
}
void solve ()
{
	tmax = 0;
	int i,j,k,head=-1;
	for ( i = 1; i <= n; i++ )
	{
		head=-1;
		for ( j = 1; j <= m+1; j++ )
		{
			if ( head == -1 )
			{
				head++;
				stack[head].x = i;
				stack[head].y = j;
				continue;
			}
			k = h[stack[head].x][stack[head].y];
			if ( h[i][j] > k )
			{
				head++;
				stack[head].x = i;
				stack[head].y = j;
				continue;
			}
			else if ( h[i][j] == k )
				continue;
			while ( h[i][j] <= k )
			{
				if ( k*(j-stack[head].y) > tmax )
					tmax = k*(j-stack[head].y);
				head--;
				if ( head == -1 )
					break;
				k = h[stack[head].x][stack[head].y];
			}
			if ( h[i][j] != k )
			{
				head++;
				h[i][stack[head].y] = h[i][j];
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