#include <iostream>
using namespace std;
struct ac
{
	int x,y;
}a[20];
int dp[50000];
int amount,year,n;
void input () 
{
	int i;
	scanf("%d%d",&amount,&year);
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].x /= 1000;
	}
}
void solve ( )
{
	int i,j,k;
	memset(dp,0,sizeof(dp));
	for ( i = 1; i < 50000; i++ )
	{
		dp[i] = dp[i-1];
		for ( j = 0; j < n; j++ )
		{
			if ( i >= a[j].x && dp[i] < dp[i-a[j].x] + a[j].y )
				dp[i] = dp[i-a[j].x] + a[j].y;
		}
	}
	k = amount;
	for ( i = 0; i < year; i++ )
	{
		k += dp[k/1000];
	}
	printf("%d\n",k);
}
int main ()
{
	int tc;
	scanf("%d",&tc);
	while ( tc-- )
	{
		input();
		solve();
	}
	return 0;
}