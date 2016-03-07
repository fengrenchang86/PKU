#include <iostream>
using namespace std;
const int max = 320;
int f[max][max];//流量
int w[max];//dij用的
int pre[max];//路径中的上一个点
int path[max];//存储路径
int Len;//路径长度
bool visit[max];
struct node
{
	int v;
	node *next;
}*list[max];
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
int MinStream ( int n )
{
	int min = 2000000000;
	int j = n;
	int i = 1;
	path[0] = n;
	while ( pre[n] != -1 )
	{
		path[i++] = pre[n];
		if ( f[pre[n]][n] < min )
			min = f[pre[n]][n];
		n = pre[n];
	}
	n = j;
	while ( pre[n] != -1 )
	{
		f[pre[n]][n] -= min;
		f[n][pre[n]] += min;
		n = pre[n];
	}
	return min;
}
int dij ( int n )
{
	init_dij(n);
	int i,j,k,min;
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
		min = 2000000000;
		for ( j = 2; j <= n; j++ )
		{
			if ( visit[j] == false && w[j] < min )
			{
				min = w[j];
				k = j;
			}
		}
		if ( min == 2000000000 )
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
		min = MinStream(n);
	return min;
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

