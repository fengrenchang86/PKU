//#include <iostream>
#include <stdio.h>
//using namespace std;
int main ()
{
//	fstream cin("in.txt");
	int tcase;
	int n,k;
	int i,j,c,t;
	int v[1030];
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase--;
		scanf("%d%d",&n,&k);
	//	n = 1024;
	//	k = 64;
		for ( i = 1; i <= n; i++ )
//			v[i] = i;
			scanf("%d",&v[i]);
		for ( i = 0; i < k; i++ )
		{
			for ( j = n; j >= 2; j-- )
			{
				if ( v[j-1] < v[j] )
					break;
			}
			if ( j == 1 )
			{
				for ( i = 1; i <= n; i++ )
					v[i] = i;
			}
			else
			{
				c = j;
				v[0] = v[j-1];
				while ( v[j] > v[0] && j <= n)
					j++;
				j--;
				t = v[c-1];
				v[c-1] = v[j];
				v[j] = t;
				t = c;
				for ( j = t; j <= c+n-j ; j++ )
				{
					t = v[j];
					v[j] = v[c+n-j];
					v[c+n-j] = t;
				}
			}
		}
		for ( i = 1; i < n; i++ )
			printf("%d ",v[i]);
		printf("%d\n",v[n]);
	}
	return 0;
}