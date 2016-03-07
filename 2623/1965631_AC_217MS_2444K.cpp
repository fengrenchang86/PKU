#include <iostream>
using namespace std;
void SmallHeapInsert ( unsigned int a[], int MaxSize, int& CurrentSize, int x )
{
//	if ( CurrentSize == MaxSize )
	{
//		printf("No memory\n");
//		return;
	}
	int i = CurrentSize;
	while ( i > 1 )
	{
		if ( a[i/2] > x )
		{
			a[i] = a[i/2];
			i /= 2;
		}
		else
			break;
	}
	a[i] = x;
	CurrentSize++;
}

void SmallDel ( unsigned int sort[], unsigned int a[], int& CurrentSize, int& Len )
{
	CurrentSize--;
	sort[Len++] = a[1];
	int item = a[CurrentSize];
	int i = 2;
	while ( i <= CurrentSize )
	{
		if ( i < CurrentSize && a[i] > a[i+1] )
			i++;
		if ( item <= a[i] )
			break;
		a[i/2] = a[i];
		i *= 2;
	}
	a[i/2] = item;
}
const int max = 300000;
int main ()
{
	int n;
	int x;
	int Current=1,len=1;
	double mid;
	unsigned int a[max],sort[max];
	int i;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d",&x);
		SmallHeapInsert(a,999999,Current,x);
	}
	{
		for ( i = 1; i <= (n+1)/2+1; i++ )
			SmallDel(sort,a,Current,len);
	}
	if ( n%2 == 1 )
		mid = sort[(n+1)/2]*1.0;
	else
		mid = (sort[(n)/2]*1.0 + 1.0*sort[(n)/2+1])/2;
	printf("%.1lf\n",mid);
	return 1;
}