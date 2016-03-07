#include<iostream>
using namespace std;
int maxsum ( int a[], int left, int right, int &x, int &y )
{
	int sum = 0;
	x = y = left;
	if ( left == right )
	{
		sum = a[left];
	}
	else
	{
		int lx,ly,rx,ry;
		int center = (left+right)/2;
		int leftsum = maxsum(a,left,center,lx, ly);
		int rightsum = maxsum(a,center+1,right,rx,ry);
		int s1 = -50000000;
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
		int s2 = -50000000;
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
		if ( sum < leftsum )
		{
			g = false;
			sum = leftsum;
			x = lx;
			y = ly;
		}
		if ( sum < rightsum)
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
	int a[500100];
	int testcase,it;
	int sum;
	int sum1,sum2;
	int min;
	int n,i,j;
	int begin , end;
//	scanf("%d",&testcase);
//	for ( it = 0; it < testcase; it++ )
	while ( scanf("%d",&n) && n!=0 )
	{
		sum1 = sum2 = -50000000;
		sum = 0;
		min = -5000000;
		for ( i = 0; i < n; i++ )
			scanf("%d",&a[i]);
		if ( n == 2 )
		{
			printf("%d\n",a[0]+a[1]);
			continue;
		}
		sum = maxsum(a,0,n-1,begin,end);
//		printf("left = %d right = %d\n",begin,end);
		if ( begin > 0 )
		sum1 = maxsum(a,0,begin-1,i,j);
		if ( n-1 > end+1 )
		sum2 = maxsum(a,end+1,n-1,i,j);
		if ( sum1 < sum2 )
			sum1 = sum2;
		if ( end-begin > 1 )
		{
			for ( i = begin; i <= end; i++ )
			a[i] *= -1;
			min = maxsum(a,begin,end,i,j);
		}
		if ( sum1 > min )
			min = sum1;
		sum += min;
		printf("%d\n",sum);
	}
	return 1;
}