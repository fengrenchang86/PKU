#include<iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int x,y;
}a[300];
double b[50000];
int cmp (const void*a, const void*b )
{
	return *(double*)a > *(double*)b ? 1:-1;
}
int main ()
{
	int i,j,k,n;
	int ans = 0;
	scanf("%d",&n);
	for ( i = 0; i <n ;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	k = 0;
	for ( i = 0; i < n-1; i++ )
	{
		for ( j = i+1; j < n; j++)
		{
			if ( a[i].x != a[j].x )
			{
				b[k] = double(a[i].y-a[j].y)/double(a[i].x-a[j].x);
				k++;
			}
			else
				ans = 1;
		}
	}
	qsort(b,k,sizeof(b[0]),cmp);
	i = j = 1;
	for ( i = 1; i < k; i++ )
	{
		if ( b[i] - b[i-1] >= 0.000000001 )
			b[j++] = b[i];
	}
	if ( k != 0)
		ans += j;
	printf("%d\n",ans);
	return 0;
}