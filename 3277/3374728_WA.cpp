#pragma warning(disable:4786)
#include <iostream>
#include <stdlib.h>
#include <map>
using namespace std;
const int MAXN = 81000;
map<int,bool>use;
struct ac
{
	int x,y,h;
}a[41000];
struct tree
{
	__int64 area;
	int cover;
	int maxh;
}t[320000];
int b[MAXN];
int c[MAXN];
int n,m;
int cmp ( const void*a, const void*b )
{
	return *(int*)a-*(int*)b;
}
int Find ( int x )
{
	int begin = 0,end = m-1, mid=(begin+end)/2;
	while ( begin < end )
	{
		if ( b[mid] < x )
			begin = mid+1;
		else if ( b[mid] > x )
			end = mid;
		else
			return mid;
		mid = (begin+end)/2;
	}
	return mid;
}
void init ( int i, int begin, int end )
{
	if ( end-begin == 1 )
	{
		t[i].cover = 0;
		t[i].maxh = 0;
		t[i].area = 0;
		return;
	}
	int mid = (begin+end)/2;
	init(i*2,begin,mid);
	init(i*2+1,mid,end);
}
void update ( int i, int begin, int end, int x, int y, int high )
{
	int mid = (begin+end)/2;
	if ( begin == x && end == y )
	{
		if ( high >= t[i].maxh )
		{
			t[i].maxh = high;
			t[i].area = high*__int64(b[end]-b[begin]);
			t[i].cover = high;
		}
		return;
	}
	if ( t[i].cover != 0 )
	{
		t[i*2].cover = t[i].cover;
		t[i*2+1].cover = t[i].cover;
		t[i*2].area = t[i*2].cover*__int64(b[mid]-b[begin]);
		t[i*2+1].area = t[i*2+1].cover*__int64(b[end]-b[mid]);
		t[i*2].maxh = t[i].cover;
		t[i*2+1].maxh = t[i].cover;
		t[i].cover = 0;
	}
	if ( y <= mid )
		update(i*2,begin,mid,x,y,high);
	else if ( x >= mid )
		update(i*2+1,mid,end,x,y,high);
	else
	{
		update(i*2,begin,mid,x,mid,high);
		update(i*2+1,mid,end,mid,y,high);
	}
	t[i].area = t[i*2].area+t[i*2+1].area;
	t[i].maxh = t[i*2].maxh > t[i*2+1].maxh ? t[i*2].maxh:t[i*2+1].maxh;
}
int main ()
{
	int i;
	m = 0;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].h);
		if ( use[a[i].x] == false )
		{
			use[a[i].x] = true;
			b[m++] = a[i].x;
		}
		if ( use[a[i].y] == false )
		{
			use[a[i].y] = true;
			b[m++] = a[i].y;
		}
	}
	qsort(b,m,sizeof(b[0]),cmp);
	init(1,0,m-1);
	for ( i = 0; i < n; i++ )
	{
		a[i].x = Find(a[i].x);
		a[i].y = Find(a[i].y);
		update(1,0,m-1,a[i].x,a[i].y,a[i].h);
	}
	printf("%I64d\n",t[1].area);
	return 0;
}
