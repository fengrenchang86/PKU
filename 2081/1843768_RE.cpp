#include <iostream.h>
void main ()
{
	int a[500000];
	int i;
	int k;
	int t = 0;
	a[0] = 1;
	while ( cin>>k && k!=-1)
	{
		for ( i = 1; i <= k; i++ )
		{
			if ( t-i>0 && a[i]!=1)
				t = t-i;
			else
				t = t+i;
			a[t] = 1;
		}
		cout<<t<<endl;
	}
}