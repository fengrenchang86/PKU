#include <iostream>
#include <algorithm>
using namespace std;
__int64 a[1000100];
void test()
{
	int x,y,z;
	x = 1;
	y = 2;
	int i=1;
	while ( z <= 2000000000 )
	{
		z = x+y;
		printf("%d + %d = %d\n",x,y,z);
		x = y;
		y = z;
		i++;
	}
	cout<<i<<endl;
}
int main ()
{
	int n,i;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
		scanf("%I64d",&a[i]);
	if ( n <= 3 )
		printf("The set is rejected.\n");
	else
	{
		sort(a,a+n);
		if ( a[0]+a[1] > a[n-1] )
			printf("The set is rejected.\n");
		else
		{
			for ( i = 2; i < n; i++ )
			{
				if ( a[i-2]+a[i-1]>a[i] )
					break;
			}
			if ( i == n )
				printf("The set is rejected.\n");
			else
				printf("The set is accepted.\n");
		}
	}
	return 0;
}