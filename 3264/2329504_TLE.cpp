#include<iostream>
using namespace std;
int a[50100];
void find ( int low, int high, int& min, int& max)
{
	if ( low == high )
	{
		max = min = a[low];
		return;
	}
	else if ( high-low == 1 )
	{
		if ( a[low] > a[high] )
		{
			min = a[high];
			max = a[low];
		}
		else
		{
			min = a[low];
			max = a[high];
		}
		return;
	}
	int mid = (low+high)/2;
	int min1,min2,max1,max2;
	min1 = min2 = min;
	max1 = max2 = max;
	find(low,mid,min1,max1);
	find(mid+1,high,min2,max2);
	min = min1<min2?min1:min2;
	max = max1>max2?max1:max2;
}
int main ()
{
	int i,n,q,min,max;
	int begin,end;
	scanf("%d%d",&n,&q);
	for ( i = 1; i <= n; i++ )
		scanf("%d",&a[i]);
	for ( i = 0; i < q; i++ )
	{
		scanf("%d%d",&begin,&end);
		find(begin,end,min,max);
		printf("%d\n",max-min);
	}
	return 0;
}