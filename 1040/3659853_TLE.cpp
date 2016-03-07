#include <iostream>
using namespace std;
struct ac
{
	int end,num;
	bool use;
}a[10][30];
int sizeA[10];
int out[10];
int n,m,maxEarn;
void init ()
{
	int i;
	for ( i = 0; i <= m; i++ )
	{
		sizeA[i] = 0;
		out[i] = 0;
	}
	maxEarn = 0;
}
void input ( int t )
{
	int x,y,z,i,j;
	for ( i = 0; i < t; i++ )
	{
		scanf("%d%d%d",&x,&y,&z);
		j = sizeA[x];
		a[x][j].end = y;
		a[x][j].num = z;
		a[x][j].use = false;
		sizeA[x]++;
	}
}
void dfs ( int sNum, int pNum, int earn, bool flag )
{
	if ( sNum == m+1 )
		return;
	int i,j;
	j = sizeA[sNum];
	if ( flag )
		pNum -= out[sNum];
	if ( pNum == 0 && earn > maxEarn )
		maxEarn = earn;
	for ( i = 0; i < j; i++ )
	{
		if ( a[sNum][i].use == false && pNum + a[sNum][i].num <= n )
		{
			a[sNum][i].use = true;
			out[a[sNum][i].end] += a[sNum][i].num;
			dfs(sNum,pNum+a[sNum][i].num,earn+a[sNum][i].num*(a[sNum][i].end-sNum),false);
			out[a[sNum][i].end] -= a[sNum][i].num;
			a[sNum][i].use = false;
		}
	}
	dfs(sNum+1,pNum,earn,true);
}
void solve ( )
{
	int t;
	while ( scanf("%d%d%d",&n,&m,&t) != EOF )
	{
		if ( n == 0 && m == 0 && t == 0 )
			break;
		init();
		input(t);
		dfs(0,0,0,true);
		printf("%d\n",maxEarn);
	}
}
int main ()
{
	solve();
	return 0;
}