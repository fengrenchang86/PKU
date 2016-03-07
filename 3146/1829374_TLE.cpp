#include <iostream>
#include <iomanip>
using namespace std;
void main ( )
{
	int pd (int, int, int );
	int number = 1;
	int in1 = 1;
	int in2 = 1;
	int i;
	int ans = 0;
	
	while ( 1 )
	{
		ans = 0;
		cin>>in1>>in2;
		if ( in1 == 0 && in2 == 0 )
			break;
		for ( i = 0; i <= ( in2 - 1 ) / 2; i++ )
		{
			ans += pd (in2, i, in1 );
		}
		ans *= 2;
		if ( in2 % 2 == 0 )
		{
			ans += pd (in2, in2 / 2, in1 );
		}
		ans = in2 - ans + 1;
		ans %= 10000;
		cout<<"Case "<<number++<<": "<<setw(4)<<setfill('0')<<ans<<endl;
	}
	
}

int pd ( int m, int n, int p )
{
	int i;
	int c1 = 0;
	int temp;
	for ( i = m; i >= m - n + 1; i-- )
	{
		if ( i % p == 0 )
		{
			c1++;
			temp = i / p;
			while ( temp % p == 0 )
			{
				c1 ++;
				temp = temp / p;
			}
		}
	}
	for ( i = n; i > 1; i-- )
	{
		if ( i % p == 0 )
		{
			c1--;
			temp = i / p;
			while ( temp % p == 0 )
			{
				c1--;
				temp = temp / p;
			}
		}
	}
	if ( c1 >=1 )
		return 1;
	else 
		return 0;
}