#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int begin,end,num;
	bool use;
}order[30];
int out[10];
int n,m,t,maxEarn;
int cmp ( const void*a , const void *b )
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	if ( c->begin != d->begin )
		return c->begin - d->begin;
	else
		return d->num - c->num;
}
void init ()
{
	int i;
	for ( i = 0; i <= m; i++ )
	{
		out[i] = 0;
	}
	maxEarn = 0;
}
void input ( )
{
	int i;
	for ( i = 0; i < t; i++ )
		scanf("%d%d%d",&order[i].begin,&order[i].end,&order[i].num);
	order[i].begin = m;
	order[i].end = m;
	order[i].num = 0;
	t++;
	qsort(order,t,sizeof(order[0]),cmp);
}
void dfs ( int oNum, int pNum, int earn, int lastStation )
{
	if ( oNum == t )
		return;
	int x= pNum;
	if ( lastStation != order[oNum].begin )
		pNum -= out[order[oNum].begin];
	if ( earn > maxEarn )
		maxEarn = earn;
	if ( pNum + order[oNum].num <= n )
	{
		out[order[oNum].end] += order[oNum].num;
		dfs(oNum+1,pNum+order[oNum].num,earn+order[oNum].num*(order[oNum].end-order[oNum].begin),order[oNum].begin);
		out[order[oNum].end] -= order[oNum].num;
	}
	dfs(oNum+1,x,earn,lastStation);
}
void solve ( )
{
	while ( scanf("%d%d%d",&n,&m,&t) != EOF )
	{
		if ( n == 0 && m == 0 && t == 0 )
			break;
		init();
		input();
		dfs(0,0,0,-1);
		printf("%d\n",maxEarn);
	}
}
int main ()
{
	solve();
	return 0;
}