#include <iostream>
using namespace std;
int a[1001][500];
int b[500];
int plus ( int a[], int b[], int sizea, int sizeb, int d[] )
{			//数组a[sizea]+数组b[sizeb],结果存入数组c[]
	int i ;
	int c[1001];
	int max = sizea<sizeb ? sizea:sizeb;
	c[0] = 0;
	for ( i = 0; i < max; i++ )
	{
		c[i+1] = (a[i]+b[i])/10000;
		c[i] += (a[i]+b[i])%10000;
	}
	if ( sizea < sizeb )
	{
		c[i] += b[i];
		for ( i++; i < sizeb; i++ )
			c[i] = b[i];
	}
	else if ( sizea > sizeb )
	{
		c[i] += a[i];
		for ( i++; i < sizea; i++ )
			c[i] = a[i];
	}
	while ( c[i] <= 0 )
		i--;
	int j;
	for ( j = 0; j <= i; j++ )
		d[j] = c[j];
	return i+1;
}

int main ()
{
	int v[2];
	v[0] = 1;
	int sizea[1001],sizeb;
	int begin[1001];
//	int end[1001];
	begin[3] = 0;
//	end[2] = 1;
	int n,i,j;
		a[2][0] = 1;
		a[3][0] = 1;
		b[0] = 1;
		sizea[2] = sizea[3] = sizeb = 1;
		for ( i = 4; i <= 1000; i++ )
		{
			sizea[i] = plus( a[i-1], b, sizea[i-1],sizeb,a[i]);
			sizeb = sizea[i];
			for ( j = 0; j < sizea[i]; j++ )
				b[j] = a[i][j];
			if ( begin[i-1] == 0 )
				sizea[i] = plus(a[i],v,sizea[i],1,a[i]);
			if ( begin[i-1] == 0 )
				begin[i] = 1;
			else
				begin[i] = 0;
		}
	while ( cin >> j )
	{
		if ( j == 1 )
		{
			cout<<0<<endl;
			continue;
		}
		printf("%d",a[j][sizea[j]-1]);
		i = sizea[j]-2;
		while ( i >= 0 )
		{
			printf("%04d",a[j][i]);
			i--;
		}
		printf("\n");
	}

	return 0;
}