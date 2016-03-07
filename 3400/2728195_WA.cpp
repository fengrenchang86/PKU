#include <iostream>
using namespace std;
int n,d;
struct ac
{
	int w,c;
}a[20];
int max=0;
void dfs ( int x, int y, int lay, int cost )
{
	if ( lay == n )
	{
		if (cost >max)
			max= cost;
		return;
	}
	if ( abs(x+a[lay].w-y) < d || x + d <= y)
		dfs(x+a[lay].w,y,lay+1,cost);
	if ( abs(y+a[lay].w-x) < d || y + d <= x)
		dfs(x,y+a[lay].w,lay+1,cost+a[lay].c);
}
int main ()
{
	cin>>n>>d;
	for ( int i = 0; i < n; i++ )
		cin>>a[i].w>>a[i].c;
	dfs(a[0].w,0,1,0 );
	cout<<max<<endl;
	return 0;
}