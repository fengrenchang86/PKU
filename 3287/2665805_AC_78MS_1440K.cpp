#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int v;
	ac *next;
}*list[10010];
struct wa
{
	int data;
	int num;
}c[10010];
void insert ( int i, int key )
{
	ac *p = new ac;
	p->v = key;
	p->next = list[i];
	list[i] = p;
}
int cmp ( const void*a, const void *b )
{
	return *(int*)a-*(int*)b;
}
int cmp2 ( const void*a, const void*b )
{
	struct wa *c = (wa*)a;
	struct wa *d = (wa*)b;
	if ( c->num != d->num )
		return d->num - c->num;
	else
		return c->data - d->data;
}
int main ()
{
	int n,i,j,k,t,a[10010];
	while ( scanf("%d",&n) && n!=0 )
	{
		for ( i = 0; i < n; i++ )
		{
			scanf("%d",&a[i]);
			list[i] = NULL;
		}
		qsort(a,n,sizeof(a[0]),cmp);
		c[0].num = 1;
		c[0].data = a[0];
		k = 0;
		for ( i = 1; i < n; i++ )
		{
			if ( a[i] != a[i-1] )
			{
				k++;
				c[k].data = a[i];
				c[k].num = 1;
			}
			else
				c[k].num++;
		}
		qsort(c,k+1,sizeof(c[0]),cmp2);
		k = c[0].num;
		j = 0;
		t = 0;
		for ( i = 0; i < n; i++ )
		{
			if ( j == k )
				j = 0;
			if ( c[t].num == 0 )
				t++;
			c[t].num--;
			insert(j,c[t].data);
			j++;
		}
		printf("%d\n",k);
		for ( i = 0; i < k; i++ )
		{
			ac *p = list[i];
			printf("%d",p->v);
			p = p->next;
			while ( p != NULL )
			{
				printf(" %d",p->v);
				p = p->next;
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}