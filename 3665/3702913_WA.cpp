#include <iostream>
#include <queue>
using namespace std;
struct ac
{
	int R;
	int id;
	bool operator()(const ac&m1, const ac&m2 )
	{
		if ( m1.R != m2.R )
			return m2.R > m1.R;
		else
			return m1.id > m2.id;
	}
}a[1100];
bool visit[1100];
int w[1100];
priority_queue<ac,vector<ac>,ac>que;
void test ()
{
	int i;
	ac p;
	for ( i = 0; i < 5; i++ )
	{
		cin>>p.R>>p.id;
		que.push(p);
	}
	while ( !que.empty() )
	{
		p = que.top();
		que.pop();
		cout<<p.R<<" "<<p.id<<endl;
	}
}
void solve ()
{
	int n,t,i,x,avg,rest;
	ac p;
	scanf("%d%d",&n,&t);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d",&p.R);
		p.id = i;
		w[i] = p.R;
		que.push(p);
	}
	if ( n == 1 )
	{
		for ( i = 0; i < t; i++ )
			printf("1\n");
		return;
	}
	while ( t-- )
	{
		p = que.top();
		que.pop();
		avg = p.R/(n-1);
		rest = p.R%(n-1);
		printf("%d\n",p.id+1);
		w[p.id] = 0;
		while (	!que.empty() )
		{
			p = que.top();
			que.pop();
			w[p.id] = p.R;
			w[p.id] += avg;
			if ( rest > 0 )
			{
				w[p.id]++;
				rest--;
			}
		}
		for ( i = 0; i < n; i++ )
		{
			p.id = i;
			p.R = w[i];
			que.push(p);
		}
	}
}
int main ()
{
	solve();
	return 0;
}