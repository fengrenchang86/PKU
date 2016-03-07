#include<iostream>
using namespace std;
int father[210000];
int size[210000];
int a[5000000];
int n;
int getfather(int x)
{
	while( x!=father[x])
		x = father[x];
	return x;
}
void init()
{
	int i;
	for( i = 0; i < n; i++)
	{
		father[i] = i;
		size[i] = 1;
	}
	for ( i = 0; i < 5000000; i++)
		a[i] = 0;
}
void Begin( int i, int x, int y)
{
	a[i] += n;
	if( x == y )
		return;
	Begin(i*2,x,(x+y)/2);
}
void insert ( int i, int x, int y, int key)
{
	a[i]++;
	if( x == y )
		return;
	int mid = (x+y)/2;
	if( key <= mid )
		insert(i*2,x,mid,key);
	else
		insert(i*2+1,mid+1,y,key);
}
void del ( int i, int x, int y, int key )
{
	a[i]--;
	if( x== y)
		return;
	int mid = (x+y)/2;
	if ( key <= mid)
		del(i*2,x,mid,key);
	else
		del(i*2+1,mid+1,y,key);
}
int Findk ( int i, int x, int y, int k )
{
	if( x == y )
		return x;
	if( a[i*2+1] >= k )
		return Findk(i*2+1,(x+y)/2+1,y,k);
	else
		return Findk(i*2,x,(x+y)/2,k-a[i*2+1]);
}
void solve()
{
	int m;
	int i,x,y,op;
	int fx,fy;
	scanf("%d%d",&n,&m);
	init();
	Begin(1,1,n);;
	for( i = 0; i < m; i++)
	{
		scanf("%d",&op);
		if(op == 0)
		{
			scanf("%d%d",&x,&y);
			fx = getfather(x);
			fy = getfather(y);
			if(fx != fy)
			{
				del(1,1,n,size[fx]);
				del(1,1,n,size[fy]);
				father[fx] = fy;
				size[fx] += size[fy];
				size[fy] = size[fx];
				insert(1,1,n,size[fy]);
			}
		}
		else
		{
			scanf("%d",&x);
			y = Findk(1,1,n,x);
			printf("%d\n",y);
		}
	}
}
int main()
{
	solve();
	return 0;
}