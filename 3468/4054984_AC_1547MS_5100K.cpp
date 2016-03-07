#include <iostream>
using namespace std;
struct ac
{
	__int64 value;
	__int64 cover;
}a[300000];
__int64 t[120000];
int n,m;
void init ( int i, int begin, int end )
{
	a[i].cover = 0;
	if ( begin == end )
	{
		a[i].value = t[begin];
		return;
	}
	init ( i*2,begin,(begin+end)/2 );
	init ( i*2+1,(begin+end)/2+1,end);
	a[i].value = a[i*2].value+a[i*2+1].value;
}
void updata ( int i, int begin, int end, int x, int y, int c )
{
	if ( begin == x && end == y )
	{
		a[i].cover += c;
		return;
	}
	a[i].value += c*(y-x+1);
	int mid = (begin+end)/2;
	if ( a[i].cover != 0 )
	{
		a[i].value += a[i].cover*(end-begin+1);
		a[i*2].cover += a[i].cover;
		a[i*2+1].cover += a[i].cover;
		a[i].cover = 0;
	}
	if ( y <= mid )
		updata(i*2,begin,mid,x,y,c);
	else if ( x > mid )
		updata(i*2+1,mid+1,end,x,y,c);
	else
	{
		updata(i*2,begin,mid,x,mid,c);
		updata(i*2+1,mid+1,end,mid+1,y,c);
	}
}
__int64 get ( int i, int begin, int end, int x, int y )
{
	int mid = (begin+end)/2;
	if ( a[i].cover != 0 )
	{
		a[i].value += a[i].cover*(end-begin+1);
		if ( begin != end )
		{
			a[i*2].cover += a[i].cover;
			a[i*2+1].cover += a[i].cover;
		}
		a[i].cover = 0;
	}
	if ( begin == x && end == y  )
		return a[i].value;
	if ( y <= mid )
		return get(i*2,begin,mid,x,y);
	else if ( x > mid )
		return get(i*2+1,mid+1,end,x,y);
	else
		return get(i*2,begin,mid,x,mid)+get(i*2+1,mid+1,end,mid+1,y);
}
int main ()
{
	int i,x,y,c,j;
	char ch;
	scanf("%d%d",&n,&m);
	for ( i = 1; i <= n; i++ )
		scanf("%I64d",&t[i]);
	init(1,1,n);
	for ( i = 0; i < m; i++ )
	{
		scanf(" %c",&ch);
		if ( ch == 'Q' )
		{
			scanf("%d%d",&x,&y);
			if ( x > y )
			{
				j = x;
				x = y;
				y = j;
			}
			printf("%I64d\n",get(1,1,n,x,y));
		}
		else
		{
			scanf("%d%d%d",&x,&y,&c);
			if ( x > y )
			{
				j = x;
				x = y;
				y = j;
			}
			updata(1,1,n,x,y,c);
		}
	}
	return 0;
}