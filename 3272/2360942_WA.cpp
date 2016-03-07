#include <iostream>
using namespace std;
int n,m;
int w[5010],in[5010],stack[5010];
bool visit[5010];
struct ac
{
	int v;
	ac *next;
	ac(){next=NULL;}
}*list[5100];
void insert ( int a, int b )
{
	ac *p = new ac;
	p->v = b;
	p->next = list[a];
	list[a] = p;
}
int main ()
{
	int i;
	int a,b;
	scanf("%d%d",&n,&m);
	for ( i = 0; i <= n; i++ )
	{
		list[i] = NULL;
		visit[i] = false;
		w[i] = 0;
		in[i] = 0;
	}
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d",&a,&b);
		in[b]++;
		insert(a,b);
	}
	for ( i = 1; i <= n; i++ )
	{
		if ( in[i] == 0 )
		{
			w[i] = 1;
			in[i] = 1;
			insert(0,i);
		}
	}
	a = 0;
	b = 1;
	stack[0] = 0;
	ac *p;
	while ( a < b )
	{
		i = stack[a];
		p = list[i];
		a++;
		while ( p != NULL )
		{
			in[p->v]--;
			w[p->v] += w[i];
			if ( in[p->v] == 0 )
			{
				stack[b] = p->v;
				b++;
			}
			p = p->next;
		}
	}
	cout<<w[n]<<endl;
	return 0;
}