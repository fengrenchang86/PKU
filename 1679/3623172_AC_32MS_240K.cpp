#include <iostream>
using namespace std;
const int inf = 2000000000;
struct ac
{
	int x,y;
}a[11000];
int c[120][120];
bool visit[120];
int pre[120];
int w[120];
int n,m,num;
void input()
{
	void init();
	int i,x,y,z;
	scanf("%d%d",&n,&m);
	init();
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d%d",&x,&y,&z);
		c[x][y] = c[y][x] = z;
	}
}
void init()
{
	int i,j;
	for ( i = 1; i <= n; i++ )
		for ( j = 1; j <= n; j++ )
			c[i][j] = inf;
}
int Prim ( bool flag )
{
	int i,j,k,tmin;
	int ans = 0;
	if ( flag )
		num = 0;
	for ( i = 1; i <= n; i++ )
	{
		visit[i] = false;
		w[i] = inf;
	}
	visit[1] = true;
	for ( i = 2; i <= n; i++ )
	{
		if ( c[1][i] != inf )
		{
			w[i] = c[1][i];
			pre[i] = 1;
		}
	}
	for ( i = 1; i < n; i++ )
	{
		tmin = inf;
		for ( j = 1; j <= n; j++ )
		{
			if ( !visit[j] && w[j] < tmin )
			{
				tmin = w[j];
				k = j;
			}
		}
		if ( tmin == inf )
			return -1;
		visit[k] = true;
		ans += c[pre[k]][k];
		if ( flag )
		{
			a[num].x = pre[k];
			a[num].y = k;
			num++;
		}
		for ( j = 1; j <= n; j++ )
		{
			if ( !visit[j] && w[j] > c[j][k] )
			{
				w[j] = c[j][k];
				pre[j] = k;
			}
		}
	}
	return ans;
}
void solve ()
{
	int i,j,k,tmin,ans=inf;
	tmin = Prim(true);
	for ( i = 0; i < num; i++ )
	{
		k = c[a[i].x][a[i].y];
		c[a[i].x][a[i].y] = c[a[i].y][a[i].x] = inf;
		j = Prim(false);
		if ( j < ans && j != -1 )
			ans = j;
		c[a[i].x][a[i].y] = c[a[i].y][a[i].x] = k;
	}
	if ( tmin == ans )
		printf("Not Unique!\n");
	else
		printf("%d\n",tmin);
}
int main ()
{
	int tc;
	scanf("%d",&tc);
	while ( tc-- )
	{
		input();
		solve();
	}
	return 0;
}