#include <iostream>
using namespace std;
class ac
{
public:
	int node;
	ac *next;
	ac(){next=NULL;}
}*list[1010],*LIST[1010];;
bool flag = false;
bool Exit = false;
int max = 0;
int pos;
int cow[1012];
int first[1012];
int in[1010];
int visit[1010];
int stack[1010];
int k,m,n;
void insert(int a, int b)
{
	ac *p = new ac;
	p->node = b;
	p->next = list[a];
	list[a] = p;
	p = new ac;
	p->node = a;
	p->next =LIST[b];
	LIST[b] = p;
}
int bfs()
{
	int point = 0;
	ac *p = list[0];
	ac *q;
	stack[0] = 0;
	int pos=0;
	int begin=0,end=1;
	while ( begin < end )
	{
		point = stack[begin];
		begin++;
		p = list[point];
		while ( p != NULL )
		{
			in[p->node]--;
			if ( in[p->node] == 0 )
			{
				stack[end] = p->node;
				end++;
				q = LIST[p->node];
				while ( q != NULL )
				{
					in[p->node] += in[q->node];
					q = q->next;
				}
				if ( cow[p->node] == 1 )
					in[p->node]++;
				if ( in[p->node] == k )
				{
					pos = p->node;
					return pos;
				}
			}
			p = p->next;
		}
	}
	return pos;
}
void dfs ( int node )
{
	ac *p = list[node];
	while ( p != NULL )
	{
		if ( visit[p->node] == 0 )
		{
			visit[p->node] = 1;
			max++;
			dfs(p->node);
		}
		p = p->next;
	}
}
int main ()
{
	int x,y;
	int i,d;
	scanf("%d%d%d",&k,&n,&m);
	for ( i = 0; i <= n; i++ )
	{
		cow[i] = 0;
		first[i] = 0;
		LIST[i] = list[i] = NULL;
		visit[i] = 0;
		in[i] = 0;
	}
	for ( i = 0; i < k; i++ )
	{
		scanf("%d",&d);
		cow[d] = 1;
	}
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d",&x,&y);
		insert(x,y);
		in[y]++;
	}
	in[0] = 0;
	for ( i = 1; i <= n; i++ )
	{
		if ( in[i] == 0 )
		{
			in[i] = 1;
			insert(0,i);
		}
	}
	int pos = bfs();
	visit[pos] = 1;
	max = 1;
	dfs(pos);
	cout<<max<<endl;
	return 0;
}