#include <iostream>
using namespace std;
struct ac
{
	int v;
	ac *next;
}*list[1100];
struct wa
{
	int begin,end,value;
}a[1100];
int in[1100];
bool visit[1100];
int w[1100];
int N,M,R;
void insert ( int x, int y )
{
	in[y]++;
	ac *p = new ac;
	p->v = y;
	p->next = list[x];
	list[x] = p;
}
void input()
{
	scanf("%d%d%d",&N,&M,&R);
	int i,j;
	for ( i = 0; i < M; i++ )
		list[i] = NULL;
	for ( i = 0; i < M; i++ )
	{
		scanf("%d%d%d",&a[i].begin,&a[i].end,&a[i].value);
		in[i] = 0;
		w[i] = 0;
	}
	for ( i = 0; i < M; i++ )
	{
		for ( j = 0; j < M; j++ )
		{
			if ( a[j].begin-a[i].end > R )
				insert(i,j);
		}
	}
}
void dfs ( int v )
{
	ac *p = list[v];
	while ( p != NULL )
	{
		in[p->v]--;
		if ( in[p->v] == 0 )
		{
			if ( w[p->v] < w[v]+a[p->v].value )
				w[p->v] = w[v]+a[p->v].value;
			dfs(p->v);
		}
		p = p->next;
	}
}
void solve ()
{
	int i,j=0;
	for ( i = 0; i < M; i++ )
		w[i] = a[i].value;
	for ( i = 0; i < M; i++ )
	{
		if ( in[i] == 0 )
			visit[i] = true;
		else
			visit[i] = false;
	}
	for ( i = 0; i < M; i++ )
	{
		if ( visit[i] )
			dfs(i);
	}
	for ( i = 0; i < M;i++ )
	{
		if ( w[i] > j )
			j = w[i];
	}
	printf("%d\n",j);
}
int main ()
{
	input();
	solve();
	return 0;
}