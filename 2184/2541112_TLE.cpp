#include <iostream>
using namespace std;
struct wf
{
	int a,b;
	int type;
	bool visit;
}t[120];
int n;
bool ans[120];
int max = 0;
void init ()
{
	int i;
	for ( i = 0; i <= 100; i++ )
		ans[i] = false;
}
void dfs ( int x, int y, int sum, int pos )
{
	int i;
	if ( sum <= max )
		return ;
	if ( x >= 0 && y >= 0 )
	{
		if ( sum > max )
			max = sum;
		return ;
	}
	for ( i = pos; i < n; i++ )
	{
		if ( t[i].type == 2 )
		{
			dfs(x,y,sum,i+1);
			t[i].visit = false;
			dfs(x-t[i].a,y-t[i].b,sum-t[i].a-t[i].b,i+1);
			t[i].visit = true;
		}
		else if ( t[i].type == 3 )
		{
			dfs(x,y,sum,i+1);
			t[i].visit = true;
			dfs(x+t[i].a,y+t[i].b,sum+t[i].a+t[i].b,i+1);
			t[i].visit = false;
		}
	}
}
int main ()
{
	int i=0,j=0;
	int x=0,y=0,sum=0;
	scanf("%d",&n);
	for ( j = 0; j< n; j++ )
	{
		scanf("%d%d",&t[i].a,&t[i].b);
		t[i].visit = false;
		if ( t[i].a >= 0 && t[i].b >= 0 )
		{
			x += t[i].a;
			y += t[i].b;
			sum += t[i].a+t[i].b;
			t[i].type = 1;
			t[i].visit = true;
		}
		else if ( t[i].a <= 0 && t[i].b <= 0 )
			t[i].type = -1;
		else if ( t[i].a+t[i].b>0 && t[i].a*t[i].b < 0 )
		{
			t[i].type = 2;
			x += t[i].a;
			y += t[i].b;
			sum += t[i].a+t[i].b;
			t[i].visit = true;
			i++;
		}
		else
		{
			t[i].type = 3;
			i++;
		}
	}
	n = i;
	dfs(x,y,sum,0);
	cout<<max<<endl;
	return 0;
}