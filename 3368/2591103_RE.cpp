#include <iostream>
using namespace std;
struct ac
{
	int left,right,max;
}v[50000];
int a[10010];
int MAX ( int a, int b )
{
	return a>b?a:b;
}
int MAX ( int a, int b, int c )
{
	return MAX (MAX(a,b),MAX(a,c));
}
void init ( int i, int begin, int end )
{
	if ( begin == end )
	{
		v[i].left = v[i].right = v[i].max = 1;
		return;
	}
	int mid = ( begin + end )/2;
	init ( i*2, begin, mid );
	init (i*2+1, mid+1,end );
	if ( a[mid] == a[mid+1] )
	{
		v[i].max = MAX(v[i*2].max,v[i*2+1].max,v[i*2].right+v[i*2+1].left);
		if ( a[begin] == a[mid+1] )
			v[i].left = v[i*2].left+v[i*2+1].left;
		else
			v[i].left = v[i*2].left;
		if ( a[end] == a[mid] )
			v[i].right = v[i*2].right+v[i*2+1].right;
		else
			v[i].right = v[i*2+1].right;
	}
	else
	{
		v[i].max = MAX(v[i*2].max,v[i*2+1].max);
		v[i].left = v[i*2].left;
		v[i].right = v[i*2+1].right;
	}
}
void go ( int i, int begin, int end, int x, int y, int &l, int &r ,int &max )
{
	if ( begin == x && end == y )
	{
		l = v[i].left;
		r = v[i].right;
		max = v[i].max;
		return;
	}
	int mid = (begin+end)/2;
	if ( x > mid )
		go ( i*2+1,mid+1,end,x,y,l,r,max );
	else if ( y <= mid )
		go (i*2,begin,mid,x,y,l,r,max);
	else
	{
		int l1,l2,r1,r2,max1,max2;
		go ( i*2, begin,mid,x,mid,l1,r1,max1);
		go (i*2+1,mid+1,end,mid+1,y,l2,r2,max2);
		if ( a[mid] == a[mid+1] )
		{
			max = MAX(max1,max2,r1+l2);
			if ( a[begin] == a[mid+1] )
				l = l1+l2;
			else
				l = l1;
			if ( a[end] == a[mid] )
				r = r1+r2;
			else
				r = r2;
		}
		else
		{
			max = MAX(max1,max2);
			l = l1;
			r = r2;
		}
	}
}
int main ()
{
	int i,n,m,x,y,l,r,max;
	while ( scanf("%d",&n)&&n!=0 )
	{
		scanf("%d",&m);
		for ( i = 1; i <= n; i++ )
			scanf("%d",&a[i]);
		init(1,1,n);
		for ( i = 0; i < m; i++ )
		{
			scanf("%d%d",&x,&y);
			go(1,1,n,x,y,l,r,max);
			cout<<max<<endl;
		}
	}
	return 0;
}