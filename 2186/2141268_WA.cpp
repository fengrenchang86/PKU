#include <iostream>
using namespace std;
struct node
{
	node *next;
	int v;
	node(){next=NULL;}
}*table1[10101],*table2[10101];

void insert1 ( int a, int b )
{
	node *temp = new node;
	temp->v = b;
	temp->next = table1[a];
	table1[a] = temp;
}
void insert2 ( int a, int b )
{
	node *temp = new node;
	temp->v = a;
	temp->next = table2[b];
	table2[b] = temp;
}
int d[10101];
int f[10101];//finished time
int visit[10101];//a vex wheather visited or not
int count = 1;
void dfs ( int v )
{
	node *p = table1[v];
	while ( p != NULL )
	{
		if ( visit[p->v] == 0 )
		{
			d[p->v] = count++;
			visit[p->v] = 1;
			dfs(p->v);
			f[p->v] = count++;
		}
		p = p->next;
	}
}
void dfsF ( int v )
{
	node *p = table2[v];
	while ( p != NULL )
	{
		if ( visit[p->v] == 0 )
		{
			visit[p->v] = 1;
			dfsF(p->v);
			count++;
		}
		p = p->next;
	}
}
int t[10101];
int Qsort( int start, int end )
{
	int i;
	t[0] = t[start];
	i = 0; // i==0表示t[up]跟t[0]比较， i==1表示t[down]跟t[0]比较。
	int up = end;
	int down = start;
	while ( up != down )
	{
		if ( i == 0 && f[t[up]] <= f[t[0]] )
		{
			up--;
			continue;
		}
		if ( i == 0 && f[t[up]] > f[t[0]] )
		{
			t[down] = t[up];
			i = 1;
			down++;
			continue;
		}
		if ( i == 1 && f[t[down]] >= f[t[0]] )
		{
			down++;
			continue;
		}
		if ( i == 1 && f[t[down]] < f[t[0]] )
		{
			t[up] = t[down];
			i = 0;
			up--;
		}
	}
	t[down] = t[0];
	return down;
}
void qs ( int start, int end )		//递归实现快排
{
	int mid;
	if ( start < end )
	{
		mid = Qsort(start,end);
		qs ( start,mid-1);
		qs ( mid+1,end);
	}
}
int main ()
{
	int i;
	for ( i = 0; i < 10101; i++ )
	{
		table1[i] = NULL;
		table2[i] = NULL;
		d[i] = 0;
		f[i] = 0;
		visit[i] = 0;
	}
	int n,m;
	cin>>n>>m;
	int a,b;
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d",&a,&b);
		insert1(a,b);
		insert2(a,b);
	}
	for ( i = 1; i <= n; i++ )
	{
		if ( visit[i] == 0 )
		{
			d[i] = count++;
			visit[i] = 1;
			dfs(i);
			f[i] = count++;
		}
	}
	
	for ( i = 1; i <= n; i++ )
	{
		visit[i] = 0;
		t[i] = i;
	}
	qs(1,n);
//	for ( i = 1; i <= n; i++ )
//		cout<<"    "<<i<<" "<<f[t[i]]<<endl;
	for ( i = 1; i <= n; i++ )
	{
		if ( visit[t[i]] == 0 )
		{
			count = 1;
			visit[t[i]] = 1;
			dfsF(t[i]);
		}
	}
	printf("%d\n",count);
	return 0;
}