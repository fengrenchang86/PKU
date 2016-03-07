#include <iostream>
using namespace std;
int a[120][120];
int main ()
{
	bool go(int);
	bool flag;
	int n,i,j,m;
	while ( cin>>n )
	{
		flag = false;
		m = n*n;
		for ( i = 1; i <= m; i++ )
		{
			for ( j = 1; j <= m; j++ )
				scanf("%d",&a[i][j]);
		}
		flag = go(n);
		if ( flag == false )
			printf("INCORRECT\n");
		else
			printf("CORRECT\n");
	}
	return 0;
}
bool go ( int n )
{
	int i,j,k,l;
	int m=n*n;
	int list[120];
	for ( i = 1; i <= m; i++ )
	{
		memset(list,0,sizeof(list));
		for ( j = 1; j <= m; j++ )
		{
			if ( a[i][j] == 0 )
				continue;
			if ( a[i][j] > m )
				return false;
			if ( list[a[i][j]] != 0 )
				return false;
			list[a[i][j]]++;
		}
		memset(list,0,sizeof(list));
		for ( j = 1; j <= m; j++ )
		{
			if ( a[j][i] == 0 )
				continue;
			if ( list[a[j][i]] != 0 )
				return false;
			list[a[j][i]]++;
		}
	}
	for ( i = 1; i < m; i += n )
	{
		for ( j = 1; j < m; j+=n )
		{
			memset(list,0,sizeof(list));
			for ( k = 1; k <= n; k++ )
			{
				for ( l = 1; l <= n; l++ )
				{
					if ( a[i+k][j+l] == 0 )
						continue;
					if ( list[a[i+k][j+l]] != 0 )
						return false;
					list[a[i+k][j+l]]++;
				}
			}
		}
	}
	return true;
}