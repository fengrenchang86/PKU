#include <iostream>
using namespace std;
int f ( int n )
{
	int sum = n;
	if ( n > 9 )
		sum+=n-9;
	if ( n > 99 )
		sum += n-99;
	if ( n > 999 )
		sum += n-999;
	if ( n > 9999 )
		sum += n- 9999;
	if ( n > 99999 )
		sum += n-99999;
	return sum;
}
int g ( int n, int p )
{
	int k;
	if ( n < 10 )
		k = 1;
	else if ( n < 100 )
		k = 2;
	else if ( n < 1000 )
		k = 3;
	else if ( n < 10000 )
		k = 4;
	else if ( n < 100000 )
		k = 5;
	else 
		k = 6;
	for ( int i = 0; i < k-p; i++ )
		n/=10;
	return n%10;
}
int main ()
{
	int n,sum,i;
	int j,k;
	scanf("%d",&k);
	for ( j = 0; j < k; j++ )
	{
		scanf("%d",&n);
		sum = n;
		i = 1;
		while ( sum > 0 )
		{
			sum -= f(i);
			i++;
		}
		i--;
		if ( sum == 0 )
		{
			printf("%d\n",i%10);
			continue;
		}
		sum+=f(i);
		if ( sum < 9 )
		{
			printf("%d\n",sum);
			continue;
		}
		i = 1;
		while ( sum > f(i) )
			i++;
		if ( sum == f(i) )
		{
			printf("%d\n",i%10);
			continue;
		}
		i--;
		sum -= f(i);
		i++;
		printf("%d\n",g(i,sum));
	}
	return 1;
}