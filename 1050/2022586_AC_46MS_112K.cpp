#include <iostream>
using namespace std;
int maxsum ( short a[], int left, short right )
{
	int sum = 0;
	if ( left == right )
		sum = a[left];
	else
	{
		int center = (left+right)/2;
		int leftsum = maxsum(a,left,center);
		int rightsum = maxsum(a,center+1,right);
		int s1 = -500000;
		int lefts = 0;
		for ( int i = center; i >= left; i-- )
		{
			lefts += a[i];
			if ( lefts > s1 )
				s1 = lefts;
		}
		int s2 = -500000;
		int rights = 0;
		for ( int j = center +1; j <= right; j++ )
		{
			rights += a[j];
			if ( rights > s2 )
				s2 = rights;
		}
		sum = s1+s2;
		bool g = true;
		if ( sum < leftsum )
		{
			g = false;
			sum = leftsum;
		}
		if ( sum < rightsum)
		{
			g = false;
			sum = rightsum;
		}
	}
	return sum;
}
int main ()
{
	short v[120][120];
	short a[120];
	int i,j,k;
	int n;
	int t;
	int max = -200;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < n; j++ )
			scanf("%d",&v[i][j]);
	}
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < n; j++ )
			a[j] = 0;
		for ( j = i; j < n; j++ )
		{
			for ( k = 0; k < n; k++ )
				a[k] += v[j][k];
			t = maxsum(a,0,n-1);
			if ( t > max )
				max = t;
		}
	}
	printf("%d\n",max);
	return 1;
}