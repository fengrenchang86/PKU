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
	int i,j,pre,t=0;
	j = 1;
	pre = 0;
	for ( i = 1; i <= n; i++ )
	{
		if ( a[i] >= pre )
		{
			stack[j] = i;
			sum += t;
			t = 0;
			j++;
		}
		else
		{
			p[stack[j-1]] += p[i];
			t *= 2;
			t += p[i];
		}
		pre = a[i];
	}
	pre = j-1;
	j = stack[j-1]+1;
	while ( j <= n && a[j] == a[j-1] )
		j++;
	t = 0;
	while ( j <= n )
	{
		t *= 2;
		t += p[j];
		j++;
	}
	sum += t;
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

/*	pre = j;
	j = stack[j-1]+1;
	while ( j <= n && a[j] == a[j-1] )
		j++;
	sum += (n+2-j)*(n+1-j)/2;
	for ( i = 0; i < pre-1; i++ )
	{
		j = i+1;
		while ( j < pre && a[stack[i]] > a[stack[j]] )
		{
			sum += p[stack[j]];
			j++;
		}
	}
//	printf("%I64d\n",sum);*/
	sum = 0;
//	test(n);
	oper(n);
	printf("%I64d\n",sum);
	return 0;
}