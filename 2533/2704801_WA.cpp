#include <iostream>
using namespace std;
int a[10000];
int b[10000];
int n;
int maxL( int n )
{
	for ( int i = 0, temp = 0; i < n; i++ )
		if ( b[i] > temp )
			temp = b[i];
		return temp;
}
int LISdyna ()
{
	int i,j,k;
	for ( i =1,b[0]=1;i < n; i++ )
	{
		for ( j = 0, k=0;j<i;j++ )
		{
			if ( a[j] <= a[i] && k < b[j] )
				k = b[j];
		}
		b[i] = k+1;
	}
	return maxL(n);
}
int main ()
{
	int i;
	scanf("%d",&n);
		for ( i = 0; i < n; i++ )
		{
			scanf("%d",&a[i]);
		}
		printf("%d\n",LISdyna());
	return 0;
}