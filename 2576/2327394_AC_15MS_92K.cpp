#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp( const void*a, const void*b)
{
	return *(int*)a-*(int*)b;
}
int comp = 1000000;
int v;
void oper ( int n, int t[] )
{
	int b[101],c[101];
	int s1,s2;
	int sum1=0,sum2=0;
	int i,j = 0;
	for ( i = 0; i < n/2; i++ )
	{
		b[j++] = t[i];
		sum1 += t[i];
	}
	s1 = j;
	j = 0;
	while ( i < n )
	{
		c[j++] = t[i];
		sum2 += t[i];
		i++;
	}
	s2 = j;
	comp = abs(sum1-sum2);
	v = sum1;
	int x,y;
	for ( i = 0; i < 800; i++ )
	{
		x = rand()%s1;
		y = rand()%s2;
		sum1 = sum1-b[x]+c[y];
		sum2 = sum2-c[y]+b[x];
		j = b[x];
		b[x] = c[y];
		c[y] = j;
		if ( abs(sum1-sum2) < comp)
		{
			comp = abs(sum1-sum2);
			v = sum1;
		}
	}
}
int main ()
{
	int i,j,n,sum=0;
	int a[101];
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}
	if ( n == 1 )
	{
		printf("0 %d\n",a[1]);
		return 0;
	}
	oper(n,a);
	if ( v < sum-v )
	{
		i = v;
		j = sum-v;
	}
	else
	{
		i = sum-v;
		j = v;
	}
	printf("%d %d\n",i,j);
	return 0;
}
