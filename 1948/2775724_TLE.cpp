#include <iostream>
#include <math.h>
using namespace std;
int a[50];
bool c[1610][1610];
bool ok = false;
int max = 0;
int s ( int x, int y, int z )
{
	double area = (x*x+y*y-z*z)/(2.0*x*y);
	area = acos(area);
	area = 0.5*x*y*sin(area);
	return int(area*100);
}
void dfs ( int x, int y, int i, int n )
{
//	if ( c[x][y] == true )
//		return;
	int z=a[0]-x-y;
	c[x][y] = c[y][x] = true;
	if ( x+y > z && y+z > x && x+z > y)
	{
		int t=s(x,y,z);
		ok = true;
		if ( t > max )
			max = t;
	}
	if ( i > n )
		return;
	dfs(x+a[i],y,i+1,n);
	dfs(x,y+a[i],i+1,n);
	dfs(x,y,i+1,n);
}
int main ()
{
	int n,i,j;
	cin>>n;
	for ( i = 0; i <= 1600; i++ )
		for ( j = 0; j <= 1600; j++ )
			c[i][j] = false;
	a[0] = 0;
	for ( i = 1; i <= n; i++ )
	{
		scanf("%d",&a[i]);
		a[0] += a[i];
	}
	dfs(0,0,1,n);
	if ( ok == true )
		cout<<max<<endl;
	else
		cout<<-1<<endl;
	return 0;
}