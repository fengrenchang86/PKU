#include <iostream>
#include <iomanip>
using namespace std;
int main ()
{
	int a[1000];
	int c = 0;
	int n;
	int i;
	int j;
	while ( cin>>n && n !=0 )
	{
		c = 0;
		int g[11] = {0};
		for ( i = 0; i < 1000; i++ )
			a[i] = 0;
		a[0] = 1;
		for ( i = 2; i <= n; i++ )
		{
			for ( j = 0; j <= c; j++ )
				a[j] *= i;
			for ( j = 0; j <= c; j++ )
			{
				a[j+1] += (a[j]/10000);
				a[j] %= 10000;
			}
			if ( a[c+1] > 0 )
				c++;
		}
		for ( i = 0; i < c; i++ )
		{
			j = a[i];
			g[j%10]++;
			j/=10;
			g[j%10]++;
			j/=10;
			g[j%10]++;
			j/=10;
			g[j%10]++;
		}
		j = a[c];
		while ( j != 0 )
		{
			g[j%10]++;
			j/=10;
		}
		cout<<n<<"! --"<<endl;
		for ( i = 0; i < 10; i++ )
		{
			cout<<"   ("<<i<<")";
			cout<<setw(5)<<g[i];
			if ( i == 4 )
				cout<<endl;
		}
		cout<<endl;
		
	}
	return 1;
}