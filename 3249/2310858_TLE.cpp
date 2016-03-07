#include <iostream>
using namespace std;
int m,n;
class ac
{
public:
	int node;
	ac *next;
	ac(){next=NULL;}
}*list[100010];
void insert ( int a, int b )
{
	ac *p = new ac;
	p->node = a;
	p->next = list[b];
	list[b] = p;
}
int max;
bool visit[100010];
bool first[100010];
int prov[100010];
int w[100010];
void dfs ( int node )
{
	if ( list[node] == NULL )
	{
		if ( max < w[node] )
			max = w[node];
		return; 
	}
	ac *p = list[node];
	while ( p != NULL )
	{
		if ( visit[p->node] == false )
		{
			visit[p->node] = true;
			w[p->node] = w[node]+prov[p->node];
			dfs(p->node);
		}
		else if ( w[node] + prov[p->node] > w[p->node] )
		{
			w[p->node] = w[node]+prov[p->node];
			dfs(p->node);
		}
		p = p->next;
	}
}
int main ()
{
	int i,x,y;
	int vis;
	while ( scanf("%d%d",&n,&m ) !=EOF )
	{
		for ( i = 1; i <= n; i++ )
		{
			scanf("%d",&prov[i]);
			visit[i] = first[i] = false;
			list[i] = NULL;
			w[i] = 0;
		}
		for ( i = 0; i < m; i++ )
		{
			scanf("%d%d",&x,&y);
			insert(y,x);
			first[y] = true;
		}
		vis = 1;
		max = 0;
		while ( vis <= n )
		{
			if ( visit[vis] == false && first[vis] == false )
			{
				w[vis] = prov[vis];
				visit[vis] = true;
				dfs( vis );
			}
			vis++;
		}
		printf("%d\n",max);
	}
	return 0;
}