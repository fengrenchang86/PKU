#include <iostream>
using namespace std;
int v[50];
int flag = 0;
int count=1;
void ini ()
{
	int i;
	for ( i = 0; i < 50; i++ )
		v[i] = 0;
}
void dfs( int lay, int end )	//用dfs测试，发现递推关系
{
	if ( lay == end+1 )
	{
		count++;
		return;
	}
	if ( v[lay-1] == 0 )
	{
		v[lay] = 1;
		dfs(lay+1,end);
		v[lay] = 0;
	}
	dfs(lay+1,end);	
}
int main ()
{
	int i;
	int a[50];
	int n;
	a[1] = 2;
	a[2] = 3;
	for ( i = 3; i <= 45; i++ )
		a[i] = a[i-1]+a[i-2];
	int tcase;
	cin>>tcase;
	for ( i = 1; i <= tcase; i++ )
	{
		cin>>n;
		printf("Scenario #%d:\n%d\n\n",i,a[n]);
	}
	return 0;
}