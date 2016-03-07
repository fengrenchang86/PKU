#include <iostream>
using namespace std;
int plus ( int a[], int b[], int sizea, int sizeb, int c[] )
{			//数组a[sizea]+数组b[sizeb],结果存入数组c[]
	int i ;
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
	return i+1;
}
int cheng ( int a[], int &sizea )
{
	int i;
	a[sizea] = 0;
	for ( i = 0; i < sizea; i++ )
		a[i] *= 2;
	for ( i = 0; i < sizea; i++ )
	{
		a[i+1] += a[i]/10000;
		a[i] %= 10000;
	}
	if ( a[sizea] > 0 )
		sizea++;
	return 0;
}
int main ()
{
	int i;
	int *a = new int[100];
	int *b = new int[100];
	int *c = new int[100];
	int *temp;
	int sizea,sizeb,sizec;
	int n;
	while ( cin>>n )
	{
		if ( n == 0 )
			cout<<1<<endl;
		else if ( n == 1 )
			cout<<1<<endl;
		else
		{
			a[0] = 1;
			b[0] = 1;
			sizea = 1;
			sizeb = 1;
			n-=1;
			for ( i = 0; i < n; i++ )
			{
				cheng ( a, sizea );
				sizec = plus(a,b,sizea,sizeb,c);
				temp = a;
				a = b;
				b = c;
				c = temp;
				sizea = sizeb;
				sizeb = sizec;
			}
		}
		cout<<b[sizeb-1];
		for ( i = sizeb-2; i >= 0; i-- )
			printf("%04d",b[i]);
		printf("\n");
	}
	return 0;
}