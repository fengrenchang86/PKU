#include<iostream>
using namespace std;
int begin,end;
int maxsum ( int a[], int left, int right )
{
	int sum = 0;
	if ( left == right )
	{
		if ( a[left] > 0 )
		{
			sum = a[left];
			begin = left;
			end = left;
		}
		else
			sum = 0;
	}
	else
	{
		int center = (left+right)/2;
		int leftsum = maxsum(a,left,center);
		int rightsum = maxsum(a,center+1,right);
		int s1 = 0;
		int lefts = 0;
		for ( int i = center; i >= left; i-- )
		{
			lefts += a[i];
			if ( lefts > s1 )
			{
				s1 = lefts;
				begin = i;
			}
		}
		int s2 = 0;
		int rights = 0;
		for ( int j = center +1; j <= right; j++ )
		{
			rights += a[j];
			if ( rights > s2 )
			{
				s2 = rights;
				end = j;
			}
		}
		sum = s1+s2;
		if ( sum < leftsum )
		{
			sum = leftsum;
	//		begin = left;
		}
		if ( sum < rightsum )
		{
			sum = rightsum;
	//		end = right;
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
	int n,i,j;
	scanf("%d",&testcase);
	for ( it = 0; it < testcase; it++ )
	{
		sum = 0;
		min = 300000;
		scanf("%d",&n);
		for ( i = 0; i < n; i++ )
			scanf("%d",&a[i]);
		sum = maxsum(a,0,n-1);
//		printf("left = %d right = %d\n",begin,end);
		for ( i = begin; i < end; i++ )
		{
			if ( a[i] < min && a[i] < 0 )
			{
				j = i;
				min = a[i];
			}
		}
		if ( min != 300000 )
			sum -= min;
		printf("%d\n",sum);
	}
	return 1;
}