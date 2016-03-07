#include <iostream>
#include <math.h>
using namespace std;
const int max = 15000;
int l[max];
int a[max];
struct node
{
	short v;
	node *next;
	node()
	{
		next = NULL;
	}
}*table[max],*list[max];
void insert ( int x, int y )
{
	node *temp = new node;
	temp->v = y;
	node *p = table[x];
	if ( table[x] == NULL )
	{
		table[x] = temp;
		return;
	}
	if ( p->v > y )
	{
		temp->next = table[x];
		table[x] = temp;
	}
	else
	{
		while ( p->next != NULL )
		{
			if ( p->next->v >= y )
				break;
			p = p->next;
		}
		if ( p->next != NULL && p->next->v == y )
			return;
		temp->next = p->next;
		p->next = temp;
	}
}
void insert2 ( int x, int y )
{
	node *temp = new node;
	temp->v = y;
	node *p = list[x];
	if ( list[x] == NULL )
	{
		list[x] = temp;
		return;
	}
	if ( p->v > y )
	{
		temp->next = list[x];
		list[x] = temp;
	}
	else
	{
		while ( p->next != NULL )
		{
			if ( p->next->v >= y )
				break;
			p = p->next;
		}
		if ( p->next != NULL && p->next->v == y )
			return;
		temp->next = p->next;
		p->next = temp;
	}
}

void dfs ( int v , int count )
{
	node *p = table[v];
	while ( p != NULL )
	{
		if ( l[p->v] != count )
		{
			a[count]++;
			l[p->v] = count;
			dfs(p->v,count);
		}
		p = p->next;
	}
}

int main ()
{
	memset(l,0,sizeof(l));
	memset(a,0,sizeof(l));
	int n,m;
	int i,j,k;
	scanf("%d%d",&n,&m);
	int end = 0;
	for ( i = 1; i <= n; i++ )
	{
		insert(i,i);
		insert2(i,i);
	}
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d",&j,&k);
		insert2 (j,k);
		insert(k,j);
	}
	k = 0;
	for ( i = 1; i <= n; i++ )
		dfs(i,i);
	for ( i = 1; i <= n; i++ )
	{
//		printf("%d   %d\n",i,a[i]);
		if ( a[i] == n )
			k++;
	}
	cout<<k<<endl;
	return 0;
}