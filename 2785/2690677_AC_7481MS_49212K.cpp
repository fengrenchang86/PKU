#include <iostream>
#include <algorithm> 
using namespace std;
int a[4][4100];
int b[2][17000000];
int main ()
{
	int i,j,k,n;
	int v[4];
	while ( scanf("%d",&n) != EOF )
	{
		for ( i = 0; i < n; i++ )
			scanf("%d%d%d%d",&a[0][i],&a[1][i],&a[2][i],&a[3][i]);
		k = 0;
		for ( i = 0; i < n; i++ )
		{
			for ( j = 0; j < n; j++ )
			{
				b[0][k] = a[0][i]+a[1][j];
				b[1][k++] = a[2][i] + a[3][j];
			}
		}
		j = n*n;
		int c = 0;
		int low = 0, high = n*n-1;
		sort(b[0],b[0]+j);
		sort(b[1],b[1]+j);
		while ( low < j && high >= 0 )
		{
			if ( b[0][low] + b[1][high] < 0 )
				low++;
			if ( b[0][low] + b[1][high] > 0 )
				high--;
			if ( b[0][low] + b[1][high] == 0 )
			{
				i = high-1;
				while ( i >=0 && b[1][high] == b[1][i] )
					i--;
				k = low+1;
				while ( k < j && b[0][low] == b[0][k] )
					k++;
				c += (i-high)*(low-k);
				high = i;
				low = k;
			}
		}
		cout<<c<<endl;
	}
	return 0;
}
