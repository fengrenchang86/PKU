#include <iostream>
#include <stdlib.h>
using namespace std;
int a[1000010],b[1000010],sort[1000010],visit[1000010];
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
void SmallDel ( int& CurrentSize, int& Len )
{
	CurrentSize--;
	if ( sort[Len-1] != a[1] )
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
int find ( int key, int end)
{
	int begin = 1,mid;
	while ( 1 )
	{
		mid = (begin+end)/2;
		if ( key > sort[mid] )
			begin = mid+1;
		else if ( key < sort[mid] )
			end = mid;
		else
			break;
	}
	return mid;
}
int main ()
{
	int n,i,j,k,ans,c;
	int CurrentSize=1,len=1;
	scanf("%d",&n);
	for ( i = 1; i <= n; i++ )
	{
		scanf("%d",&a[i]);
		b[i] = a[i];
		SmallHeapInsert(CurrentSize,a[i]);
	}
	for ( i = 1; i < len; i++)
		visit[i] = 0;
	sort[0] = 2147483648;
	ans = n;
	while ( CurrentSize > 0 )
		SmallDel(CurrentSize,len);
	len--;
	for ( i = 1; i <= n-len+1; i++ )
	{
		j = i-1;
		c = 0;
		while ( c < len )
		{
			j++;
			k = find(b[j],len);
			if(visit[k] != i )
			{
				visit[k] = i;
				c++;
			}
			if ( j == n )
				break;
		}
		if ( c == len && j-i+1 < ans )
			ans = j-i+1;
	}
	cout<<ans<<endl;
	return 0;
}
