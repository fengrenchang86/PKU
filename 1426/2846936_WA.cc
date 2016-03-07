#include <iostream>
using namespace std;
bool visit[210];
char a[2000];
bool flag;
int main ()
{
	void dfs(int,int,int);
	int n;
	while ( cin>>n && n!= 0)
//	for ( n = 1; n <= 200; n++ )
	{
		flag = false;
		memset(visit,false,sizeof(visit));
		visit[1] = true;
		a[0] = '1';
		dfs(n,1,1);
		cout<<a<<endl;
	}
	return 0;
}
void dfs ( int n, int k, int sum )
{
	int t = sum%n*10%n;
	t %= n;
	if ( t == 0 )
	{
		a[k] = '0';
		a[k+1] = NULL;
		flag = true;
		return;
	}
	if ( visit[t] == false )
	{
		visit[t] = true;
		a[k] = '0';
		dfs(n,k+1,t);
	}
	if ( flag == true )
		return;
	t = sum%n*10%n+1;
	t %= n;
	if  ( t == 0 )
	{
		a[k] = '1';
		a[k+1] = NULL;
		flag = true;
		return;
	}
	if ( visit[t] == false )
	{
		visit[t] = true;
		a[k] = '1';
		dfs(n,k+1,t);
	}
}