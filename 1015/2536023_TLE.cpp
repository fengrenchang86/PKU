#include <iostream>
using namespace std;
int pow[30];
int v[30];
int a[250],b[250];
int wf ( int n )
{
	int sum = 0;
	for ( int i = 20; i >= 0; i-- )
	{
		v[i] = n/pow[i];
		sum += v[i]*(a[i]+b[i]);
		n %= pow[i];
	}
	return sum;
}
void pf ( int n )
{
	int sa=0,sb=0;
	for ( int i = 20; i >= 0; i-- )
	{
		v[i] = n/pow[i];
		sa += v[i]*a[i];
		sb += v[i]*b[i];
		n %= pow[i];
	}
	printf("Best jury has value %d for prosecution and value %d for defence:\n",sa,sb);
	for ( i = 0; i <= 20; i++ )
	{
		if ( v[i] == 1 )
			printf(" %d",i);
	}
	printf("\n");
}
int main ()
{
	int i,j,k,n,m,M,tcase = 1;
	bool c[2][21][801];
	int d[2][21][801];
	pow[0] = 1;
	for ( i = 1; i <= 23; i++ )
		pow[i] = pow[i-1]*2;
	while ( scanf("%d%d",&n,&m) && !(m==0&&n==0) )
	{
		M = 0;
		for ( i = 1; i <= n; i++ )
		{
			scanf("%d%d",&a[i],&b[i]);
			if ( a[i]-b[i] < M )
				M = a[i]-b[i];
		}
		if ( M > 0 )
			M = 0;
		else
			M *= -1;
		for ( k = 0; k <= 800; k++ )
		{
			c[0][0][k] = false;
			d[0][0][k] = 0;
		}
		c[1][0][0] = true;
		c[0][0][0] = true;
		d[0][0][0] = 0;
		d[1][0][0] = 0;
		for ( i = 1; i <= n; i++ )
		{
			for ( j = 1; j <= i && j <= m; j++ )
			{
				for ( k = 0; k <= 800; k++ )
				{
					c[i%2][j][k] = false;
					d[i%2][j][k] = d[(i+1)%2][j][k];
					if ( c[(i+1)%2][j][k] == true )
						c[i%2][j][k] = true;
					if ( k-(a[i]-b[i]+M) >= 0 && c[(i+1)%2][j-1][k-(a[i]-b[i]+M)] == true )
					{
						c[i%2][j][k] = true;
						if ( c[(i+1)%2][j][k] == false )
							d[i%2][j][k] = d[(i+1)%2][j-1][k-(a[i]-b[i]+M)]+pow[i];
						else if ( wf(d[i%2][j][k]) < wf(d[(i+1)%2][j-1][k-(a[i]-b[i]+M)]+pow[i]) )
							d[i%2][j][k] = d[(i+1)%2][j-1][k-(a[i]-b[i]+M)]+pow[i];
					}
				}
			}
		}
		j = -1;
		for ( i = n*M; i >= 0; i-- )
		{
			if ( c[n%2][m][i] == true )
			{
				j = i;
				break;
			}
		}
		k = -1;
		for ( i = n*M+1; i <= 800; i++ )
		{
			if( c[n%2][m][i] == true )
			{
				k = i;
				break;
			}
		}
		printf("Jury #%d\n",tcase);
		tcase++;
		if ( j == -1 )
			pf(d[n%2][m][k]);
		else if ( k == -1 )
			pf(d[n%2][m][j]);
		else
		{
			if ( abs(j-n*M) > abs(k-n*M) )
				pf(d[n%2][m][k]);
			else if ( abs(j-n*M) < abs(k-n*M) )
				pf(d[n%2][m][j]);
			else
			{
				if ( wf(d[n%2][m][j]) > wf(d[n%2][m][k]) )
					pf(d[n%2][m][j]);
				else
					pf(d[n%2][m][k]);
			}
		}
		printf("\n");
	}
	return 0;
}