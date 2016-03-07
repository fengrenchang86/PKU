#include <iostream.h>
void main ()
{
	int n[30];
	int ans ;
	int i = 0;
	int k;
	int sum = 0;
	while ( cin>>n[i] && n[i] != 0)
		i++;
	int j = 0;
	while ( j < i )
	{
	ans = 0;
	sum = n[j];
	k = sum;
	while ( sum >= 10 )
	{
		sum=0;
		while ( k != 0 )
		{
			
			sum+= k - k/10*10;
			k = k / 10;
		}
		k = sum;
	}
	cout<<sum<<endl;
	j++;
	}
}
