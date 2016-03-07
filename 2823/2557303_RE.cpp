#include <iostream>
using namespace std;
struct ac
{
	int min,max;
}a[80000000];
int t[1001000];
void init ( int begin, int end, int i )
{
	if ( begin == end )
	{
		a[i].min = t[begin];
		a[i].max = t[begin];
		return;
	}
	else if ( end-begin==1 )
	{
		a[i].max = t[begin]>t[end]?t[begin]:t[end];
		a[i].min = t[begin]<t[end]?t[begin]:t[end];
		return;
	}
	init ( begin, (begin+end)/2, i*2);
	init ( (begin+end)/2,end,i*2+1);
	a[i].max = a[i*2].max>a[i*2+1].max?a[i*2].max:a[i*2+1].max;
	a[i].min = a[i*2].min<a[i*2+1].min?a[i*2].min:a[i*2+1].min;
}
void find ( int left, int right, int begin ,int end, int i, int &min, int &max)
{
	if ( left == begin && right == end )
	{
		min = a[i].min;
		max = a[i].max;
		return;
	}
	int mid = (left+right)/2;
	int x,y,xx,yy;
	if ( begin >= mid )
	{
		find(mid,right,begin,end,i*2+1,x,y);
		min = x;
		max = y;
	}
	else if ( end <= mid )
	{
		find(left,mid,begin,end,i*2,x,y);
		min = x;
		max = y;
	}
	else
	{
		find(left,mid,begin,mid,i*2,x,y);
		find(mid,right,mid,end,i*2+1,xx,yy);
		min = x<xx?x:xx;
		max = y>yy?y:yy;
	}
}
int main ()
{
	int n,i,k,j=0;
	int x[1000100];
	int y[1000100];
	scanf("%d%d",&n,&k);
	for ( i = 1; i <= n; i++ )
		scanf("%d",&t[i]);
	init(1,n,1);
	for ( i = 1; i+k-1<=n; i++ )
	{
		find(1,n,i,i+k-1,1,x[j],y[j]);
		printf("%d ",x[j]);
		j++;
	}
	printf("\n");
	j = 0;
	for ( i = 1; i+k-1 <= n; i++ )
		printf("%d ",y[j++]);
	printf("\n");
	return 0;
}