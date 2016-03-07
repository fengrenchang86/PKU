#include <iostream>
using namespace std;
int n;
struct wa
{
	int v;
	wa *next;
	wa(){next=NULL;}
}*list[100100];
bool visit[100100];
int w[100100];
int parrent[100100];
int apple[100100];
void insert ( int x, int y )
{
	wa *p = new wa;
	p->v = y;
	p->next = list[x];
	list[x] = p;
	p = new wa;
	p->v = x;
	p->next = list[y];
	list[y] = p;
}
int dfs ( int node )
{
	wa *p = list[node];
	int t = 1;
	while ( p != NULL )
	{
		if ( visit[p->v] == false )
		{
			parrent[p->v] = node;
			visit[p->v] = true;
			t += dfs(p->v);
		}
		p = p->next;
	}
	w[node] = t;
	return w[node];
}
void init()
{
	int i;
	for ( i = 0; i <= n; i++ )
	{
		visit[i] = false;
		list[i] = NULL;
		apple[i] = 1;
	}
}
int main ()
{
	int i,x,y;
	char ch;
	scanf("%d",&n);
	init();
	for ( i = 0; i < n-1; i++ )
	{
		scanf("%d%d",&x,&y);
		insert(x,y);
	}
	visit[1] = true;
	dfs(1);
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		cin>>ch>>x;
		if ( ch == 'Q' )
			printf("%d\n",w[x]);
		else
		{
			if ( apple[x] == 1 )
				y = -1;
			else
				y = 1;
			while ( x != 1 )
			{
				apple[x] += y;
				w[x]+=y;
				x = parrent[x];
			}
			w[x]+=y;
		}
	}
	return 0;
}
