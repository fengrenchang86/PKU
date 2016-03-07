#include <iostream>
using namespace std;
int f ( int k,int b[] )
{
	int i = k;
	int c = 0;
	while ( b[k] != -1 )
	{
		c++;
		k = b[k];
	}
	return c;
}
int main ()
{
	int pow[10] = {1,2,4,8,16,32,64,128,256,512};
	int a[300];
	int b[300];
	int c[300];
	int i,n;
	int p;
	while (scanf("%d",&n) && n!= 0 )
	{
		for ( i = 0; i < 300; i++ )
		{
			a[i] = 0;
			b[i] = -1;
			c[i] = 0;
		}
		for ( i = pow[n]-1; i >= 1; i-- )
			scanf("%d",&a[i]);
		p = 1;
		for ( i = pow[n]-1; i >= pow[n-1]; i--,p++ )
		{
			if ( a[i]%2 == 0 )
			{
				b[2*p-1] = a[i];
			}
			else
				b[2*p] = a[i];
		}
		for ( i = 1; i <= pow[n-1]-1; i++ )
		{
			if ( a[i] == a[2*i] )
				b[a[2*i+1]] = a[i];
			else
				b[a[2*i]] = a[i];
		}
		for ( i = pow[n]-1; i >= 1; i-- )
		{
			if ( a[i] == a[2*i] )
				c[a[i]] += c[a[2*i+1]]+1;
			else
				c[a[i]] += c[a[2*i]]+1;
		}
		int m;
		scanf("%d",&m);
		for ( i = 0; i < m; i++ )
		{
			scanf("%d",&p );
			printf("Player %d can be ranked as high as %d or as low as %d.\n",p,f(p,b)+1,pow[n]-c[p]);
		}
		printf("\n");
	}
	return 1;
}