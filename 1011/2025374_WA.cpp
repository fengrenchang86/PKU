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
	while ( sum != 0 )
	{
		if ( c[i] > 0 && g + c[i] <= m )
		{
			g += c[i];
			c[i] *= -1;
		}
		if ( g == m )
		{
			sum -= g;
			if ( sum == 0 )
				return 1;
			i = n;
		}
		i--;
		if ( i <= 0 )
			return 0;
	}
	return 3;
}
int main ()
{
	int n,i;
	int v[100];   //stick
	int a[100];
	int d[100];
	int sum;
	int m;
	int data;
	while ( scanf("%d",&n) && n!=0 )
	{
		sum = 0;
		for ( i = 0; i < 100; i++ )
			a[i] = v[i] = 0;
		for ( i = 1; i <= n; i++ )
		{
			scanf("%d",&data);
			d[i] = data;
			v[data]++;
			sum += data;
		}
		qs(d,1,n);
		for ( m = d[n]; m < sum; m++ )
		{
			if ( sum%m != 0 )
				continue;
			data = f(d,m,n,sum);
	//		printf("%d\n",data);
			if ( data == 1 )
			{
				printf("%d\n",m);
				break;
			}
		}
		printf("%d\n",sum);
	}
	return 1;
}