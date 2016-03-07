#include <iostream>
using namespace std;
int m;
int main ()
{
	int a[120];
	int tcase;
	int i,j,k,n,ans,t;
	scanf("%d",&tcase);
	while ( tcase-- )
	{
		scanf("%d",&m);
		for ( i = 1; i <= m; i++ )
			a[i] = i;
		j = m;
		ans = 1;
		for ( i = 2; j >= i; i++ )
		{
			j -= i;
			ans *= i;
		}
		n = i;
		printf("%d",ans);
		k = 1;
		for ( i = 2; i < n; i++ )
		{
			t = a[k];
			for ( j = k; j < k+i-1; j++ )
				a[j] = a[j+1];
			a[j] = t;
			k += i;
		}
		for ( i = 1; i <= m; i++ )
			printf(" %d",a[i]);
		printf("\n");
	}
	return 0;
}