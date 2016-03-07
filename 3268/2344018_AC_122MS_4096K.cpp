#include <iostream>
using namespace std;
struct node
{
	int v;
	int len;
	node *next;
}*list[1200],*LIST[1200];
struct ac
{
	int w1,w2;
	bool v1,v2;
	ac(){w1=w2=1000000;v1=v2=false;
	}
}cow[1010];
int v[1010][1010];
int main ()
{
	int n,m,x,i,j;
	int a,b,len;
	scanf("%d%d%d",&n,&m,&x);
	for ( a = 1; a <= n; a++ )
		for ( b = a+1; b <= n; b++ )
			v[a][b] = v[b][a] = 1000000;
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d%d",&a,&b,&len);
		v[a][b] = len;
	}
	cow[x].v1 = true;
	for ( i = 1; i <= n; i++ )
	{
		cow[i].w1 = v[x][i];
	}
	for ( i = 1; i < n; i++ )
	{
		len = 1000000;
		for ( j = 1; j <= n; j++ )
		{
			if ( cow[j].v1 == false && cow[j].w1 < len )
			{
				len = cow[j].w1;
				a = j;
			}
		}
		cow[a].v1 = true;
		for ( j = 1; j <= n; j++ )
		{
			if ( a == j )
				continue;
			if ( cow[j].v1 == false && cow[j].w1 > cow[a].w1+v[a][j] )
				cow[j].w1 = cow[a].w1 + v[a][j];
		}
	}
	cow[x].v2 = true;
	for ( i = 1; i <= n; i++ )
	{
		cow[i].w2 = v[i][x];
	}
	for ( i = 1; i < n; i++ )
	{
		len = 1000000;
		for ( j = 1; j <= n; j++ )
		{
			if ( cow[j].v2 == false && cow[j].w2 < len )
			{
				len = cow[j].w2;
				a = j;
			}
		}
		cow[a].v2 = true;
		for ( j = 1; j <= n; j++ )
		{
			if ( a == j )
				continue;
			if ( cow[j].v2 == false && cow[j].w2 > cow[a].w2+v[j][a] )
				cow[j].w2 = cow[a].w2 + v[j][a];
		}
	}
	len = 0;
	for ( i = 1; i <= n; i++ )
	{
		if ( cow[i].w1 + cow[i].w2 > len && i != x)
			len = cow[i].w1 + cow[i].w2;
	}
	cout<<len<<endl;
	return 0;
}