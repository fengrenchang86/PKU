#include <iostream>
using namespace std;
int plus ( int a[], int b[], int sizea, int sizeb  )//a=a+b;
{
	int i;
	if ( sizea >= sizeb )
	{
		a[sizea] = 0;
		for ( i = 0; i < sizeb; i++ )
			a[i] += b[i];
		for ( i = 0; i < sizea; i++ )
		{
			a[i+1] += a[i]/10000;
			a[i] %= 10000;
		}
		if ( a[sizea] != 0 )
			return sizea+1;
		else
			return sizea;
	}
	a[sizeb] = 0;
	for ( i = 0; i < sizea; i++ )
		a[i] += b[i];
	while ( i < sizeb )
	{
		a[i] = b[i];
		i++;
	}
	for ( i = 0; i < sizeb; i++ )
	{
		a[i+1] += a[i]/10000;
		a[i] %= 10000;
	}
	if ( a[sizeb] != 0 )
		return sizeb+1;
	else
		return sizeb;
}
int cheng ( int a[], int b[], int c[], int sizea, int sizeb )
{
	int i,j;
	for ( i = 0; i <= sizea+sizeb+1; i++ )
		c[i] = 0;
	for ( i = 0; i < sizea; i++ )
	{
		for ( j = 0; j < sizeb; j++ )
			c[i+j] += a[i]*b[j];
	}
	for ( i = 0; i < sizea+sizeb-1; i++ )
	{
		c[i+1] += c[i]/ 10000;
		c[i] %= 10000;
	}
	if ( c[i] != 0 )
		return i+1;
	else
		return i;
}
int cheng2 ( int a[], int size )
{
	int i;
	a[size] = 0;
	for ( i =0 ;i < size; i++ )
		a[i] *= 2;
	for ( i = 0; i < size; i++ )
	{
		a[i+1] += a[i] / 10000;
		a[i] %= 10000;
	}
	if ( a[size] != 0 )
		return size+1;
	else
		return size;
}
void output ( int t[], int size )
{
	int i = size-1;
	printf("%d",t[i]);
	i--;
	while ( i >= 0 )
	{
		printf("%04d",t[i]);
		i--;
	}
	printf("\n");
}
int main ()
{
	int a[120][100]={0};
	int size[120];
	int t[120];
	int i,j,k;
	size[0] = size[1] = size[2] = 1;
	a[0][0] = a[1][0] = 1;
	a[2][0] = 2;
	for ( i = 3; i <= 100; i++ )
	{
		size[i] = 1;
		a[i][0] = 0;
		for ( j = 0; j < i/2; j++ )
		{
			k = cheng(a[j],a[i-1-j],t,size[j],size[i-1-j]);
			size[i] = plus(a[i],t,size[i],k);
		}
		size[i] = cheng2(a[i],size[i]);
		if ( i % 2 == 1 )
		{
			k = cheng(a[i/2],a[i/2],t,size[i/2],size[i/2]);
			size[i] = plus(a[i],t,size[i],k);
		}
//		printf("%4d:",i);
//		output(a[i],size[i]);
	}
	while ( scanf("%d",&i ) && i !=-1 )
		output(a[i],size[i]);
	return 0;
}