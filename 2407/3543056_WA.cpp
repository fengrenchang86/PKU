#include <iostream>
using namespace std;
int a[12000],b[12000];
int make ()
{
	int i,j,k=2;
	a[0] = 2;
	a[1] = 3;
	for ( i = 5; i < 62000; i+=2 )
	{
		for ( j = 3; j*j <= i; j+=2 )
		{
			if ( i % j == 0 )
				break;
		}
		if ( i % j != 0 )
			a[k++] = i;
	}
	return k;
}
__int64 ac ( int x, int y )
{
	if ( y == 0 )
		return 1;
	int i;
	__int64 j=1;
	for ( i = 0; i < y; i++ )
		j *= x;
	return j;
}
int main ()
{
	int n,i,j,k=make();
	__int64 ans;
	while ( cin>>n && n )
	{
		memset(b,0,sizeof(b));
		ans = 1;
		for ( i = 0; i < k; i++ )
		{
			j = n;
			while ( j % a[i] == 0 )
			{
				b[i]++;
				j /= a[i];
			}
			if ( b[i] != 0 )
			{
				ans *= ac(a[i],b[i]-1);
				ans *= __int64(a[i]-1);
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}