#include <iostream>
using namespace std;
struct ac
{
	int v;
	ac *next;
}*list[10010];
int father[10010];
int number[10010];
bool visit[10010];
int sum;
void init ( int n )
{
	int i;
	for ( i = 1; i <= n; i++ )
	{
		list[i] = NULL;
		father[i] = i;
		visit[i] = false;
		sum = 0;
	}
}
void insert ( int a, int b )
{
	ac *p = new ac;
	p->v = b;
	p->next = list[a];
	list[a] = p;
}
void dfs ( int node )
{
	ac *p = list[node];
	while ( p != NULL )
	{
		if ( visit[p->v] == false )
		{
			visit[p->v] = true;
			dfs(p->v);
		}
		p = p->next;
	}
	sum += abs(number[node]-1);
	number[father[node]] += number[node]-1;
	number[node] = 1;
}
int main ()
{
	int n,i,j,v,num,d,s;
	while ( scanf("%d",&n) && n != 0 )
	{
		init(n);
		for ( i = 0; i < n; i++ )
		{
			scanf("%d%d",&v,&num);
			number[v] = num;
			scanf("%d",&d);
			for ( j = 0; j < d; j++ )
			{
				scanf("%d",&s);
				father[s] = v;
				insert(v,s);
			}
		}
		for ( i = 1; i <= n; i++ )
		{
			if ( father[i] == i )
				break;
		}
		dfs(i);
		cout<<sum<<endl;
	}
	return 0;
}