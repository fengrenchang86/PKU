#include <iostream>
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
	if ( n == 1 )
		return;
	int i,j,pre,t=1;
	j = 1;
	int v = 0;
	pre = 0;
	for ( i = 1; i <= n; i++ )
	{
		if ( a[i] >= pre )
		{
			stack[j] = i;
			t = 1;
			j++;
		}
		else
		{
			p[stack[j-1]] += p[i];
			sum += t*p[i];
			t++;
		}
		pre = a[i];
	}
	pre = j-1;
	j = stack[j-1]+1;
	while ( j <= n && a[j] == a[j-1] )
		j++;
	t = 1;
	for ( i = 1; i <= pre; i++ )
		a[i] = a[stack[i]];
	for ( i = 1; i <= pre; i++ )
		p[i] = p[stack[i]];
	if ( pre == n )
		return;
	oper(pre);
}
int main ()
{
	int i,j,n;
	int pre = 0;
	scanf("%d",&n);
	stack[0] = 0;
	j = 0;
	for ( i = 1; i <= n; i++ )
	{
		p[i] = 1;
		scanf("%d",&a[i]);
	}
	sum = 0;
//	test(n);
	oper(n);
	printf("%I64d\n",sum);
	return 0;
}