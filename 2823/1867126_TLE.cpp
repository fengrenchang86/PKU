#include <iostream.h>
int a[1000020];
int t[1000020];
int max[1000020] ;
int min[1000020] ;
int M;
int N;
int c = 0;
int Qsort( int h[], int start, int end )
{
	int i;
	i = 0; // i==0表示t[up]跟t[0]比较， i==1表示t[down]跟t[0]比较。
	int up = end;
	int down = start;
	h[0] = h[start];
	while ( up != down )
	{
		if ( i == 0 && h[up] >= h[0] )
		{
			up--;
			continue;
		}
		if ( i == 0 && h[up] < h[0] )
		{
			h[down] = h[up];
			i = 1;
			down++;
			continue;
		}
		if ( i == 1 && h[down] <= h[0] )
		{
			down++;
			continue;
		}
		if ( i == 1 && h[down] > h[0] )
		{
			h[up] = h[down];
			i = 0;
			up--;
		}
	}
	h[down] = h[0];
	return down;
}
void qs ( int h[], int start, int end )		//递归实现快排
{
	int mid;
	if ( start < end )
	{
		mid = Qsort(h,start,end);
		qs ( h,start,mid-1);
		qs ( h,mid+1,end);
	}
}
void f ( int b, int e )
{
	int m = -999999;
	int n = 999999;
	int i;
	for ( i = b; i < e; i++ )
	{
		if ( a[i] > m )
		{
			m = a[i];
		}
		if ( a[i] < n )
		{
			n = a[i];
		}
	}
	max[c] = m;
	min[c++] = n;
}

void main ()
{
	int n;
	int k;
	int i;
	int j;
	cin>>n>>k;
	for ( i = 1; i <= n; i++ )
		cin>>a[i];
	for ( i = 1; i <= n-k+1; i++ )
	{
		for ( j = i; j <= i+k-1; j++ )
			t[j] = a[j];
		t[0] = t[i];
		qs(t,i,i+k-1);
		min[i] = t[i];
		max[i] = t[i+k-1];
	}
	for ( i = 1; i <= n-k+1; i++ )
		cout<<min[i]<<" ";
	cout<<endl;
	for ( i = 1; i <= n-k+1; i++ )
		cout<<max[i]<<" ";
	cout<<endl;
}