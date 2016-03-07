#include <iostream>
using namespace std;
int plus ( int a[], int b[], int sizea, int sizeb )
{			//数组a[sizea]+数组b[sizeb],结果存入数组c[]
	int i ;
	int c[500];
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
		a[j] = c[j];
	return i+1;
}

int main ()
{
	int v[2];
	v[0] = 1;
	int a[500];
	int b[500];
	int sizea,sizeb;
	int begin[1001];
//	int end[1001];
	begin[2] = 1;
//	end[2] = 1;
	int n,i,j;
	while ( cin >> n )
	{
		a[0] = 1;
		b[0] = 0;
		sizea = sizeb = 1;
		for ( i = 2; i < n; i++ )
		{
			sizea = plus( a, b, sizea,sizeb);
			sizeb = sizea;
			for ( j = 0; j < sizea; j++ )
				b[j] = a[j];
			if ( begin[i-1] == 0 )
				sizea = plus(a,v,sizea,1);
			if ( begin[i-1] == 0 )
				begin[i] = 1;
			else
				begin[i] = 0;
		}
		printf("%d",a[sizea-1]);
		i = sizea-2;
		while ( i >= 0 )
		{
			printf("%04d",a[i]);
			i--;
		}
		printf("\n");
	}
	return 0;
}