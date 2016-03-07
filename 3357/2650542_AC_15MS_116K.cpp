#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int x,y,len;
}a[500];
int pre[30];
int find ( int x )
{
	while ( x != pre[x] )
		x = pre[x];
	return x;
}
void join ( int x, int y )
{
	pre[find(x)] = find(y);
}
int cmp ( const void*a, const void*b )
{
	struct ac *c = (ac*)a;
	struct ac *d = (ac*)b;
	if ( c->len != d->len )
		return c->len - d->len;
	else if ( c->x != d->x )
		return c->x - d->x;
	else
		return c->y - d->y;
}
int main ()
{
	char ch;
	int i,j,tcase,it,n,len,k;
	scanf("%d",&tcase);
	for ( it = 1; it <= tcase; it++ )
	{
		scanf("%d",&n);
		for ( i = 0; i < n; i++ )
			pre[i] = i;
		k = 0;
		for ( i = 0; i < n; i++ )
		{
			scanf("%d",&a[k].len);
			for ( j = 1; j < n; j++ )
			{
				scanf("%c%d",&ch,&len);
				if ( i < j && len!=0)
				{
					a[k].x = i;
					a[k].y = j;
					a[k].len = len;
					k++;
				}
			}
		}
		qsort(a,k,sizeof(a[0]),cmp);
		printf("Case %d:\n",it);
		for ( i = 0; i < k; i++ )
		{
			if ( find(a[i].x) != find(a[i].y) )
			{
				join(a[i].x,a[i].y);
				printf("%c-%c %d\n",char(a[i].x+'A'),char(a[i].y+'A'),a[i].len);
			}
		}
	}
	return 0;
}