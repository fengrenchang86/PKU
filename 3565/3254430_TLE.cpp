#include <iostream>
using namespace std;
struct point
{
	int x,y;
}w[110],b[110];
int max ( int a, int b )
{
	return a>b?a:b;
}
double max ( double a, double b )
{
	return a>b?a:b;
}
int min ( int a, int b )
{
	return a<b?a:b;
}
double min ( double a, double b )
{
	return a<b?a:b;
}
int multiply(point sp,point ep,point op) 
{ 
	return((sp.x-op.x)*(ep.y-op.y)-(ep.x-op.x)*(sp.y-op.y)); 
} 

bool iscross ( point p1, point p2, point p3, point p4 )
{
	int t1,t2;
	t1 = multiply(p1,p3,p4);
	t2 = multiply(p2,p3,p4);
	if ( t1*t2 > 0 )
		return false;
	t1 = multiply(p3,p1,p2);
	t2 = multiply(p4,p1,p2);
	if ( t1*t2 > 0 )
		return false;
	return true;
}
int n;
bool flag;
int ans[110];
bool visit[110];
void dfs ( int lay )
{
	if ( lay == n )
	{
		flag = true;
		return;
	}
	int i,j;
	for ( i = 0; i < n; i++ )
	{
		if ( visit[i] == true )
			continue;
		for ( j = 0; j < lay; j++ )
		{
			if ( iscross(w[lay],b[i],w[j],b[ans[j]])==true )
				break;
		}
		if ( j == lay )
		{
			ans[lay] = i;
			visit[i] = true;
			dfs(lay+1);
			if ( flag == true )
				return;
			visit[i] = false;
		}
	}
}
int main ()
{
	cin>>n;
	int i;
	flag = false;
	memset(visit,false,sizeof(visit));
	for ( i = 0; i < n; i++ )
		cin>>w[i].x>>w[i].y;
	for ( i = 0; i < n; i++ )
		cin>>b[i].x>>b[i].y;
	dfs(0);
	for ( i = 0; i < n; i++ )
		cout<<ans[i]+1<<endl;
	return 0;
}