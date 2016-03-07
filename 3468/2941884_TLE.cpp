#include<iostream>
using namespace std;
__int64 a[300000];
int data[120000];
void init ( int i, int begin, int end )
{
	if ( begin == end )
	{
		a[i] = data[begin];
		return;
	}
	int mid = (begin+end)/2;
	init(i*2,begin,mid);
	init(i*2+1,mid+1,end);
	a[i] = __int64(a[i*2])+__int64(a[i*2+1]);
}
void updata ( int i, int begin, int end, int x, int y, int c )
{
	if ( begin == end )
	{
		a[i] += __int64(c);
		return;
	}
	a[i] += __int64((y-x+1)*c);
	int mid = (begin+end)/2;
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
__int64 gett ( int i, int begin, int end, int x, int y )
{
	if ( begin == x && end == y )
		return a[i];
	int mid = (begin+end)/2;
	if ( y <= mid )
		return gett(i*2,begin,mid,x,y);
	else if ( x > mid )
		return gett(i*2+1,mid+1,end,x,y);
	else
		return gett(i*2,begin,mid,x,mid)+gett(i*2+1,mid+1,end,mid+1,y);
}
int main ()
{
	int n,m,i;
	char ch;
	int x,y,c;
	while ( scanf("%d%d",&n,&m) != EOF )
	{
		for ( i = 1; i <= n; i++ )
			scanf("%d",&data[i]);
		init(1,1,n);
		for ( i = 0; i < m; i++ )
		{
			cin.ignore();
			scanf("%c",&ch);
			if ( ch == 'Q' )
			{
				scanf("%d%d",&x,&y);
				printf("%I64d\n",gett(1,1,n,x,y));
			}
			else
			{
				scanf("%d%d%d",&x,&y,&c);
				updata(1,1,n,x,y,c);
			}
		}
	}
	return 0;
}