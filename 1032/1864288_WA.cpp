#include <iostream.h>
void main ()
{
	int i;
	int n;
	int sum;
	int ji;
	int c;
	int maxsum = 0;
	int maxji = 0;
	int pos = 0;
	int a[1001];
	cin>>n;
	for ( i = 0; i < 1001; i++ )
		a[i] = i;
	sum = 0;
	ji = 1;
	c = 1;
	i = c;
	while ( i < 1001 )
	{
		sum+=a[i];
		ji *= a[i];
		if ( sum > n )
		{
			sum = 0;
			ji = 1;
			c++;
			i = c;
		}
		else if ( sum == n )
		{
			if ( ji > maxji )
			{
				maxji = ji;
				maxsum = sum;
				pos = c;
			}
			sum = 0;
			ji = 1;
			c++;
			i = c;
		}
		else
			i++;
	}
	i = pos;
	sum = 0;
	while ( a[sum] != n )
	{
		cout<<a[i]<<" ";
		sum += a[i++];
	}
	cout<<endl;

}