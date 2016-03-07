#include <iostream>
using namespace std;
int v[40];
const int max = 1000001;
int a[max+1][40];
int b[max+1];
int main ()
{
	int i,j,k;
	v[0] = 1;
	for ( i = 1; i <= 32; i++ )
		v[i] = v[i-1]*2;
	for ( i = 0; i <= max; i++ )
		a[i][0] = 1;
	for ( i = 1; i <= max; i++ )
	{
		b[i] = 0;
		for ( j = 1; v[j] <= i && j < 32; j++ )
		{
			a[i][j] = 0;
			for ( k = j; k >= 0; k-- )
				a[i][j] += a[i-v[k]][k];
			b[i] += a[i][j];
		}
	}
	scanf("%d",&i);
	printf("%d\n",b[i]);
	return 0;
}
