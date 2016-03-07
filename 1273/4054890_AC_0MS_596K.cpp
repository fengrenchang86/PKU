#include <iostream>
using namespace std;
const int acMax = 320;
int f[acMax][acMax];//流量
int w[acMax];//dij用的
int pre[acMax];//路径中的上一个点
int path[acMax];//存储路径
int Len;//路径长度
bool visit[acMax];
struct node
{
	int v;
	node *next;
}*list[acMax];
void insert ( int x, int y )
{
	node *p = new node;
	p->v = y;
	p->next = list[x];
	list[x] = p;
}
void init ( int n )
{
	int i,j;
	for ( i = 0; i <= n; i++ )
		for ( j = 0; j <= n; j++ )
			f[i][j] = 0;
	for ( i = 0; i <= n; i++ )
		list[i] = NULL;
}
void init_dij( int n )
{
	int i;
	for ( i = 0; i <= n; i++ )
	{
		w[i] = 2000000000;
		visit[i] = false;
	}
	pre[1] = -1;
}
int acMinStream ( int n )
{
	int acMin = 2000000000;
	int j = n;
	int i = 1;
	path[0] = n;
	while ( pre[n] != -1 )
	{
		path[i++] = pre[n];
		if ( f[pre[n]][n] < acMin )
			acMin = f[pre[n]][n];
		n = pre[n];
	}
	n = j;
	while ( pre[n] != -1 )
	{
		f[pre[n]][n] -= acMin;
		f[n][pre[n]] += acMin;
		n = pre[n];
	}
	return acMin;
}
int dij ( int n )
{
	init_dij(n);
	int i,j,k,acMin;
	node *p = list[1];
	while ( p != NULL )
	{
		if ( f[1][p->v] > 0 )
		{
			w[p->v] = 1;
			pre[p->v] = 1;
		}
		p = p->next;
	}
	visit[1] = true;
	for ( i = 1; i < n; i++ )
	{
		acMin = 2000000000;
		for ( j = 2; j <= n; j++ )
		{
			if ( visit[j] == false && w[j] < acMin )
			{
				acMin = w[j];
				k = j;
			}
		}
		if ( acMin == 2000000000 )
			return 0;
		visit[k] = true;
		p = list[k];
		while ( p != NULL )
		{
			if ( visit[p->v] == false && f[k][p->v] > 0 && w[p->v] > w[k]+1 )
			{
				w[p->v] = w[k]+1;
				pre[p->v] = k;
			}
			p = p->next;
		}
	}
	if ( w[n] == 2000000000 )
		return 0;
	else
		acMin = acMinStream(n);
	return acMin;
}
int main ()
{
	int m,n,i,x,y,len,sum;
	while ( scanf("%d%d",&m,&n) != EOF )
	{
		init(n); 
		sum = 0;
		for ( i = 0; i < m; i++ )
		{
			scanf("%d%d%d",&x,&y,&len);
			insert(x,y);
			insert(y,x);
			f[x][y] += len;
		}
		while ( 1 )
		{
			i = dij(n);
			if ( i == 0 )
				break;
			sum += i;
		}
		cout<<sum<<endl;
	}
	return 0;
}

