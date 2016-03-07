#include<iostream>
using namespace std;
int maxsum ( int a[], int left, int right )
{
	int sum = 0;
	if ( left == right )
	{
		if ( a[left] > 0 )
			sum = a[left];
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
				s1 = lefts;
		}
		int s2 = 0;
		int rights = 0;
		for ( int j = center +1; j <= right; j++ )
		{
			rights += a[j];
			if ( rights > s2 )
				s2 = rights;
		}
		sum = s1+s2;
		if ( sum < leftsum )
			sum = leftsum;
		if ( sum < rightsum )
			sum = rightsum;
	}
	return sum;
}

int main ()
{
	int a[50010];
	int testcase,it;
	int sum;
	int s1, s2;
	int n,i,j;
	scanf("%d",&testcase);
	for ( it = 0; it < testcase; it++ )
	{
		sum = 0;
		scanf("%d",&n);
		for ( i = 0; i < n; i++ )
			scanf("%d",&a[i]);
		for ( j = 1; j < n-1; j++ )
		{
			s1 = maxsum(a,0,j);
			if ( s1 > 0 )
				s2 = maxsum(a,j+1,n-1);
			if ( s1 + s2 > sum )
				sum = s1+s2;
		}
		printf("%d\n",sum);
	}
	return 1;
}