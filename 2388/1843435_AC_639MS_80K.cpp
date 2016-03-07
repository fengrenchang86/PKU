#include <iostream.h>
void main ()
{
	int n;
	cin>>n;
	int *a = new int[n];
	int i;
	for ( i = 0; i < n; i++ )
		cin>>a[i];
	int j;
	int k;
	for ( i = 0; i < n-1; i++ )
	{
		for ( j= i+1; j < n; j++ )
		{
			if ( a[i]<a[j] )
			{
				k = a[i];
				a[i] = a[j];
				a[j] = k;
			}
		}
	}
	cout<<a[n/2]<<endl;
}