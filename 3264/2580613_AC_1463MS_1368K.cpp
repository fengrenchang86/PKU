#include<iostream>
using namespace std;
struct ac
{
	int min,max;
}v[320000];
int a[50100];
void init ( int i, int begin, int end )
{
	if ( begin == end )
	{
		v[i].max = v[i].min = a[begin];
		return;
	}
	int mid = (begin+end)/2;
	init(i*2,begin,mid);
	init(i*2+1,mid+1,end);
	v[i].min = v[i*2].min<v[i*2+1].min ? v[i*2].min:v[i*2+1].min;
	v[i].max = v[i*2].max>v[i*2+1].max ? v[i*2].max:v[i*2+1].max;
}
void f ( int i, int begin, int end, int x, int y ,int &min, int &max) 
{
	if ( x == begin && y == end )
	{
		min = v[i].min;
		max = v[i].max;
		return;
	}
	int mid = (begin+end)/2;
	int min1,min2,max1,max2;
	if ( x > mid )
	{
		f(i*2+1,mid+1,end,x,y,min1,max1);
		min = min1;
		max = max1;
	}
	else if ( y <= mid )
	{
		f(i*2,begin,mid,x,y,min2,max2);
		min = min2;
		max = max2;
	}
	else
	{
		f(i*2,begin,mid,x,mid,min1,max1);
		f(i*2+1,mid+1,end,mid+1,y,min2,max2);
		min = min1<min2?min1:min2;
		max = max1>max2?max1:max2;
	}
}
int main ()
{
	int i,n,q,min,max;
	int begin,end;
	scanf("%d%d",&n,&q);
	for ( i = 1; i <= n; i++ )
		scanf("%d",&a[i]);
	init(1,1,n);
	for ( i = 0; i < q; i++ )
	{
		scanf("%d%d",&begin,&end);
		f(1,1,n,begin,end,min,max);
		printf("%d\n",max-min);
	}
	return 0;
}