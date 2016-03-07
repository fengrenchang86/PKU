#include <iostream>
using namespace std;
const int max = 10100;
struct node
{
	short v;
	node *next;
	node()
	{
		next = NULL;
	}
}*table[max];
void insert ( int x, int y )
{
	node *temp = new node;
	temp->v = y;
	node *p = table[x];
	temp->next = table[x];
	table[x] = temp;
}
int main ()
{
	int n,m;
	int i,j,k;
	scanf("%d%d",&n,&m);
	int end = 0;
	int begin;
	int *que = new int[n+1];
	int *a = new int[n+1];
	for ( i = 1; i <= n; i++ )
	{
		insert(i,i);
		a[i] = 0;
	}
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d",&j,&k);
		insert ( k,j);
	}
	k = 0;
	node *p;
	for ( i = 1; i <= n; i++ )
	{
		a[0] = begin = end = 0;
		p = table[i];
		do
		{
			if ( a[p->v] != i )
			{
				a[p->v] = i;
				que[end++] = p->v;
				a[0]++;
			}
			p = p->next;
			while ( p == NULL )
			{
				if ( begin >= end  )
					break;
				p = table[que[begin++]];
			}
		}while ( begin < end || p != NULL);
		if ( a[0] == n )
			k++;
	}
	cout<<k<<endl;
	return 0;
}