#include <iostream>
using namespace std;
int main ()
{
	int n,k;
	int p[600];
	int q[600];
	int a[1200];
	int d;
	char ch[10];
	scanf("%d %d",&n,&k);
	int i,j;
	for ( i = 0; i <= n; i++ )
		a[i] = 0;
	for ( j = 0; j < k; j++ )
	{
		scanf("%d",&d);
		for ( i = 0; i < d; i++ )
			scanf("%d",&p[i]);
		for ( i = 0; i < d; i++ )
			scanf("%d",&q[i]);
		scanf("%s",ch);
		if ( ch[0] == '=' )
		{
			for ( i = 0; i < d; i++ )
				a[p[i]] = a[q[i]] = 65536;
		}
		else if ( ch[0] == '>' )
		{
			for ( i = 0; i < d; i++ )
			{
				a[p[i]]--;
				a[q[i]]++;
			}
		}
		else
		{
			for ( i = 0; i < d; i++ )
			{
				a[p[i]]++;
				a[q[i]]--;
			}
		}
	}
	int max = -1;
	for ( i = 1; i <= n; i++ )
	{
		if ( a[i] < 0 )
			a[i]*=-1;
		if ( a[i] > max && a[i] != 65536 )
		{
			max = a[i];
			d = i;
		}
	}
	printf("%d\n",d);
	return 1;
}