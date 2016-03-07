#include <iostream.h>
int a[1000000];
int max[1000000] ;
int min[1000000] ;
int c = 0;
void f ( int b, int e )
{
	int m = -999999;
	int n = 999999;
	int i;
	for ( i = b; i < e; i++ )
	{
		if ( a[i] > m )
		{
			m = a[i];
		}
		if ( a[i] < n )
		{
			n = a[i];
		}
	}
	max[c] = m;
	min[c++] = n;
}

void main ()
{
	int n;
	int k;
	int i;
	cin>>n>>k;
	for ( i = 0; i < n; i++ )
		cin>>a[i];
	for ( i = 0; i < n-k+1; i++ )
		f ( i, i+k );
	for ( i = 0; i < n-k+1; i++ )
		cout<<min[i]<<" ";
	cout<<endl;
	for ( i = 0; i < n-k+1; i++ )
		cout<<max[i]<<" ";
	cout<<endl;
}