#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int a[20100];
void SmallHeapInsert ( int& CurrentSize, int x )
{
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
int SmallDel ( int& CurrentSize )
{
	CurrentSize--;
	int t = a[1];
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
	return t;
}
int main ()
{
	int CurrentSize = 1;
	int n,i;
	scanf("%d",&n);
	int d;
	for ( i = 0; i < n; i++ )
	{
		scanf("%d",&d);
		SmallHeapInsert ( CurrentSize, d );
	}
	_int64 x,y,sum = 0;
	for ( i = 1; i < n; i++ )
	{
		x = SmallDel(CurrentSize);
		y = SmallDel(CurrentSize);
		sum += (x+y);
		SmallHeapInsert ( CurrentSize, x+y );
	}
//	sum += SmallDel(CurrentSize);
	printf("%I64d\n",sum);
	return 0;
}