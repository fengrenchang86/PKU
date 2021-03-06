#include <iostream>
#include <math.h>
using namespace std;
const int max = 15000;
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
int main ()
{
	int n,m;
	int i,j,k;
	scanf("%d%d",&n,&m);
	int end = 0;
	int *a = new int[n+1];
	int *h = new int[n+1];
	for ( i = 1; i <= n; i++ )
	{
		insert(i,i);
		insert2(i,i);
		a[i] = h[i] = 0;
	}
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d",&j,&k);
		insert2 (j,k);
		insert(k,j);
	}
	k = 0;
	node *p,*q;
	j = sqrt(n);
	j++;
	while ( j-- >= 0 )
	{
	for ( i = 1; i <= n; i++ )
	{
		p = table[i];
		while ( p != NULL )
		{
			q = list[i];
			while ( q != NULL )
			{
	//			insert2(p->v,q->v);
				insert(q->v,p->v);
				q = q->next;
			}
			p = p->next;
		}
	}
	}
	k = 0;
	for ( i = 1; i <= n; i++ )
	{
		p = table[i];
		while ( p != NULL )
		{
			if ( h[p->v] != i )
			{
				h[p->v] = i;
				a[i]++;
			}
			p = p->next;
		}
		if ( a[i] == n )
			k++;
	}
	cout<<k<<endl;
	return 0;
}