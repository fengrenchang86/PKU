#include <iostream>
using namespace std;
typedef int type;
const int MaxSize = 500010;
int CurrentSize = 1;
int Len = 1;
void SmallHeapInsert ( type a[], int MaxSize, int& CurrentSize, int x )
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
void SmallDel ( type sort[], type a[], int& CurrentSize, int& Len )
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
int main ()
{
	bool flag[4000000]={0};
	int a[MaxSize];
	int m = 1;
	a[0] = 0;
	while ( m <= 500000 )
	{
//		printf("%d %d::   ",a[m-1],m);
		if ( a[m-1] <= m || flag[a[m-1]-m] == 1 )
			a[m] = a[m-1]+m;
		else
			a[m] = a[m-1]-m;
		flag[a[m]] = 1;
//		printf("%d\n",a[m]);
		m++;
	}
	while (cin>>m&&m!=-1)
		printf("%d\n",a[m]);
	return 1;
}