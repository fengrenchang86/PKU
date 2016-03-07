#include <iostream>
using namespace std;
struct wf
{
	int color;
	wf(){color=2;}
}a[800000];
int pow[32];
int v[32];
void init ( int i, int begin, int end )
{
	a[i].color = 2;
	if ( begin == end )
		return;
	init ( i*2,begin,(begin+end)/2);
	init ( i*2+1,(begin+end)/2+1,end);
}
int g ( int col )
{
	int i = 31;
	int sum=0;
	while ( i >= 0 )
	{
		sum += col/pow[i];
		col %= pow[i];
		i--;
	}
	return sum;
}
int plus ( int a, int b )
{
	int sum = 0;
	int i = 31;
	while ( i >= 0 )
	{
		v[i] = a/pow[i];
		if ( v[i] == 0 )
			v[i] = b/pow[i];
		a %= pow[i];
		b %= pow[i];
		sum += v[i]*pow[i];
		i--;
	}
	return sum;
}
int plus ( int a, int b, int c )
{
	int sum = 0;
	int i = 31;
	while ( i >= 0 )
	{
		v[i] = a/pow[i];
		if ( v[i] == 0 )
			v[i] = b/pow[i];
		if ( v[i] == 0 )
			v[i] = c/pow[i];
		a %= pow[i];
		b %= pow[i];
		c %= pow[i];
		sum += v[i]*pow[i];
		i--;
	}
	return sum;
}
void find ( int i, int begin, int end, int x, int y, int &col )
{
	if ( begin == x && end == y )
	{
		col = a[i].color;
		return;
	}
	int mid = (begin+end)/2;
	if ( x > mid )
		find(i*2+1,mid+1,end,x,y,col);
	else if ( y <= mid )
		find(i*2,begin,mid,x,y,col);
	else
	{
		int j = 0;
		find(i*2,begin,mid,x,mid,col);
		find(i*2+1,mid+1,end,mid+1,y,j);
		col = plus(j,col);
	}
}
void update ( int i, int begin, int end, int x, int y, int newColor )
{
	if ( begin == end )
	{
		a[i].color = pow[newColor];
		return;
	}
	if ( begin == x && end == y )
	{
		a[i].color = pow[newColor];
		update(i*2,begin,(begin+end)/2,begin,(begin+end)/2,newColor);
		update(i*2+1,(begin+end)/2+1,end,(begin+end)/2+1,end,newColor);
		return;
	}
	int mid = (begin+end)/2;
	int col=0,j=0;
	if ( begin <= x-1 )
		find(i,begin,end,begin,x-1,col);
	if ( y+1 <= end )
		find(i,begin,end,y+1,end,j);
	a[i].color = plus(col,j,pow[newColor]);
	if ( y <= mid )
		update(i*2,begin,mid,x,y,newColor);
	else if ( x > mid )
		update(i*2+1,mid+1,end,x,y,newColor);
	else
	{
		update(i*2,begin,mid,x,mid,newColor);
		update(i*2+1,mid+1,end,mid+1,y,newColor);
	}
}
int main ()
{
	int i,x,y,z,k;
	int n,col,m;
	char ch;
	pow[0] = 1;
	for ( i = 1; i <= 31; i++ )
		pow[i] = pow[i-1]*2;
	scanf("%d%d%d",&n,&col,&m);
//	init(1,1,n);
	for ( i = 0; i < m; i++ )
	{
		scanf(" %c",&ch);
		if ( ch == 'C' )
		{
			scanf("%d%d%d",&x,&y,&k);
			if ( x > y )
			{
				z = x;
				x = y;
				y = z;
			}
			update(1,1,n,x,y,k);
		}
		else
		{
			col = 0;
			scanf("%d%d",&x,&y);
			if ( x > y )
			{
				z = x;
				x = y;
				y = z;
			}
			find(1,1,n,x,y,col);
			cout<<g(col)<<endl;
		}
	}
	return 0;
}