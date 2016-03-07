#include <iostream>
using namespace std;
class ac
{
public:
	int node;
	ac *next;
	ac(){next=NULL;}
}*list[1010];
bool flag = false;
bool Exit = false;
int max = 0;
int pos;
int cow[1012];
int first[1012];
int visit[1010];
void insert(int a, int b)
{
	ac *p = new ac;
	p->node = b;
	p->next = list[a];
	list[a] = p;
}
void DFS ( int node, int count , int k )
{
	if ( cow[node] == 1 )
		count++;
	if ( count == k )
	{
		flag = true;
		pos = node;
		return;
	}
	ac *p = list[node];
	while ( p != NULL )
	{
		DFS(p->node,count,k);
		if ( flag == true )
			return;
		p = p->next;
	}
}
int num = 1;
void DDD ( int node )
{
	ac *p = list[node];
	while ( p != NULL )
	{
		if ( visit[p->node] == 0 )
		{
			visit[p->node] = 1;
			num++;
		}
		DDD(p->node);
		p = p->next;
	}
}
void dfs ( int node, int count, int k, int number)
{
	if ( number > max )
		max = number;
	if ( flag == true )
		number++;
	else if ( cow[node] == 1 )
		count++;
	if ( count == k && flag == false )
	{
		flag = true;
		number++;
	}
	ac *p = list[node];
	int i;
	while ( p != NULL )
	{
		i = p->node;
		if ( visit[i] == 0 )
		{
			visit[i] = 1;
			dfs(p->node,count,k,number);
			if ( flag == true && cow[node] == 1 )
				Exit = true;
			if ( Exit == true )
				return;
			visit[i] = 0;
		}
		p = p->next;
	}
	if ( number > max )
		max = number;
}
int main ()
{
	int x,y;
	int k,n,m,i,d;
	scanf("%d%d%d",&k,&n,&m);
	for ( i = 0; i <= n; i++ )
	{
		cow[i] = 0;
		first[i] = 0;
		list[i] = NULL;
		visit[i] = 0;
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
		first[y] = 1;
	}
	for ( i = 1; i <= n; i++ )
	{
		if ( first[i] == 0 )
		{
			flag = false;
			Exit =false;
			DFS(i,0,k);
			if ( flag == true )
				break;
		}
	}
	DDD(pos);
	cout<<num<<endl;
	return 0;
}