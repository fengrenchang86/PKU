
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


int main ()
{
	int n;
	scanf("%d",&n);
	int *a = new int[n+3];
	int i;
	for ( i = 1; i <= n; i++ )
		scanf("%d",&a[i]);
	qs(a,1,n);
	printf("%d\n",a[(n+1)/2]);
	return 1;
}