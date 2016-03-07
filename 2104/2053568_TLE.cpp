#include <iostream>
using namespace std;
void SmallHeapInsert (int a[], int& CurrentSize, int x )
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
void SmallDel ( int sort[], int a[], int& CurrentSize, int& Len )
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
	int CurrentSize,Len;
	int n,m;
	int x,y,z;
	int i,j;
	scanf("%d %d",&n,&m);
	int *a = new int[n+1];
	int *b = new int[n+1];
	int *sort = new int [n+1];
	for ( i = 1; i <= n; i++ )
		scanf("%d",&b[i]);
	for ( i = 0; i < m; i++ )
	{
		CurrentSize = 1;
		Len = 0;
		scanf("%d%d%d",&x,&y,&z);
		for ( j = x; j <= y; j++ )
			SmallHeapInsert(a,CurrentSize,b[j]);
		for ( j = 0; j < z; j++ )
			SmallDel(sort,a,CurrentSize,Len);
		printf("%d\n",sort[z-1]);
	}
	return 1;
}	
