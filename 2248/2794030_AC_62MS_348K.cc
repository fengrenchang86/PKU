#include <iostream>
using namespace std;
int a[120];
int ans[120];
int tmin;
int n;
int main ()
{
	void dfs(int);
	while ( cin>>n && n!=0 )
	{
		tmin = 200000;
		a[0] = 1;
		dfs(1);
		for ( n = 0; n < tmin-1; n++ )
			cout<<ans[n]<<" ";
		cout<<ans[n]<<endl;
	}
	return 0;
}
void dfs ( int k )
{
	int i;
	if ( a[k-1] == n )
	{
		if ( k < tmin )
		{
			for ( i = 0; i < k; i++ )
				ans[i] = a[i];
			tmin = k;
		}
		return;
	}
	else if ( k >= tmin )
		return;
	for ( i = k-1; i >= 0; i-- )
	{
		if ( a[i]+a[k-1] <= n )
		{
			a[k] = a[i]+a[k-1];
			dfs(k+1);
		}
	}
}