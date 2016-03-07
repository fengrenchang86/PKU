#include <iostream>
using namespace std;
struct node
{
	node *next;
	int v;
	node(){next=NULL;}
}*table1[10101],*table2[10101];

void insert1 ( int a, int b )
{
	node *temp = new node;
	temp->v = b;
	temp->next = table1[a];
	table1[a] = temp;
}
void insert2 ( int a, int b )
{
	node *temp = new node;
	temp->v = a;
	temp->next = table1[b];
	table2[b] = temp;
}
int d[10101];
int f[10101];//finished time
int visit[10101];//a vex wheather visited or not
int count = 1;
void dfs ( int v )
{
	node *p = table1[v];
	while ( p != NULL )
	{
		if ( visit[p->v] == 0 )
		{
			d[p->v] = count++;
			visit[p->v] = 1;
			dfs(p->v);
			f[p->v] = count++;
		}
		p = p->next;
	}
}
int main ()
{
	int i;
	for ( i = 0; i < 10101; i++ )
	{
		table1[i] = NULL;
		table2[i] = NULL;
		d[i] = 0;
		f[i] = 0;
		visit[i] = 0;
	}
	int n,m;
	cin>>n>>m;
	int a,b;
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d",&a,&b);
		insert1(a,b);
//		insert2(a,b);
	}
	for ( i = 1; i <= n; i++ )
	{
		if ( visit[i] == 0 )
		{
			d[i] = count++;
			visit[i] = 1;
			dfs(i);
			f[i] = count++;
		}
	}
	a = 1;
	for ( i = 1; i <= n; i++ )
	{
		if ( f[i] < f[a] )
			a = i;
	}
//	for ( i = 1; i <= n; i++ )
//		printf("d[%d] = %d    f[%d] = %d\n",i,d[i],i,f[i]);
	count = 1;
	for ( i = 1; i <= n; i++ )
		d[i] = f[i] = visit[i] = 0;
	d[a] = count++;
	visit[a] = 1;
	dfs(a);
	f[a] = count++;
	printf("%d\n",(count-1)/2);
//	for ( i = 1; i <= n; i++ )
//		printf("d[%d] = %d    f[%d] = %d\n",i,d[i],i,f[i]);
	return 0;
}