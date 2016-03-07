#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;
const int inf = 2000000000;
struct ac
{
	int v;
	int len;
	ac *next;
}*list[1200];
struct chang
{
	int id,w;
	bool operator()(const chang&m1, const chang&m2)
	{
		return m1.w > m2.w;
	}
};
priority_queue<chang,vector<chang>,chang>que;
bool visit[1200];
int dis[1200];
int father[1200];
int a[12000];
int N,M,T;
int count;
void test()
{
	chang p;
	while ( cin>>p.w )
		que.push(p);
	cout<<"OK"<<endl;
	while ( !que.empty())
	{
		p = que.top();
		que.pop();
		cout<<p.w<<endl;
	}
}
int cmp ( const void*a, const void*b )
{
	return *(int*)a - *(int*)b;
}
void insert ( int x, int y, int z )
{
	ac *p = new ac;
	p->len = z;
	p->v = y;
	p->next = list[x];
	list[x] = p;
}
void input ()
{
	scanf("%d%d%d",&N,&M,&T);
	int i,j,x,y,z;
	for ( i = 0; i <= N; i++ )
	{
		list[i] = NULL;
		dis[i] = inf;
		visit[i] = false;
	}
	a[0] = 0;
	for ( i = 0; i < M; i++ )
	{
		scanf("%d%d%d",&x,&y,&z);
		insert(x,y,z);
		insert(y,x,z);
		a[i+1] = z;
	}
	M++;
	qsort(a,M,sizeof(a[0]),cmp);
	j = 1;
	for ( i = 1; i < M; i++ )
	{
		if ( a[i] != a[i-1] )
			a[j++] = a[i];
	}
	M=j;
}
void dfs ( int node, int maxLen )
{
	visit[node] = true;
	father[node] = ::count;
	ac *p = list[node];
	while ( p != 0 )
	{
		if ( !visit[p->v] && p->len <= maxLen )
			dfs(p->v, maxLen);
		p = p->next;
	}
}
bool LoveHH ( int maxLen )
{
	memset(visit,false,sizeof(visit));
	int i;
	for ( i = 1; i <= N; i++ )
	{
		if ( !visit[i] )
		{
			::count = i;
			dfs(i, maxLen);
		}
	}
	int k;
	chang p,q;
	ac *temp;
	while ( !que.empty())
		que.pop();
	for ( i = 1; i <= N; i++ )
	{
		if ( father[i] == 1 )
		{
			p.w = 0;
			p.id = i;
			que.push(p);
			dis[i] = 0;
			visit[i] = true;
		}
		else
		{	
			dis[i] = inf;
			visit[i] =false;
		}
	}
	while ( !que.empty() )
	{
		p = que.top();
		que.pop();
		if ( dis[p.id] < p.w )
			continue;
		temp = list[p.id];
		while ( temp != 0 )
		{
			if ( father[p.id] == father[temp->v] )
				k = 0;
			else
				k = 1;
			if ( !visit[temp->v] && dis[temp->v] > dis[p.id] + k )
			{
				dis[temp->v] = dis[p.id]+k;
				q.id = temp->v;
				q.w = dis[temp->v];
				que.push(q);
			}
			temp = temp->next;
		}
	}
	if ( dis[N] <= T )
		return true;
	else
		return false;
}
void solve ()
{
	int nbegin = 0;
	int nend = M-1;
	int mid;
	while ( nbegin < nend )
	{
		mid = (nbegin+nend)/2;
		if ( LoveHH(a[mid]) == true )
			nend = mid;
		else
			nbegin = mid+1;
	}
	if ( LoveHH(a[nbegin]) == false )
		printf("-1\n");
	else
		printf("%d\n",a[nbegin]);
}
int main ()
{
	input();
	solve();
	return 0;
}