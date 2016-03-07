
#include <iostream>
using namespace std;
const int n = 1200000;
int a[n];
int b[n];
void make ( )
{
	int i,j,k=5;
	a[0] = a[1] = 0;
	b[0] = b[1] = 0;
	a[2] = b[2] = 1;
	a[3] = a[4] = 2;
	b[3] = b[4] = 1;
	for ( i = 5; i <= 1000000; i+=2 )
	{
		for ( j = 3; j*j <= i; j+= 2 )
		{
			if ( i % j == 0 )
				break;
		}
		if ( i % j != 0 )
		{
			a[k] = a[k-1]+1;
			if ( (i-1)%4==0 )
				b[k] = b[k-1]+1;
			else
				b[k] = b[k-1];
			k++;
		}
		else
		{
			a[k] = a[k-1];
			b[k] = b[k-1];
			k++;
		}
		a[k] = a[k-1];
		b[k] = b[k-1];
		k++;

	}
}
int main ()
{
	int l,u;
	make();
	while ( scanf("%d%d",&l,&u) )
	{
		if ( l == -1 && u == -1 )
			break;
		printf("%d %d ",l,u);
		if ( l < 1 )
			l = 1;
		if ( u < 1 )
			u = 1;
		printf("%d %d\n",a[u]-a[l-1],b[u]-b[l-1]);
	}
	return 0;
}
