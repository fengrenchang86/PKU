#include <iostream>
using namespace std;
const int max = 1000;
int index[max];/*
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
void SmallDel (  int& CurrentSize, int& Len )
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
}*/
int Qsort( int t[], int start, int end )
{
	int i;
	index[0] = index[start];
	i = 0; // i==0表示t[up]跟t[0]比较， i==1表示t[down]跟t[0]比较。
	int up = end;
	int down = start;
	while ( up != down )
	{
		if ( i == 0 && t[index[up]] >= t[index[0]] )
		{
			up--;
			continue;
		}
		if ( i == 0 && t[index[up]] < t[index[0]] )
		{
			index[down] = index[up];
			i = 1;
			down++;
			continue;
		}
		if ( i == 1 && t[index[down]] <= t[index[0]] )
		{
			down++;
			continue;
		}
		if ( i == 1 && t[index[down]] > t[index[0]] )
		{
			index[up] = index[down];
			i = 0;
			up--;
		}
	}
	index[down] = index[0];
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
	int CurrentSize,Len;
	int n,m;
	int x,y,z;
	int i,j;
	scanf("%d %d",&n,&m);
	int *b = new int[n+1];
	for ( i = 1; i <= n; i++ )
	{
		scanf("%d",&b[i]);
		index[i] = i;
	}
	index[0] = 0;
	for ( i = 0; i < m; i++ )
	{
		CurrentSize = 1;
		Len = 0;
		scanf("%d%d%d",&x,&y,&z);
		for ( j = 0; j <= n; j++ )
			index[j] = j;
//		cout<<"before sort\n";
//		for ( j = x; j <= y; j++ )
//			cout<<b[index[j]]<<" ";
//		cout<<endl;
		qs(b,x,y);
//		cout<<"after sort\n";
//		for ( j = x; j <= y; j++ )
//			cout<<b[index[j]]<<" ";
//		cout<<endl;
		printf("%d\n",b[index[z+x-1]]);
//		printf("%d\n",sort[z-1]);
	}
	return 1;
}	
