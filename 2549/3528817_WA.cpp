#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp ( const void *a , const void *b ) 
{
	return *(int *)a - *(int *)b; 
} 
int a[1200];
int n;
void input ()
{
	int i;
	for ( i = 0; i < n; i++ )
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(a[0]),cmp);
}
bool solve ( )
{
	int i,j,k,l;
	for ( i = n-1; i >= 0; i-- )
	{
		for ( j = 0; j < n; j++ )
		{
			for ( k = j+1; k < n; k++ )
			{
				for ( l = k+1; l < n; l++ )
				{
					if ( a[i] == a[j]+a[k]+a[l])
					{
						printf("%d\n",a[i]);
						return false;
					}
				}
			}
		}
	}
	return true;
}
int main ()
{
	while ( cin>>n && n )
	{
		input();
		if ( solve() )
			printf("no solution\n");
	}
	return 0;
}