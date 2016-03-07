#include <iostream>
using namespace std;
struct ac
{
	int v;
	ac *next;
}*list[11000];
bool visit[11000];
int w[11000];
int n;
void init ()
{
	int i;
	for ( i = 0; i <= n; i++ )
	{
		list[i] = NULL;
		visit[i] = false;
		w[i] = 0;
	}
}
void insert ( int x, int y )
{
	ac *p = new ac;
	p->v = y;
	p->next = list[x];
	list[x] = p;
}
void input ()
{
	scanf("%d",&n);
	init();
	int i,x,y;
	for ( i = 1; i < n; i++ )
	{
		scanf("%d%d",&x,&y);
		insert(x,y);
		insert(y,x);
	}
}
int dfs ( int v )
{
	visit[v] = true;
	ac *p = list[v];
	int j,k=0,sum=0;
	while ( p != NULL )
	{
		if ( visit[p->v] == false )
		{
			j = dfs(p->v);
			sum += j;
			if ( j > k )
				k = j;
		}
		p = p->next;
	}
	if ( n-1-sum > k )
		k = n-1-sum;
	w[v] = k;
	return sum+1;
}
void solve ()
{
	int i,k=n/2;
	dfs(1);
	for ( i = 1; i <= n; i++ )
	{
		if ( w[i] <= k )
			printf("%d\n",i);
	}
}
int main ()
{
	input();
	solve();
	return 0;
}