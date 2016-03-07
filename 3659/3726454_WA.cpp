
#include <iostream>
using namespace std;
struct ac
{
	int v;
	ac *next;
}*list[11000];
struct hui
{
	int x,y,z;
	hui(){x=0;y=0;z=0;}
};
bool visit[11000];
int acmin ( int x, int y )
{
	if ( x == -1 )
		return y;
	else if ( y == -1 )
		return x;
	else
		return x<y?x:y;
}
int acmin ( int x, int y, int z )
{
	if ( y == -1 )
		return acmin(x,z);
	else
		return acmin(acmin(x,y),z);
}
void insert ( int x, int y )
{
	ac *p = new ac;
	p->v = y;
	p->next = list[x];
	list[x] = p;
}
hui chang(int node)
{
	visit[node] = true;
	int n=0,k,i=0;
	hui cc;
	ac *p = list[node];
	while ( p != NULL )
	{
		if ( !visit[p->v] )
			n++;
		p = p->next;
	}
	if ( n == 0 )
	{
		cc.x = 1;
		cc.y = 0;
		cc.z = -1;
		return cc;
	}
	hui *t = new hui[n];
	p = list[node];
	i = 0;
	while ( p != NULL )
	{
		if ( !visit[p->v] )
		{
			t[i] = chang(p->v);
			i++;
		}
		p = p->next;
	}
	k = 2000000000;
	for ( i = 0; i < n; i++ )
		cc.x += acmin(t[i].x,t[i].y,t[i].z);
	cc.x++;
	for ( i = 0; i < n; i++ )
	{
		cc.y += t[i].z;
		if ( t[i].z == -1 )
		{
			cc.y = -1;
			break;
		}
	}
	for ( i = 0; i < n; i++ )
	{
		k = acmin(k,t[i].x-acmin(t[i].x,t[i].z));
		cc.z += acmin(t[i].x,t[i].z);
	}
	if ( k >= 0 )
		cc.z += k;
	else
	{
		for ( i = 0; i < n; i++ )
		{
			k = t[i].x - acmin(t[i].x,t[i].z);
			if ( k < 0 )
				cc.z += k;
		}
	}
	delete []t;
	return cc;
}
void solve()
{
	int n,i,x,y;
	scanf("%d",&n);
	if ( n == 1 )
	{
		printf("1\n");
		return;
	}
	for ( i = 0; i <= n; i++ )
	{
		list[i] = NULL;
		visit[i] = false;
	}
	for ( i = 1; i < n; i++ )
	{
		scanf("%d%d",&x,&y);
		insert(x,y);
		insert(y,x);
	}
	hui acm = chang(1);
	printf("%d\n",acmin(acm.x,acm.y,acm.z));
}
int main ()
{
	solve();
	return 0;
}
