#include <iostream>
#include <algorithm>
using namespace std;
int a[1000100];
int main ()
{
	int n,i;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
		scanf("%d",&a[i]);
	sort(a,a+n);
	if ( n < 3 )
		printf("The set is rejected.\n");
	else if ( a[0]+a[1] > a[n-1] || a[n-3]+a[n-2]<=a[n-1] )
		printf("The set is rejected.\n");
	else
		printf("The set is accepted.\n");
	return 0;
}