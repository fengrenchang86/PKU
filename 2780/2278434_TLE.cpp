#include <Iostream>
using namespace std;
int a[1200][2];
int main ()
{
	int i,j,k,n;
	int c,max;
	while ( scanf("%d",&n)!=EOF )
	{
		for ( i = 0; i < n; i++ )
			scanf("%d%d",&a[i][0],&a[i][1]);
		max = 0;
		for ( i = 0; i < n; i++)
		{
			for ( j = i+1; j < n; j++ )
			{
				c  = 2;
				for ( k = j+1; k <n ; k++ )
				{
					if ( (a[j][1]-a[i][1])*(a[k][0]-a[j][0]) == (a[k][1]-a[j][1])*(a[j][0]-a[i][0]) )
						c++;
					if ( c > max )
						max = c;
				}
			}
		}
		printf("%d\n",max);
	}
	return 0;
}