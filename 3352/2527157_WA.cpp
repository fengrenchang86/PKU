#include <iostream>
using namespace std;
bool visit[1200];
struct ac
{
	int v;
	ac *next;
	ac(){next=NULL;}
}*list[1200];
int v[1010][1010];
void insert ( int a, int b )
{
	ac *p = new ac;
	p->v = b;
	p->next = list[a];
	list[a] = p;
	p = new ac;
	p->v = a;
	p->next = list[b];
	list[b] = p;
}
int ans = 0;
void dfs ( int node )
{
	int c = 0;
	ac *p = list[node];
	while ( p != NULL )
	{
		if ( visit[p->v] == false )
		{
			if ( v[p->v][node] == 1 )
				c++;
			visit[p->v] = true;
			dfs ( p->v );
		}
		p = p->next;
	}
	if ( c != 0 )
		ans += (c-1);
}
int main ()
{
	int n,m,i,j,a,b;
	scanf("%d%d",&n,&m);
	for ( i = 1; i <= n; i++ )
		for ( j =1; j <= n; j++ )
			v[i][j] = 0;
	for ( i = 1; i <= n; i++ )
		list[i] = NULL;
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d",&a,&b);
		insert(a,b);
		v[a][b]++;
		v[b][a]++;
	}
	b = 0;
	for ( i = 1; i <= n; i++ )
	{
		memset(visit,0,sizeof(visit));
		visit[i] = true;
		ans = 0;
		dfs(i);
		if ( ans > b )
			b = ans;
	}
	cout<<b<<endl;
	return 0;
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= n; j++ )
			visit[j] = false;
		visit[i] = true;
		a = 0;
		ac *p = list[i];
		while ( p != NULL )
		{
			if ( visit[p->v] == false )
			{
				visit[p->v] = true;
				a++;
				dfs(p->v);
			}
			p = p->next;
		}
		if ( a > b )
			b = a;
	}
	cout<<b-1<<endl;
	return 0;
}