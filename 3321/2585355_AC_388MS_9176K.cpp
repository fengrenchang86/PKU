#include <iostream>
using namespace std;
struct ac
{
	int v;
	ac *next;
}*list[100100];
struct WF
{
	int begin,end;
}wf[100100];
int segTree[400400];
bool visit[100100];
bool Apple[100100];
int node[100100];
int count = 1;
void insert ( int a, int b )
{
	ac *p = new ac;
	p->v = b;
	p->next = list[a];
	list[a] = p;
}
void init ( int n )
{
	int i;
	for ( i = 1; i <= n; i++ )
	{
		list[i] = NULL;
		visit[i] = false;
		Apple[i] = true;
	}
}
void dfs ( int apple )
{
	visit[apple] = true;
	node[apple] = count;
	count++;
	wf[apple].begin = count;
	ac *p = list[apple];
	while ( p != NULL )
	{
		if ( visit[p->v] == false )
			dfs(p->v);
		p = p->next;
	}
	wf[apple].end = count-1;
}
void initTree ( int i, int begin, int end )
{
	if ( begin == end )
	{
		segTree[i] = 1;
		return;
	}
	initTree ( i*2, begin, (begin+end)/2);
	initTree ( i*2+1, (begin+end)/2+1, end );
	segTree[i] = segTree[i*2]+segTree[i*2+1];
}
void C ( int i, int begin, int end, int k, int add )
{
	segTree[i] += add;
	if ( begin == end )
		return;
	if ( k <= (begin+end)/2 )
		C ( i*2, begin,(begin+end)/2,k,add);
	else
		C (i*2+1,(begin+end)/2+1,end,k,add);
}
int Q ( int i, int begin, int end, int x, int y )
{
	if ( y < x )
		return 0;
	if ( begin == x && end == y )
		return segTree[i];
	int mid = (begin+end)/2;
	if ( x > mid )
		return Q(i*2+1,mid+1,end,x,y);
	else if ( y <= mid )
		return Q(i*2,begin,mid,x,y);
	else
		return Q(i*2,begin,mid,x,mid)+Q(i*2+1,mid+1,end,mid+1,y);
}
int main ()
{
	int i,m,n,a,b;
	char ch;
	scanf("%d",&n);
	init(n);
	for ( i = 1; i < n; i++ )
	{
		scanf("%d%d",&a,&b);
		insert(a,b);
		insert(b,a);
	}
	initTree(1,1,n);
	dfs(1);
	scanf("%d",&m);
	for ( i = 0; i < m; i++ )
	{
		scanf(" %c%d",&ch,&a);
		if ( Apple[a] == true )
			b = 1;
		else
			b = 0;
		if ( ch == 'Q' )
			printf("%d\n",Q(1,1,n,wf[a].begin,wf[a].end)+b);
		else
		{
			if ( Apple[a] == true )
			{
				Apple[a] = false;
				b = -1;
			}
			else
			{
				Apple[a] = true;
				b = 1;
			}
			a = node[a];
			C(1,1,n,a,b);
		}
	}
	return 0;
}
