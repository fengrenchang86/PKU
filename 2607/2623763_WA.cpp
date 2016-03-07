#include <iostream>
using namespace std;
int w[510];
int station[510];
bool visit[510];
int n,m;
struct ac
{
	int v;
	int len;
	ac *next;
}*list[510];
void init ()
{
	int i;
	for ( i = 1; i <= n; i++ )
	{
		visit[i] =false;
		if ( station[i] == 0 )
			w[i] = 2000000000;
		else
			w[i] = 0;
	}
}
void insert ( int x, int y, int len )
{
	ac *p = new ac;
	p->v = y;
	p->len = len;
	p->next = list[x];
	list[x] = p;
}
int main ()
{
	int i,j,k,d,x,y,len,pos,min,sum,ans=2000000000;
	ac *p;
	scanf("%d%d",&m,&n);
	for ( i = 1; i <= n; i++ )
	{
		list[i] = NULL;
		station[i] = 0;
	}
	for ( i = 0; i < m; i++ )
	{
		scanf("%d",&d);
		station[d] = 1;
	}
	while ( scanf("%d%d%d",&x,&y,&len) != EOF )
	{
		insert(x,y,len);
		insert(y,x,len);
	}
	for ( i = 1; i <= n; i++ )
	{
		if ( station[i] == 1 )
			continue;
		init();
		w[i] = 0;
		sum = 0;
		for ( j = 1; j <= n; j++ )
		{
			min = 2000000000;
			for ( k = 1; k <= n; k++ )
			{
				if ( visit[k] == false && w[k] < min )
				{
					min = w[k];
					pos = k;
				}
			}
			visit[pos] = true;
			sum += w[pos];
			p = list[pos];
			while ( p != NULL )
			{
				if ( visit[p->v] == false && w[p->v] > w[pos]+p->len )
					w[p->v] = w[pos]+p->len;
				p = p->next;
			}
		}
		if ( sum < ans )
		{
			ans = sum;
			d = i;
		}
	}
	cout<<d<<endl;
	return 0;
}