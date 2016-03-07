#include <iostream>
using namespace std;
int n,d;
struct ac
{
	int a,b,s;
	bool visit;
}t[20];
double check ( int a, int b, int xp )
{
	if ( xp < a )
		return 0.0;
	else if ( xp > b )
		return 1.0;
	else
		return double(double(xp)-double(a))/double(double(b)-double(a));
}
double max=0.0;
int v[20];
int ans[20];
void dfs ( double pro, int count, int exp )
{
	int i;
	if ( pro < max )
		return;
	if ( count == n )
	{
		if ( pro > max )
		{
			max=pro;
			for ( i = 0; i < n; i++ )
				ans[i] = v[i];
		}
		return;
	}
	for ( i = 0; i < n; i++ )
	{
		if ( t[i].visit == false )
		{
			t[i].visit = true;
			v[count] = i;
			dfs(pro*check(t[i].a,t[i].b,exp),count+1,exp+t[i].s);
			t[i].visit = false;
		}
	}
}
int main ()
{
	cin>>n>>d;
	int i;
	for ( i = 0; i < n; i++ )
	{
		cin>>t[i].a>>t[i].b>>t[i].s;
		t[i].visit = false;
	}
	for ( i = 0; i < n; i++ )
	{
		dfs(1.0,0,d);
	}
	printf("%.3lf\n",max);
	if ( max == 0.0 )
	{
		for ( i = 0; i < n-1; i++ )
			cout<<i+1<<" ";
		cout<<n<<endl;
	}
	else
	{
		for ( i = 0; i < n-1; i++ )
			cout<<ans[i]+1<<" ";
		cout<<ans[i]+1<<endl;
	}
	return 0;
}
