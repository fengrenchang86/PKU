#include <iostream>
using namespace std;
int Qsort( int t[], int start, int end )
{
	int i;
	t[0] = t[start];
	i = 0; // i==0表示t[up]跟t[0]比较， i==1表示t[down]跟t[0]比较。
	int up = end;
	int down = start;
	while ( up != down )
	{
		if ( i == 0 && t[up] >= t[0] )
		{
			up--;
			continue;
		}
		if ( i == 0 && t[up] < t[0] )
		{
			t[down] = t[up];
			i = 1;
			down++;
			continue;
		}
		if ( i == 1 && t[down] <= t[0] )
		{
			down++;
			continue;
		}
		if ( i == 1 && t[down] > t[0] )
		{
			t[up] = t[down];
			i = 0;
			up--;
		}
	}
	t[down] = t[0];
	return down;
}
void qs ( int t[], int start, int end )		//递归实现快排
{
	int mid;
	if ( start < end )
	{
		mid = Qsort(t,start,end);
		qs ( t,start,mid-1);
		qs ( t,mid+1,end);
	}
}
int f ( int d[], int m, int n, int sum )
{
	if ( d[n] > m )
		return 0;
	int c[100];
	int i;
	for ( i = 1; i <= n; i++ )
		c[i] = d[i];
	int g = 0;
	i = n;
	int p;
	int count[100];
	int pc = 0;
	while ( sum != 0 )
	{
		if ( c[i] > 0 && g + c[i] <= m )
		{
			g += c[i];
			c[i] *= -1;
			count[pc++] = i;
			if ( g == m )
			{
				sum -= g;
				pc = 0;
				g = 0;
				if ( sum == 0 )
					return 1;
				i = n+1;
			}
		}
		i--;
		if ( i < 1 )
		{
			if ( pc == 0 )
				return 0;
			i = count[pc-1];
			c[i] *= -1;
			g -= c[i];
			i--;
		}
		if ( i < 1 )
			return 0;
	}
	return 3;
}
int main ()
{
	int n,i;
	int d[100];
	int sum;
	int m;
	while ( scanf("%d",&n) && n!=0 )
	{
		sum = 0;
		for ( i = 1; i <= n; i++ )
		{
			scanf("%d",&d[i]);
//			d[i] = data;
			sum += d[i];
		}
		qs(d,1,n);
		for ( m = d[n]; m < sum; m++ )
		{
			if ( sum%m == 0 )
			{
				if (f(d,m,n,sum) == 1 )
					break;
			}
		}
		printf("%d\n",m);
	}
	return 1;
}