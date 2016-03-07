#include <iostream>
using namespace std;
int m,n;
class ac
{
public:
	int node;
	ac *next;
}*list[100010];
void insert ( int a, int b )
{
	ac *p = new ac;
	p->node = a;
	p->next = list[b];
	list[b] = p;
}
int max;
int prov[100010];
int w[100010];
int in[100010];
int sav[100010];
bool first[100010];
int stack[1000100];
void dfs ( int node )
{
	int begin = 0;
	stack[0] = node;
	int end = 1;
	int point;
	ac *p;
	while ( begin < end )
	{
		point = stack[begin++];
		p = list[point];
		while ( p != NULL )
		{
			in[p->node]--;
			if (w[point] + prov[p->node] > w[p->node])
				w[p->node] = w[point]+prov[p->node];
			if ( in[p->node] == 0 )
			{
				stack[end++] = p->node;
				if ( list[p->node] == NULL && w[p->node] > max )
					max = w[p->node];
			}
			p = p->next;
		}
	}
}
int main ()
{
	int i,x,y;
	while ( scanf("%d%d",&n,&m ) !=EOF )
	{
		list[0] = NULL;
		for ( i = 1; i <= n; i++ )
		{
			scanf("%d",&prov[i]);
			first[i] = false;
			list[i] = NULL;
			in[i] = 0;
			w[i] = -2100000000;
		}
		for ( i = 0; i < m; i++ )
		{
			scanf("%d%d",&x,&y);
			insert(y,x);
			in[y] ++;
			first[y] = true;
		}
		max = -2100000000;
		w[0] = 0;
		for ( i = 1; i <= n; i++ )
		{
			if ( first[i] == false )
			{
				in[i]++;
				insert(i,0);
			}
		}
		dfs(0);
		printf("%d\n",(max));
	}
	return 0;
}