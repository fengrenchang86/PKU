#include<iostream>
using namespace std;
int main ()
{
	int i,j,n,q,min,max;
	int begin,end;
	int a[50100];
	scanf("%d%d",&n,&q);
	for ( i = 1; i <= n; i++ )
		scanf("%d",&a[i]);
	for ( i = 0; i < q; i++ )
	{
		scanf("%d%d",&begin,&end);
		min = max = begin;
		for ( j = begin+1; j <= end; j++ )
		{
			if ( a[j] > a[max] )
				max = j;
			else if ( a[j] < a[min] )
				min = j;
		}
		printf("%d\n",a[max]-a[min]);
	}
	return 0;
}