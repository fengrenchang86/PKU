#include <iostream>
#include <stdlib.h>
using namespace std;
int visit[1001];
int stack[1001];
int head = 0;
int cow[1001];
int v[1001];
int k,n,m;
struct ac
{
	int node;
	ac *next;
	ac(){next=NULL;}
}*list[1001],*LIST[1001];
void insert( int a, int b )
{
	ac *p = new ac;
	p->node = b;
	p->next = list[a];
	list[a] = p;
	p = new ac;
	p->node = a;
	p->next = LIST[b];
	LIST[b] = p;
}
int max = 0;
int plus;
void wa ( int node )
{
	ac *p = list[node];
	while ( p != NULL )
	{
		if ( visit[p->node] == 0 )
		{
			visit[p->node] = 1;
			v[p->node] += plus;
			wa(p->node);
		}
		p = p->next;
	}
}
int main ()
{
	int i,d,c=0;
	int quee[1001];
	int front = 0;
	scanf("%d%d%d",&k,&n,&m);
	for ( i = 0; i <= n; i++ )
	{
		list[i] = LIST[i] = NULL;
		cow[i] = 0;
	}
	for ( i = 0; i < k; i++ )
	{
		scanf("%d",&d);
		cow[d]++;
	}
	int x,y;
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d",&x,&y);
		insert(x,y);
	}
	c = 0;
	for ( i = 1; i <= n; i++ )
	{
		if ( cow[i] != 0 )
			quee[c++] = i;
	}
	memset(v,0,sizeof(v));
	for ( i = 0; i < c; i++ )
	{
		memset(visit,0,sizeof(visit));
		visit[quee[i]] = 1;
		v[quee[i]] += cow[quee[i]];
		plus = cow[quee[i]];
		wa(quee[i]);
	}
	max = 0;
	for ( i = 1; i <= n; i++ )
	{
		if ( v[i] == k )
			max++;
	}
	cout<<max<<endl;
	return 0;
}