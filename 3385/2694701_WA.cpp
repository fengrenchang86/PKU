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
	for ( i = 1; i <= n; i++ )
	{
		if ( a[c] > d )
		{
			while ( a[c] > d )
			{
				ans += a[c]/d;
				if ( a[c]%d != 0 )
					ans++;
				a[c] /= d;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}