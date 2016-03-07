#include <iostream>
using namespace std;
bool visit[100010];
int price[200][2];
int n,k;
int count;
void dfs ( int x, int sum )
{
	if ( x > n )
		return ;
	if ( sum <= k && visit[sum] == false )
	{
		visit[sum] = true;
		count++;
	}
	if ( price[x][1] > 0 )
	{
		if ( sum + price[x][0] <= k )
		{
			price[x][1]--;
			dfs ( x,sum+price[x][0]);
			price[x][1]++;
		}
	}
	dfs ( x+1, sum );
}

int main ()
{
	int i;
	while( scanf("%d%d",&n,&k) && !(n==0&&k==0) )
	{
		for ( i = 1; i <= n; i++ )
			scanf("%d",&price[i][0]);
		for ( i = 1; i <= n; i++ )
			scanf("%d",&price[i][1]);
		visit[0] = true;
		for ( i = 1; i <= k; i++ )
			visit[i] = false;
		count = 0;
		dfs ( 1,0);
		cout<<count<<endl;
	}
	return 0;
}