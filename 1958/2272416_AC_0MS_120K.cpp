#include <iostream>
using namespace std;
int main ()
{
	int a[30];
	int b[30];
	a[0] = b[0] = 1;
	a[1] = 1;
	for ( int i = 2; i <= 12; i++ )
		a[i] = 2*a[i-1]+1;
	b[1] = 1;
	cout<<1<<endl;
	int min;
	int j;
	for ( i = 2; i <= 12; i++ )
	{
		min = 900000;
		for ( j = 1; j < i; j++ )
		{
			if ( 2*b[j]+a[i-j] < min )
				min = 2*b[j]+a[i-j];
		}
		b[i] = min;
		cout<<b[i]<<endl;
	}
	return 0;
}