#include <iostream>
using namespace std;
int a[300];
int b[300];
int main ()
{
	int n,i,j;
	while ( scanf("%d",&n)&&n!=0 )
	{
		for ( i = 1; i <= n; i++ )
			scanf("%d",&a[i]);
		for ( i = 1; i < n; i*=2 )
		{
			for ( j = 1; j <= i; j++ )
			{
				b[j*2-1] = (a[j]+a[i+j])/2;
				b[j*2] = (a[j]-a[i+j])/2;
			}
			for ( j = 1; j <= 2*i; j++ )
				a[j] = b[j];
		}
		for ( j = 1; j < n; j++ )
			cout<<a[j]<<" ";
		cout<<a[n]<<endl;
	}
	return 0;
}