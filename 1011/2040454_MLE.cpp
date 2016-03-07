
#include <iostream>
using namespace std;
int flag = 0;
int Qsort( int t[], int start, int end )
{
	int i;
	t[0] = t[start];
	i = 0; // i==0表示t[up]跟t[0]比较， i==1表示t[down]跟t[0]比较。
	int up = end;
	int down = start;
	while ( up != down )
	{
		if ( i == 0 && t[up] <= t[0] )
		{
			up--;
			continue;
		}
		if ( i == 0 && t[up] > t[0] )
		{
			t[down] = t[up];
			i = 1;
			down++;
			continue;
		}
		if ( i == 1 && t[down] >= t[0] )
		{
			down++;
			continue;
		}
		if ( i == 1 && t[down] < t[0] )
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
int f ( int a[], int l[], int t, int sum, int position, int max, int n, int p[] )
{
	if ( flag == 1 )
		return 1;
	if ( max == sum )
	{
		flag = 1;
		return 1;
	}
	else if ( t > sum )
		return 0;
	else if ( t == sum )
	{
		int *b = new int[n];
		int c[100]={0};
		int q[100];
		int i = 1, j = 1;
		while ( i <= n )
		{
			if ( l[i] == 0 )
				b[j++] = a[i];
			i++;
		}
		n = j-1;
		q[n+1] = 0;
		q[n] = b[n];
		for ( i = n-1; i>= 1; i-- )
			q[i] = q[i+1] + b[i];
		f ( b, c,0, sum, 1, max-sum, n,q );
	}
	else
	{
		if ( position > n )
			return 0;
		t+=a[position];
		if ( t <= sum && t+p[position+1] >= sum)
		if ( position == 1  )
		{
			l[position] = 1;
			f(a,l,t,sum,position+1,max,n,p);
		}
		else if (a[position] != a[position-1])
		{
			l[position] = 1;
			f(a,l,t,sum,position+1,max,n,p);
		}
		else if (a[position] == a[position-1] && l[position-1] == 1)
		{
			l[position] = 1;
			f(a,l,t,sum,position+1,max,n,p);
		}
		if ( flag == 1 )
			return 1;
		l[position] = 0;
		t -= a[position];
		f(a,l,t,sum,position+1,max,n,p);
	}
	
	return 1;
}
int main ()
{
	int n,i,j;
	int sum;
	int m;
	int p[100];
	int d[100];
	while ( scanf("%d",&n) && n!=0 )
	{
		int *l = new int[100];
		for ( i = 1; i <= n; i++ )
			l[i] = 0;
		sum = 0;
		for ( i = 1; i <= n; i++ )
		{
			scanf("%d",&d[i]);
			if ( d[i] > 50 )
			{
				i--;
				n--;
				continue;
			}
			sum += d[i];
		}
		if ( n == 1 )
		{
			cout<<d[1]<<endl;
			continue;
		}
		p[n+1] = 0;
		p[n] = d[n];
		for ( i = n-1; i >= 1; i-- )
			p[i] = p[i+1] + d[i];
		qs(d,1,n);
		for ( i = d[1]; i<=(sum+1)/2; i++ )
		{
			if ( sum%i==0)
			{
				f(d,l,0,i,1,sum,n,p);
				if ( flag == 1 )
					break;
			}
		}
		if ( flag == 1 )
			cout<<i<<endl;
		else
			cout<<sum<<endl;
		flag = 0;
	}
	return 1;
}