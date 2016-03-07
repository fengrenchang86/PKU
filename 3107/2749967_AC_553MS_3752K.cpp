#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int v;
	ac *next;
}*list[50100];
int cmp ( const void*a, const void*b )
{
	return *(int*)a-*(int*)b;
}
void insert ( int a, int b )
{
	ac *p = new ac;
	p->v = b;
	p->next = list[a];
	list[a] = p;
}
int n,MAX=2000000000,end = 0;
int ans[50100];
bool visit[50100];
int dfs ( int node )
{
	int sum = 0;
	int max = 0;
	int k;
	ac *p = list[node];
	while ( p != NULL )
	{
		if ( visit[p->v] == false )
		{
			visit[p->v] = true;
			k = dfs(p->v);
			if ( k > max )
				max = k;
			sum += k;
		}
		p = p->next;
	}
	sum++;
	if ( max < n-sum )
		max = n-sum;
	if ( max < MAX )
	{
		end = 0;
		MAX = max;
		ans[end++] = node;
	}
	else if ( max == MAX )
		ans[end++] = node;
	return sum;
}
int main ()
{
	int i,a,b;
	scanf("%d",&n);
	for ( i = 1; i <= n; i++ )
	{
		list[i] = NULL;
		visit[i] = false;
	}
	for ( i = 0; i < n-1; i++ )
	{
		scanf("%d%d",&a,&b);
		insert(a,b);
		insert(b,a);
	}
	dfs(1);
	if ( end != 0 )
	{
		qsort(ans,end,sizeof(ans[0]),cmp);
		for ( i = 0; i < end; i++ )
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}