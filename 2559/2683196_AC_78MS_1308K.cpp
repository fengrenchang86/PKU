#include <iostream>
using namespace std;
struct ac
{
	int data;
	int left,right;
}a[100100];
int n;
int f ( int key, int i )
{
	while ( i > 0 )
	{
		if ( a[i].data < key )
			return i;
		else if ( a[i-1].data < key )
			return i-1;
		else
			i--;
		i = a[i].left;
	}
	return 0;
}
int g ( int key, int i )
{
	while ( i <= n )
	{
		if ( a[i].data < key )
			return i;
		else if ( a[i+1].data < key )
			return i+1;
		else
			i++;
		i = a[i].right;
	}
	return n+1;
}
int main ()
{
	int i;
	__int64 max;
	while ( scanf("%d",&n) && n!=0 )
	{
		for ( i = 1; i <= n; i++ )
			scanf("%d",&a[i].data);
		a[0].data = 0;
		a[0].left = 0;
		a[n+1].data = 0;
		a[n+1].right = n+1;
		for ( i = 1; i <= n; i++ )
			a[i].left = f(a[i].data,i-1);
		for ( i = n; i >= 1; i-- )
			a[i].right = g(a[i].data,i+1);
		max = 0;
		for ( i = 1; i <= n; i++ )
		{
			if ( __int64((a[i].right-a[i].left-1)*__int64(a[i].data)) > max )
				max = __int64((a[i].right-a[i].left-1)*__int64(a[i].data));
		}
		printf("%I64d\n",max);
	}
	return 0;
}