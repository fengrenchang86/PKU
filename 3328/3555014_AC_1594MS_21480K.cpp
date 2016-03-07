#include <iostream>
#include <queue>
using namespace std;
const int inf = 2147483647;
struct ac
{
	int step;
	int lx,ly,rx,ry;
	int next;//next = 1 is left going, else right going
};
queue<ac>que;
int n,m,ans;
char a[70][70];
int w[70][40][70][40];
void input()
{
	int i,j,k,l;
	for ( i = 0; i <= n+1; i++ )
	{
		for ( j = 0; j <= m+1; j++ )
			a[i][j] = 'X';
	}
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= m; j++ )
			scanf(" %c",&a[i][j]);
	}
	for ( i = 0; i <= n; i++ )
	{
		for ( j = 0; j <= m; j++ )
		{
			for ( k = 0; k <= n; k++ )
			{
				for ( l = 0; l <= m; l++ )
					w[i][j][k][l] = inf;
			}
		}
	}
	ans = inf;
}
void solve ()
{
	int i,j;
	ac p,q;
	for ( j = 1; j <= m; j++ )
	{
		if ( a[n][j] != 'S' )
			continue;
		p.lx = n;
		p.ly = j;
		p.rx = n;
		p.ry = j;
		p.step=0;
		p.next = 0;
		que.push(p);
		p.next = 1;
		que.push(p);
	}
	while ( !que.empty() )
	{
		p = que.front();
		que.pop();
		if ( w[p.lx][p.ly][p.rx][p.ry] < p.step )
			continue;
		if ( p.step >= ans )
			continue;
		if ( a[p.lx][p.ly] == 'T' || a[p.rx][p.ry] == 'T' )
		{
			ans = p.step;
			continue;
		}
		if ( p.next == 0 )
		{
			q = p;
			q.next = 1;
			q.ry=q.ly+1;
			for ( i = p.lx-2; i <= p.lx+2 && q.ry <= m ; i++ )
			{
				if ( i >= 1 && i <= n && a[i][q.ry] != 'X' )
				{
					if ( a[i][q.ry] != 'T' )
						q.step=p.step+(a[i][q.ry]-'0');
					else
						q.step=p.step;
					q.rx = i;
					if ( w[q.lx][q.ly][q.rx][q.ry] > q.step )
					{
						w[q.lx][q.ly][q.rx][q.ry] = q.step;
						que.push(q);
					}
				}
			}
			q.ry++;
			for ( i = p.lx-1; i<=p.lx+1 && q.ry <=m; i++ )
			{
				if ( i >= 1 && i <= n && a[i][q.ry] != 'X' )
				{
					if ( a[i][q.ry] != 'T' )
						q.step=p.step+(a[i][q.ry]-'0');
					else
						q.step=p.step;
					q.rx = i;
					if ( w[q.lx][q.ly][q.rx][q.ry] > q.step )
					{
						w[q.lx][q.ly][q.rx][q.ry] = q.step;
						que.push(q);
					}
				}
			}
			q.ry++;
			q.rx = q.lx;
			if ( q.ry <= m && a[q.rx][q.ry] != 'X' )
			{
				if ( a[q.rx][q.ry] != 'T' )
					q.step=p.step+(a[q.rx][q.ry]-'0');
				else
					q.step=p.step;
				if ( w[q.lx][q.ly][q.rx][q.ry] > q.step )
				{
					w[q.lx][q.ly][q.rx][q.ry] = q.step;
					que.push(q);
				}
			}
		}
		else
		{
			q = p;
			q.next = 0;
			q.ly=q.ry-1;
			for ( i = q.rx-2; i <= q.rx+2 && q.ly >= 1; i++ )
			{
				q.lx = i;
				if ( i >= 1 && i <= n && a[i][q.ly] != 'X' )
				{
					if ( a[i][q.ly] != 'T' )
						q.step=p.step+(a[i][q.ly]-'0');
					else
						q.step=p.step;
					if ( w[q.lx][q.ly][q.rx][q.ry] > q.step )
					{
						w[q.lx][q.ly][q.rx][q.ry] = q.step;
						que.push(q);
					}
				}
			}
			q.ly--;
			for ( i = q.rx-1; i<=q.rx+1 && q.ly >= 1; i++ )
			{
				q.lx = i;
				if ( i >= 1 && i <=n && a[i][q.ly] != 'X' )
				{
					if ( a[i][q.ly] != 'T' )
						q.step=p.step+(a[i][q.ly]-'0');
					else
						q.step=p.step;
					if ( w[q.lx][q.ly][q.rx][q.ry] > q.step )
					{
						w[q.lx][q.ly][q.rx][q.ry] = q.step;
						que.push(q);
					}
				}
			}
			q.ly--;
			q.lx = q.rx;
			if ( q.ly >= 1 && a[q.lx][q.ly] != 'X' )
			{
				if ( a[q.lx][q.ly] != 'T' )
					q.step=p.step+(a[q.lx][q.ly]-'0');
				else
					q.step=p.step;
				if ( w[q.lx][q.ly][q.rx][q.ry] > q.step )
				{
					w[q.lx][q.ly][q.rx][q.ry] = q.step;
					que.push(q);
				}
			}
		}
	}
	if ( ans != inf )
		printf("%d\n",ans);
	else
		printf("-1\n");
}
int main ()
{
	while  (scanf("%d%d",&m,&n) != EOF )
	{
		if ( n == 0 && m == 0 )
			break;
		input();
		solve();
	}
	return 0;
}