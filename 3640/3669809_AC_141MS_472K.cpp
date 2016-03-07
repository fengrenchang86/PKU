#pragma warning(disable:4786)
#include <iostream>
#include <stdlib.h>
#include <map>
using namespace std;
__int64 a[12000];
int b[12000][5];
map<__int64,int>ma;
int comp ( const void*a, const void*b )
{
	return *(int*)a - *(int*)b;
}
int cmp ( const void*a, const void*b )
{
	return *(__int64*)a - *(__int64*)b;
}
int main ()
{
	int n,i,j,k,p;
	while ( scanf("%d",&n) != EOF )
	{
		if ( n == 0 )
			break;
		ma.clear();
		p = 0;
		for ( i = 0; i < n; i++ )
		{
			for ( j = 0 ; j < 5; j++ )
				scanf("%d",&b[i][j]);
			qsort(b[i],5,sizeof(b[i][0]),comp);
			a[i] = 0;
			for ( j = 4; j >= 0; j-- )
			{
				a[i] *= 1000;
				a[i] += b[i][j];
			}
		}
		qsort(a,n,sizeof(a[0]),cmp);
		j = 1;
		k = 1;
		p = 1;
		for ( i = 1; i < n; i++ )
		{
			if ( a[i] == a[i-1] )
				j++;
			else
			{
				if ( j > p )
				{
					p = j;
					k = 1;
				}
				else if ( j == p )
				{
					k++;
				}
				j = 1;
			}
		}
		printf("%d\n",p*k);
	}
	return 0;
}