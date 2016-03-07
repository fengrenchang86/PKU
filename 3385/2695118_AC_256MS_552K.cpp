#include <iostream>
using namespace std;
int a[100100];
int main ()
{
	int n,d,i,c,ans=0;
	scanf("%d%d",&n,&d);
	for ( i = 0; i <= n; i++ )
		a[i] = -1;
	for ( i = 0; i < n; i++ )
	{
		scanf("%d",&c);
		if ( a[c] == -1 )
			a[c] = 1;
		else
			a[c]++;
	}
	for ( i = 0; i <= n; i++ )
	{
		if ( a[i] > d )
		{
			while ( a[i] > d )
			{
				if ( a[i]/d + a[i]%d <= d )
				{
					ans += a[i]/d;
					a[i] /= d;
				}
				else if ( a[i] % d == 0 )
				{
					ans += a[i]/d;
					a[i] /= d;
				}
				else if ( a[i] % d != 1 )
				{
					ans += a[i]/d+1;
					a[i] = a[i]/d+1;
				}
				else
				{
					ans += a[i]/d;
					a[i] = a[i]/d+1;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}