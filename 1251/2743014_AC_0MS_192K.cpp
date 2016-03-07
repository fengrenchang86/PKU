#include <iostream>
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
	char node,go;
	int num,len;
	while ( cin>>n && n != 0 )
	{
		for ( i = 0; i <n ;i++ )
			for (j  =0 ; j < n;j++ )
				c[i][j] = 2000000000;
		k = 0;
		for ( i = 0; i < n-1; i++ )
		{
			cin>>node>>num;
			for ( j = 0; j < num; j++ )
			{
				cin>>go>>len;
				c[node-'A'][go-'A'] = len;
				side[k].x = int(node-'A');
				side[k].y = int(go-'A');
				side[k].len = len;
				k++;
			}
		}
		qsort(side,k,sizeof(side[0]),cmp);
		cout<<mtree(k)<<endl;
	}
	return 0;
}
