#include <iostream>
using namespace std;
struct ac
{
	bool full;
	int color;
}a[500000];
void insert ( int i, int begin, int end, int x, int y, int color )
{
	if ( begin==x && end == y )
	{
		a[i].full = true;
		a[i].color = 1<<color;
		return;
	}
	int mid = (begin+end)/2;
	if ( y <= mid )
		insert(i*2,begin,mid,x,y,color);
	else if ( x > mid )
		insert(i*2+1,mid+1,end,x,y,color);
	else
	{
		insert(i*2,begin,mid,x,mid,color);
		insert(i*2+1,mid+1,end,mid+1,y,color);
	}
	a[i].color = a[i*2].color | a[i*2+1].color;
}
int serch ( int i, int begin, int end, int x, int y )
{
	if ( a[i].full == true )
		return a[i].color;
	if ( begin==x && end == y )
		return a[i].color;
	int mid = (begin+end)/2;
	if ( y <= mid )
		return serch(i*2,begin,mid,x,y);
	else if ( x > mid )
		return serch(i*2+1,mid+1,end,x,y);
	else
	{
		return serch(i*2,begin,mid,x,mid)|serch(i*2+1,mid+1,end,mid+1,y);
	}
}
int count ( int t )
{
	int k = 1<<30;
	int c = 0;
	while ( k != 1 )
	{
		c += t/k;
		t%=k;
		k/=2;
	}
	return c;
}
int main ()
{
	int n,t,o,i;
	int x,y,c;
	char oper;
	scanf("%d%d%d",&n,&t,&o);
	for ( i = 1; i < 500000; i++ )
	{
		a[i].color = 2;
		a[i].full = false;
	}
	for ( i = 0; i < o; i++ )
	{
		scanf(" %c",&oper);
		if ( oper == 'C' )
		{
			scanf("%d%d%d",&x,&y,&c);
			if ( x > y )
			{
				t = x;
				x = y;
				y = t;
			}
			insert(1,1,n,x,y,c);
		}
		else
		{
			scanf("%d%d",&x,&y);
			if ( x > y )
			{
				t = x;
				x = y;
				y = t;
			}
			t = serch(1,1,n,x,y);
			t = count(t);
			cout<<t<<endl;
		}
	}
	return 0;
}