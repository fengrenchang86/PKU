#include <iostream>
using namespace std;
int main ()
{
	int m,n,c;
	int *a,*b,*temp;
	int i;
	int j;
	int count;
	a = new int [1010];
	b = new int [1010];
	while ( scanf( "%d %d %d",&n,&m,&c) && !(m==0&&n==0&&c==0) )
	{
		count = 0;
		for ( i = 0; i <= n; i++ )
			a[i] = 0;
		for ( i = 0; i < m; i++ )
		{
			for ( j = 0; j < n; j++ )
			{
				scanf("%d",&b[j]);
				if ( b[j] == 1 )
					b[j] = a[j] +1;
				{
					if ( b[j] == c )
						count++;
				}
			}
			temp = a;
			a = b;
			b = temp;
		}
//		for ( i = 0; i < n; i++ )
//		{
//			if ( b[i] == 1 )
//			{
//				if ( a[i] >= c )
//					count++;
//			}
//		}
		printf("%d\n",count);
	}
	return 1;
}