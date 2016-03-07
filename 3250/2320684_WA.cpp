#include <iostream>
using namespace std;
int a[80001];
int stack[80001];
int p[80001];
int test ( int n )
{
	int i,j,count;
	count = 0;
	for ( i = 1; i <= n-1; i++ )
	{
		j = i+1;
		while ( a[j] < a[i] && j <= n )
		{
			j++;
			count++;
		}
	}
	cout<<count<<endl;
	return count;
}
int main ()
{
	int i,j,n;
	_int64 sum = 0;
	int pre = 0;
	scanf("%d",&n);
	stack[0] = 0;
	j = 1;
	for ( i = 1; i <= n; i++ )
	{
		p[i] = 1;
		scanf("%d",&a[i]);
		if ( a[i] > pre )
		{
			stack[j] = i;
			sum += (i-stack[j-1])*(i-stack[j-1]-1)/2;
			j++;
			p[stack[j-1]]++;
		}
		pre = a[i];
	}
	sum += (n+1-stack[j-1])*(n-stack[j-1])/2;
	pre = j;
	for ( i = pre-1; i > 0; i-- )
	{
		while ( a[stack[i-1]] > a[stack[i]] && i > 0)
		{
			sum += p[stack[i]];
			i--;
		}
	}
	printf("%I64d\n",sum);
//	test(n);
	return 0;
}