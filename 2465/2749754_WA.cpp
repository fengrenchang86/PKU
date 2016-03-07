#include <iostream>
using namespace std;
int main ()
{
	int pow[120],price[120];
	int c[120][210];
	int i,j,k,n,min;
	bool ok;
	while ( cin>> k )
	{
	i = 1;
	pow[0] = 0;
	while ( cin>>pow[i]>>price[i]  )
		i++;
	pow[i] = k;
	price[i] = 0;
	n = i-1;
	ok = true;
	if ( k == 0 )
	{
		cout<<0<<endl;
		continue;
	}
	if ( pow[1] > 100 )
	{
		cout<<"Impossible"<<endl;
		continue;
	}
	if ( k-pow[n] > 100 )
	{
		cout<<"Impossible"<<endl;
		continue;
	}
	for ( i = 1; i <= n; i++ )
		if ( pow[i+1]-pow[i] > 200 )
		{
			cout<<"Impossible"<<endl;
			ok = false;
			break;
		}
	if ( ok == false )
		continue;
	for ( j = pow[2]-pow[1]; j <= 200; j++ )
		c[1][j] = price[1]*(j-100+pow[1]);
	for ( i = 2; i <= n; i++ )
	{
		for ( j = pow[i+1]-pow[i]; j <= 200; j++ )
		{
			min = 2000000000;
			for ( k = pow[i]-pow[i-1]; k <= 200 && j-k+pow[i]-pow[i-1]>=0; k++ )
			{
				if ( c[i-1][k] + price[i]*(j-k+pow[i]-pow[i-1]) < min )
					min = c[i-1][k] + price[i]*(j-k+pow[i]-pow[i-1]);
			}
			c[i][j] = min;
		}
	}
	cout<<c[n][100+pow[n+1]-pow[n]]<<endl;
	}
	return 0;
}