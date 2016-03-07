#include <iostream>
using namespace std;
struct ac
{
	int v;
	ac *next;
}*list[60],*List[60];
bool visit[60];
int a[60];
int b[60];
int count;
void init( int n )
{
	int i;
	for ( i = 0; i <= n; i++ )
		visit[i] = false;
}
void insert ( int x, int y )
{
	ac*p = new ac;
	p->next = list[x];
	p->v = y;
	list[x] = p;
}
void Insert ( int y, int x )
{
	ac*p = new ac;
	p->next = List[x];
	p->v = y;
	List[x] = p;
}
void dfs ( int node )
{
	visit[node] = true;
	ac *p = list[node];
	while ( p != NULL )
	{
		if ( visit[p->v] == false )
			dfs(p->v);
		p = p->next;
	}
}
void Dfs ( int node )
{
	count++;
	visit[node] = true;
	ac *p = list[node];
	while ( p != NULL )
	{
		if ( visit[p->v] == false )
			Dfs(p->v);
		p = p->next;
	}
	p = List[node];
	while ( p != NULL )
	{
		if ( visit[p->v] == false )
			Dfs(p->v);
		p=p->next;
	}
}
int main ()
{
	int i,d,n,x=0,y=0;
	{
	for ( i = 0; i < 60; i++ )
	{
		list[i] = NULL;
		List[i] = NULL;
	}
	i = 0;
	while ( cin>>d && d != -1 )
	{
		insert(i,d);
		Insert(i,d);
		while ( cin>>d && d!= -2 )
		{
			insert(i,d);
			Insert(i,d);
		}
		i++;
	}
	n = i;
	for (i = 1; i < n; i++ )
	{
		a[i] = 0;
		b[i] = 0;
		init(n);
		visit[i] = true;
		dfs(0);
		if ( visit[n] == true )
		{
			a[i]++;
			continue;
		}
		x++;
		init(n);
		visit[i] = true;
		count = 0;
		Dfs(n);
		if ( count == n )
			b[i]++;
		else
			y++;
	}
	printf("%d",x);
	for ( i = 1; i < n; i++ )
		if ( a[i] == 0 )
			printf(" %d",i);
	printf("\n");
	printf("%d",y);
	for ( i = 1; i < n; i++ )
		if ( a[i] == 0 && b[i] == 0)
			printf(" %d",i);
		printf("\n");
	}
	return 0;
}