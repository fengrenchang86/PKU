#include <iostream.h>
void main ()
{
	int c = 0;
	int count = 0;
	int i;
	int n;
	int k;
	cin>>n>>k;
	int h;
	char *a = new char[k];
	for ( i = 0; i < k; i++ )
		a[i] = -1;
	for ( i = 0; i < n; i++ )
	{
		cin>>h;
		if ( a[h] != count )
		{
			a[h] = count;
			c++;
		}
		if ( c == k )
		{
			count++;
			c = 0;
		}
	}
	count++;
	cout<<count<<endl;
}