#include <iostream>
#include <queue>
using namespace std;
struct ac
{
	int pos;
	int val;
	int energy;
};
int a[11000];
int dp[11000][600];
int c[11000][510][2];
int n,m;
void ACM ()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d",&a[i]);
		for ( j = 0; j <= m; j++ )
		{
			c[i][j][0] = -1;
			c[i][j][1] = -1;
		}
	}
	c[0][0][0] = 0;
	c[0][1][1] = a[0];
	for ( i = 1; i < n; i++ )
	{
		for ( j = 0; j <= m; j++ )
		{
			if ( j == 0 && c[i-1][0][0] > c[i][0][0] )
				c[i][0][0] = c[i-1][0][0];
			if ( j == 0 && c[i-1][1][1] > c[i][0][0] )
				c[i][0][0] = c[i-1][1][1];
	//		if ( j == 0 )
	//			continue;
			if ( j==1 && c[i-1][j-1][0]+a[i] > c[i][j][1] )
				c[i][j][1] = c[i-1][j-1][0]+a[i];
			if ( j > 0 && c[i-1][j-1][1] != -1 && c[i-1][j-1][1]+a[i] > c[i][j][1] )
				c[i][j][1] = c[i-1][j-1][1]+a[i];
			if ( j < m && c[i-1][j+1][0] != -1 && c[i-1][j+1][0] > c[i][j][0] )
				c[i][j][0] = c[i-1][j+1][0];
		}
	}
	printf("%d\n",c[n-1][0][0]);
}
queue<ac>que;
void solve ()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d",&a[i]);
		for ( j = 0; j <= m; j++ )
			dp[i][j] = 0;
	}
	ac p,q;
	p.energy = 1;
	p.pos = 1;
	p.val = a[0];
	dp[0][1] = a[0];
	dp[0][0] = 0;
	que.push(p);
	p.energy = 0;
	p.pos = 1;
	p.val = 0;
	que.push(p);
	while ( !que.empty() )
	{
		p = que.front();
		que.pop();
		if ( dp[p.pos][p.energy] > p.val )
			continue;
		q.pos = p.pos+1;
		q.energy = p.energy+1;
		q.val = p.val+a[q.pos];
		if ( q.pos < n && dp[q.pos][q.energy] < q.val )
		{
			dp[q.pos][q.energy] = q.val;
			que.push(q);
		}
		q.energy = 0;
		q.val = p.val;
		q.pos = p.pos+p.energy;
		if ( q.pos >= n )
			continue;
		if ( dp[q.pos][q.energy] < q.val )
		{
			dp[q.pos][q.energy] = q.val;
			que.push(q);
		}
		if ( p.energy == 0 )
		{
			q = p;
			q.pos++;
			if ( q.pos < n && dp[q.pos][q.energy] < q.val )
			{
				dp[q.pos][q.energy] = q.val;
				que.push(q);
			}
			que.push(q);
		}
	}
	printf("%d\n",dp[n-1][0]);
}
int main ()
{
	ACM();
//	solve();
	return 0;
}