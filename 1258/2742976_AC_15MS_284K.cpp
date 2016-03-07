#include <iostream>
#include <stdlib.h>
using namespace std;
int father[110],n;
int c[110][110];
struct ac
{
	int x,y,len;
}side[10000];
int cmp ( const void*a, const void*b )
{
	struct ac *c = (ac*)a;
	struct ac *d = (ac*)b;
	return c->len - d->len;
}
int find (int v )
{
	while ( v != father[v] )
		v = father[v];
	return v;
}
void join ( int x, int y )
{
	father[find(x)] = find(y);
}
int mtree ( int k )
{
	int i,j=0;
	int t=0;
	for ( i = 0; i < n; i++ )
		father[i] = i;
	for ( i = 0; i < n-1; i++ )
	{
		while ( j < k )
		{
			if ( find(side[j].x) != find(side[j].y) )
			{
				join(side[j].x,side[j].y);
				t += c[side[j].x][side[j].y];
				break;
			}
			j++;
		}
	}
	return t;
}
int main ()
{
	int i,j,k;
	while ( cin>>n )
	{
		k =0 ;
		for ( i = 0; i <n ;i++ )
		{
			for (j  =0 ; j < n;j++ )
			{
				scanf("%d",&c[i][j]);
				if ( i < j )
				{
					side[k].x = i;
					side[k].y = j;
					side[k].len = c[i][j];
					k++;
				}
			}
		}
		qsort(side,k,sizeof(side[0]),cmp);
		printf("%d\n",mtree(k));
	}
	return 0;
}