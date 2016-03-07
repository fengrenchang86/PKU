#include <iostream>
using namespace std;
int main ()
{
	int n;
	int i;
	int t;
	int c;
	bool suc;
	while ( cin>>n && n!=0 )
	{
		int *a = new int[n];
		suc = false;
		c = 0;
		for ( i = 0; i < n; i++ )
			cin>>a[i];
		while ( suc == false )
		{
			c++;
			suc = true;
			t = a[n-1];
			for ( i = n-1; i >= 1; i-- )
			{
				a[i]/=2;
				a[i] += a[i-1]/2;
				if ( a[i] %2 == 1 )
					a[i]++;
			}
			a[0]/=2;
			a[0]+=t/2;
			if ( a[0]%2==1 )
				a[0]++;
			t = a[0];
			for ( i = 1; i < n; i++ )
			{
				if ( a[i] != t )
					suc = false;
			}
		}
		cout<<c<<" "<<a[0]<<endl;
                  delete a;
	}
	return 1;
}