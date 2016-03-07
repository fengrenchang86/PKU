#include <iostream>
#include <stdlib.h>
using namespace std;
_int64 a[80001];
_int64 stack[80001];
_int64 p[80001];
_int64 sum;
void test ( int n )
{
	int i,j;
	_int64 count = 0;
	for ( i = 1; i <= n-1; i++ )
	{
		j = i+1;
		while ( a[j] < a[i] && j <= n )
		{
			j++;
			count++;
		}
	}
	printf("%I64d\n",count);
}
void oper ( int n )
{
	int i,j;
	for ( i = n; i > 1; i-- )
	{
		j = i-1;
		while ( a[j] <= a[i] && j >= 1 )
			j--;
		if ( a[j] > a[i] )
			p[j] += (p[i]+1);
	}
	for ( i = 1; i <= n; i++ )
		sum += p[i];
	printf("%I64d\n",sum);
}
int main ()
{
	
	int i,j,n;
	int pre = 0;
	cin>>n;
	{
		stack[0] = 0;
		j = 0;
		for ( i = 1; i <= n; i++ )
		{
			p[i] = 0;
	//		scanf("%d",&a[i]);
		}
	//	for ( i = 1; i <= n; i++ )
		{
	//		a[i] = rand()%20;
	//		printf("%d\n",a[i]);
		}
//		printf("==================\n");
		sum = 0;
//		test(n);
		oper(n);
	//	printf("%I64d\n",sum);
//		printf("===================\n");
	}
	return 0;
}