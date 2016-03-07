#include <iostream>
using namespace std;
int a[1010][110];
int main ()
{				//a[i][j] = sum{a[i-k][k]}( k<=i && 1<=k<=j )
	int i,j,k;
	for ( i = 1; i <= 1000; i++ )
		a[i][i] = a[i][1] = 1;
	for ( i = 2; i <= 1000; i++ )
	{
		for ( j = 1; j < i&& j <= 100; j++ )
		{
			a[i][j] = 0;
			for ( k = 1; k <= j && k <= i; k++ )
			{
				a[i][j] += a[i-k][k];
			}
		}
	}
	int x,y;
	cin>>x>>y;
	{
		k = 0;
		for ( i = 1; i <= y; i++ )
			k += a[x][i];
		cout<<k<<endl;
	}
	return 0;
}