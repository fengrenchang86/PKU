#include <iostream>
using namespace std;
struct ac
{
	int v,c,p,r;
	ac *next;
}*list[20];
bool visit[20];
int ans,n;
void insert ( int x, int v, int c, int p, int r )
{
	ac *t = new ac;
	t->v = v;
	t->c = c;
	t->p = p;
	t->r = r;
	t->next = list[x];
	list[x] = t;
}
void init ()
{
	int i;
	for ( i = 0; i < 20; i++ )
	{
		list[i] = NULL;
		visit[i] = false;
	}
	ans = 2000000000;
}
void dfs ( int node, int price )
{
	if ( node == n )
	{
		if ( price < ans )
			ans = price;
		return;
	}
	bool q = visit[node];
	visit[node] = true;
	ac *t = list[node];
	while ( t != NULL )
	{
		if ( visit[t->c] == true && price+t->p < ans )
			dfs(t->v,price+t->p);
		else if ( price+t->r < ans )
			dfs(t->v,price+t->r);
		t = t->next;
	}
	visit[node] = q;
}
int main ()
{
	int m,i,x,v,c,p,r;
	scanf("%d%d",&n,&m);
	init();
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d%d%d%d",&x,&v,&c,&p,&r);
		insert(x,v,c,p,r);
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}