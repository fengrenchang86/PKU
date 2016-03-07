#include <iostream.h>
int f ( int m, int n )
{
	int t;
	while ( n != 0 )
	{
		t = n;
		n = m%n;
		m = t;
	}
	if ( m == 1 )
		return 1;
	else
		return 0;
}

void main ()
{
	int i;
	int j;
	int n;
	int k;
	int c;
	int sum;
	cin>>n;
	for ( c = 1; c <= n; c++ )
	{
		cin>>k;
		sum = 0;
		cout<<c<<" "<<k<<" ";
		for ( i = 1; i <= k-1;i++ )
		{
			for ( j = i+1; j<=k; j++ )
			{
				sum+=f(j,i);
			}
		}
		sum++;
		sum *= 2; 
		sum++;
		cout<<sum<<endl;
	}
}