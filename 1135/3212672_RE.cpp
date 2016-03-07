#include <iostream>
using namespace std;
struct ac
{
	int v,len;
	ac *next;
}*list[510];
int n,m;
int w[510],ans[10];
bool visit[510];
void insert ( int x, int y, int l )
{
	ac *p = new ac;
	p->v = y;
	p->len = l;
	p->next = list[x];
	list[x] = p;
}
void dij ()
{
	ac *p;
	int i,j,k,tm;
	w[1] = 0;
	for ( i = 0; i < n; i++ )
	{
		tm = 2000000000;
		for ( j = 1; j <= n; j++ )
		{
			if ( w[j] == false && w[j] < tm )
			{
				tm = w[j];
				k = j;
			}
		}
		visit[k] = true;
		p = list[k];
		while ( p != NULL )
		{
			if ( visit[p->v] == false && w[p->v] > w[k]+p->len )
				w[p->v] = w[k]+p->len;
			p = p->next;
		}
	}
	tm = -1;
	for ( i = 1; i <= n; i++ )
	{
		if ( w[i] > tm )
		{
			tm = w[i];
			j = 0;
			ans[j] = i;
			j++;
		}
		else if ( w[i] == tm )
			ans[j++] = i;
	}
	if ( j == 1 )
	{
		printf("The last domino falls after %.1lf seconds, at key domino %d.\n\n",double(tm),ans[0]);
	}
	else
	{
		p = list[ans[0]];
		while ( p != NULL )
		{
			if ( p->v == ans[1])
				break;
			p = p->next;
		}
		printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n\n",tm+p->len/2.0,ans[0],ans[1]);
	}
}
void init()
{
	int i;
	int x,y,l;
	for ( i = 1; i <= n; i++ )
	{
		list[i] = NULL;
		w[i] = 2000000000;
		visit[i] = false;
	}
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d%d",&x,&y,&l);
		insert(x,y,l);
	}
}
int main ()
{
	int tc = 1;
	while ( scanf("%d%d",&n,&m) && (n+m) )
	{
		init();
		printf("System #%d\n",tc);
		tc++;
		dij();
	}
	return 0;
}