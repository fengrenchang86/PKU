#include <iostream>
using namespace std;
int m,n;
class ac
{
public:
	int node;
	ac *next;
	ac(){next=NULL;}
}*list[100010];
void insert ( int a, int b )
{
	ac *p = new ac;
	p->node = a;
	p->next = list[b];
	list[b] = p;
}
int max;
bool visit[100010];
int prov[100010];
int w[100010];
int in[100010];
bool first[100010];
int stack[100000010];
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
				stack[end++] = p->node;
			p = p->next;
		}
	}
	if ( w[stack[end-1]] > max )
		max = w[stack[end-1]];
}
int main ()
{
	int i,x,y;
	int vis;
	while ( scanf("%d%d",&n,&m ) !=EOF )
	{
		for ( i = 1; i <= n; i++ )
		{
			scanf("%d",&prov[i]);
			visit[i] = first[i] = false;
			list[i] = NULL;
			in[i] = 0;
			w[i] = -1000000000;
		}
		for ( i = 0; i < m; i++ )
		{
			scanf("%d%d",&x,&y);
			insert(y,x);
			in[y] ++;
			first[y] = true;
		}
		vis = 1;
		max = -1000000000;
		while ( vis <= n )
		{
			if ( visit[vis] == false && first[vis] == false )
			{
				w[vis] = prov[vis];
				visit[vis] = true;
				dfs( vis );
			}
			vis++;
		}
		printf("%d\n",abs(max));
	}
	return 0;
}