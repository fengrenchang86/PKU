#include<iostream>
using namespace std;
int a[40000];
int main ()
{
	int n,i,j=0,k;
	scanf(" %d",&n);
	for (i=0; i< n; i++ )
	{
		scanf("%d",&a[i]);
		if ( a[i] == 1 )
			j++;
	}
	k = 0;
	for ( i = 0; i < j; i++ )
	{
		if ( a[i] != 1 )
			k++;
	}
	printf("%d\n",2*k);
	return 0;
}