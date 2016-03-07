#include <iostream.h>
void main ()
{
	int m;
	int n;
	int a[200];
	int end;
	int i;
	int j;
	while ( cin>>m>>n && m!=0 && n != 0 )
	{
		for ( i = 0; i < 200; i++ )
			a[i] = 0;
		a[0] = m;
		end = 0;
		for ( i = m-1; i >= m-n+1; i-- )
		{
			for ( j = 0; j <= end; j++ )
				a[j] *= i;
			for ( j = 0; j <= end; j++ )
			{
				a[j+1] += ( a[j]/10000 );
				a[j] %= 10000;
			}
			if ( a[end+1] > 0 )
				end++;
		}
		for ( i = n; i > 1; i-- )
		{
			for ( j = end; j > 0 ; j-- )
			{
				a[j-1] += ( a[j]%i*10000 );
				a[j] = a[j]/i;
			}
			a[0] = a[0]/i;
			while ( a[end] == 0 )
				end--;
		}
		cout<<m<<" things taken "<<n<<" at a time is ";
		for ( i = end; i >= 0; i-- )
			cout<<a[i];
		cout<<" exactly."<<endl;
	}
}