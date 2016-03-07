#include <iostream>
using namespace std;
int pow[30];
int v[30];
int a[250],b[250];
struct ac
{
	int sum;
	short t[21];
	bool ok;
}dp[2][21][801];
void copy ( ac &a, ac &b, int j )
{
	int i;
	for ( i = 1; i <= j; i++ )
		a.t[i] = b.t[i];
}
void wp ( ac &q, int m )
{
	int sa = 0,sb = 0;
	int i;
	for ( i = 1; i <= m; i++ )
	{
		sa += a[q.t[i]];
		sb += b[q.t[i]];
	}
	printf("Best jury has value %d for prosecution and value %d for defence:\n",sa,sb);
	for ( i = 1; i <= m; i++ )
		printf(" %d",q.t[i]);
	printf("\n");
}
int main ()
{
	int i,j,k,n,m,M,tcase = 1;
	pow[0] = 1;
	for ( i = 1; i <= 23; i++ )
		pow[i] = pow[i-1]*2;
	while ( scanf("%d%d",&n,&m) && !(m==0&&n==0) )
	{
		M = 0;
		for ( i = 1; i <= n; i++ )
		{
			scanf("%d%d",&a[i],&b[i]);
	//		a[i] = rand()%20+1;
	//		b[i] = rand()%20+1;
	//		printf("%d %d\n",a[i],b[i]);
			if ( a[i]-b[i] < M )
				M = a[i]-b[i];
		}
		for ( j = 0; j <= 20; j++ )
			for ( k = 0; k <=800; k++ )
				dp[0][j][k].ok = dp[1][j][k].ok = false;
		if ( M > 0 )
			M = 0;
		else
			M *= -1;
		dp[0][0][0].sum = 0;
		dp[0][0][0].ok = dp[1][0][0].ok = true;
		for ( i = 1; i <= n; i++ )
		{
			dp[i%2][0][0].sum = 0;
			for ( j = 1; j <= m && j <= i; j++ )
			{
				for ( k = 0; k <= 800; k++ )
				{
					dp[i%2][j][k].sum = 0;
					dp[i%2][j][k].ok = false;
					if ( dp[(i+1)%2][j][k].ok == true  )
					{
						dp[i%2][j][k].ok = true;
						dp[i%2][j][k].sum = dp[(i+1)%2][j][k].sum;
						copy(dp[i%2][j][k],dp[(i+1)%2][j][k],j);
					}
					if ( k-(a[i]-b[i]+M) >= 0 && dp[(i+1)%2][j-1][k-(a[i]-b[i]+M)].ok == true )
					{
						if (dp[i%2][j][k].sum < dp[(i+1)%2][j-1][k-(a[i]-b[i]+M)].sum+a[i]+b[i] ||
							dp[i%2][j][k].ok == false)
						{
							dp[i%2][j][k].sum = dp[(i+1)%2][j-1][k-(a[i]-b[i]+M)].sum+a[i]+b[i];
							copy(dp[i%2][j][k],dp[(i+1)%2][j-1][k-(a[i]-b[i]+M)],j-1);
							dp[i%2][j][k].t[j] = i;
						}
						dp[i%2][j][k].ok = true;
					}
				}
			}
		}
		k = j = -1;
		for ( i = M*m; i >= 0; i-- )
		{
			if ( dp[n%2][m][i].sum != 0 )
			{
				j = i;
				break;
			}
		}
		for ( i = M*m+1; i <= 800; i++ )
		{
			if ( dp[n%2][m][i].sum != 0 )
			{
				k = i;
				break;
			}
		}
		printf("Jury #%d\n",tcase);
		if ( k == -1 )
			wp(dp[n%2][m][j],m);
		else if ( j == -1 )
			wp(dp[n%2][m][k],m);
		else
		{
			if ( dp[n%2][m][j].sum > dp[n%2][m][k].sum )
				wp(dp[n%2][m][j],m);
			else
				wp(dp[n%2][m][k],m);
		}
		tcase++;
		printf("\n");
	}
	return 0;
}