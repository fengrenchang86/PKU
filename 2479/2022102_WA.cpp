#include<iostream>
using namespace std;
int maxsum ( int a[], int left, int right, int &x, int &y )
{
	int sum = 0;
	x = y = left;
	if ( left == right )
	{
		if ( a[left] > 0 )
		{
			sum = a[left];
			x = y = left;
		}
		else
			sum = 0;
	}
	else
	{
		int lx,ly,rx,ry;
		int center = (left+right)/2;
		int leftsum = maxsum(a,left,center,lx, ly);
		int rightsum = maxsum(a,center+1,right,rx,ry);
		int s1 = -500000;
		int lefts = 0;
		for ( int i = center; i >= left; i-- )
		{
			lefts += a[i];
			if ( lefts > s1 )
			{
				s1 = lefts;
				x = i;
			}
		}
		int s2 = -500000;
		int rights = 0;
		for ( int j = center +1; j <= right; j++ )
		{
			rights += a[j];
			if ( rights > s2 )
			{
				s2 = rights;
				y = j;
			}
		}
		sum = s1+s2;
		bool g = true;
		if ( sum < leftsum && ly-lx >= 1)
		{
			g = false;
			sum = leftsum;
			x = lx;
			y = ly;
		}
		if ( sum < rightsum && ry-rx >= 1)
		{
			g = false;
			sum = rightsum;
			x = rx;
			y = ry;
		}
	}
	return sum;
}

int main ()
{
	int a[50010];
	int testcase,it;
	int sum;
	int min;
	int n,i;
	int begin , end;
	scanf("%d",&testcase);
	for ( it = 0; it < testcase; it++ )
	{
		sum = 0;
		min = 0;
		scanf("%d",&n);
		for ( i = 0; i < n; i++ )
			scanf("%d",&a[i]);
		sum = maxsum(a,0,n-1,begin,end);
//		printf("left = %d right = %d\n",begin,end);
		if ( end-begin > 1 )
		for ( i = begin; i <= end; i++ )
		{
			if ( a[i] < min)
			{
				min = a[i];
			}
		}
		sum -= min;
		printf("%d\n",sum);
	}
	return 1;
}