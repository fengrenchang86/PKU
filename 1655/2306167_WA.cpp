#include <iostream>
using namespace std;
class ac
{
public:
	int node;
	ac *next;
	ac(){next=NULL;}
}*list[20100];
int min;
int pos;
bool visit[20100];
int CurrentSize = 0;
int n;
void insert ( int x, int y )
{
	ac *t = new ac;
	t->node = y;
	t->next = list[x];
	list[x] = t;
}
void init (  )
{
	min = 99999999;
	CurrentSize = 0;
	for ( int i = 0; i < n; i++ )
	{
		visit[i] = false;
		list[i] = NULL;
	}
}
int dfs ( int node )
{
	visit[node] = true;
	int t=0,sum = 0;
	ac *p = list[node];
	int max = 0;
	while ( p != NULL )
	{
		if ( visit[p->node] == false )
		{
			t = dfs ( p->node );
			if ( t > max )
				max = t;
			sum += t;
		}
		p = p->next;
	}
	if ( n-sum-1 > t )
		t = n-sum-1;
	if ( t < min )
	{
		min = t;
		pos = node;
	}
	return sum+1;
}
int main ()
{
	int tcase;
	int i;
	int x,y;
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase--;
		scanf("%d",&n);
		init();
		for ( i = 0; i < n-1; i++ )
		{
			scanf("%d%d",&x,&y);
			insert(x,y);
			insert(y,x);
		}
		dfs(1);
		cout<<min<<" "<<pos<<endl;
	}
	return 0;
}