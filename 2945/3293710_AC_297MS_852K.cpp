#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
char t[21000][30];
int re[21000];
int cmp ( const void *a, const void*b )
{
	return strcmp((char*)a,(char*)b);
}
int main ()
{
	int i,n=4,m,k;
	while ( scanf("%d%d",&n,&m) != EOF )
	{
		if ( n == 0 && m == 0 )
			break;
		for ( i = 0; i < n; i++ )
		{
			scanf("%s",&t[i]);
			re[i] = 0;
		}
		re[n]=0;
		qsort(t,n,sizeof(t[0]),cmp);
		k = 0;
		for ( i = 1; i < n; i++ )
		{
			if ( strcmp(t[i-1],t[i])==0 )
				k++;
			else
			{
				re[k]++;
				k = 0;
			}
		}
		re[k]++;
		for ( i = 0; i < n; i++ )
			printf("%d\n",re[i]);
	}
	return 0;
}