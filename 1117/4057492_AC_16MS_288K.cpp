#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct ac
{
	int x,y;
};
vector<ac>ans;
int a[100];
int x[100],y[100];
int len;
bool cmp ( const ac&m1, const ac&m2 )
{
	if ( m1.x != m2.x )
		return m1.x < m2.x ;
	else
		return m2.y < m2.y;
}
void init ( int n )
{
	int i = 0;
	while ( n != 0 )
	{
		a[i++] = n%10;
		n/=10;
	}
	len = i;
}
int f ( int n )
{
	int i = 0;
	while ( n != 0 )
	{
		i++;
		n/=10;
	}
	if ( i != 0 )
		return i;
	else
		return 1;
}
void dfs ( int lay, int carry )
{
	if ( lay == len-1 )
	{
		if ( a[lay]-carry == x[lay] && x[lay] != 0  )
		{
			ac t;
			t.x = t.y = 0;
			int j;
			for ( j = len-1; j >= 0; j-- )
			{
				t.x *= 10;
				t.x += x[j];
			}
			for ( j = len-2; j >= 0; j-- )
			{
				t.y *= 10;
				t.y += y[j];
			}
			ans.push_back(t);
		}
		return;
	}
	int i,j,k;
	j = (a[lay]-x[lay]-carry+10)%10;
	y[lay] = j;
	if ( x[lay] == y[lay] )
	{
		for ( i = 0; i <= 9; i++ )
		{
			x[lay+1] = i;
			dfs(lay+1,(x[lay]+y[lay]+carry)/10);
		}
	}
	else
	{
		k = (x[lay]+y[lay]+carry)/10;
		i = lay+1;
		x[i] = j;
		while ( i < len-1 )
		{
			j = (a[i]-x[i]-k+10)%10;
			y[i] = j;
			k=(x[i]+y[i]+k)/10;
			i++;
			x[i] = y[i-1];
		}
		if ( x[len-1]+k == a[len-1]  )
		{
			ac t;
			t.x = t.y = 0;
			for ( j = len-1; j >= 0; j-- )
			{
				t.x *= 10;
				t.x += x[j];
			}
			for ( j = len-2; j >= 0; j-- )
			{
				t.y *= 10;
				t.y += y[j];
			}
			ans.push_back(t);
		}
	}
}
void solve ( int n )
{
	int i,j,k;
	for ( i =0; i < 10; i++ )
	{
		x[0] = i;
		dfs(0,0);
	}
	sort(ans.begin(),ans.end(),cmp);
	j = ans.size();
	printf("%d\n",j);
	for ( i = 0; i < j; i++ )
	{
		printf("%d + ",ans[i].x);
		k = f(ans[i].x)-f(ans[i].y)-1;
		while ( k-- > 0 )
			printf("0");
		printf("%d = %d\n",ans[i].y,n);
		if ( ans[i].x + ans[i].y != n )
			cout<<"NO"<<endl;
	}
}
int main ()
{
	int n;
	while ( cin>>n )
	{
		ans.clear();
		init(n);
		solve(n);
	}
	return 0;
}