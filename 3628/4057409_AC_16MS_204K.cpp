#include <iostream>
using namespace std;
int n,b;
int ans=2000000000;
int a[30];
void dfs ( int lay, int k )
{
	if ( k >= b && k-b < ans )
	{
		ans = k-b;
	}
	else if ( k >= b )
		return;
	if ( lay == n )
		return;
	dfs(lay+1,k+a[lay]);
	dfs(lay+1,k);
}
int main ()
{
	scanf("%d%d",&n,&b);
	int i;
	for ( i = 0; i < n; i++ )
		scanf("%d",&a[i]);
	dfs(0,0);
	printf("%d\n",ans);
	return 0;
}