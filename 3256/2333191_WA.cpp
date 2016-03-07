#include <iostream>
#include <stdlib.h>
using namespace std;
int visit[1001];
int stack[1001];
int head = 0;
int cow[1001];
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
int dfs ( int node )
{
	ac *p = list[node];
	int count = 0;
	int x;
	while ( p != NULL )
	{
		if ( visit[p->node] == 0 )
		{
			visit[p->node] = 1;
			x = dfs(p->node);
			count += x;
			if ( cow[node] > 0 && x == 0 )
				stack[head++] = node;
		}
		p = p->next;
	}
	count += cow[node];
	return count;
}
int max = 0;
int pos;
bool flag ;
void DFS ( int node )
{
	ac *p = LIST[node];
	while ( p != NULL )
	{
		if ( visit[p->node] == 0 )
		{
			visit[p->node] = 1;
			DFS(p->node);
			max += cow[p->node];
		}
		p = p->next;
	}
}
int search ( int node )
{
	ac *p = list[node];
	int count = 0;
	int x;
	while ( p != NULL )
	{
		if ( visit[p->node] == 0 )
		{
			visit[p->node] = 1;
			x = search(p->node);
			if ( x > 0 )
				flag = true;
			if ( flag == true )
				return 1;
		}
		p = p->next;
	}
	count += cow[node];
	return count;
}
void find ( int node )
{
	ac *p = list[node];
	while ( p != NULL )
	{
		if ( visit[p->node] == 0 )
		{
			max++;
			visit[p->node] = 1;
			find(p->node);
		}
		p = p->next;
	}
}
int main ()
{
	int i,d,c=0;
	scanf("%d%d%d",&k,&n,&m);
	for ( i = 0; i <= n; i++ )
	{
		list[i] = LIST[i] = NULL;
		visit[i] = 0;
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
	i = d;
	visit[i] = 1;
	d = dfs(i);
	if ( d < k )
		DFS(i);
	if ( max + d < k )
		cout<<0<<endl;
	else
	{
		pos = stack[0];
		for ( i = 0; i < head; i++ )
		{
			flag = false;
			memset(visit,0,sizeof(visit));
			d = search(stack[i]);
			d-=cow[stack[i]];
			if ( d > 0 )
			{
				c++;
				pos = stack[i];
			}
		}
		if ( c > 1 )
			cout<<0<<endl;
		else
		{
			max = 1;
			memset(visit,0,sizeof(visit));
			visit[pos] = 1;
			find(pos);
			cout<<max<<endl;
		}
	}
	return 0;
}