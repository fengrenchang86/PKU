#include <iostream>
#include <stdlib.h>
int cmp(const void*a, const void*b)
{
	return *(int*)a-*(int*)b;
}
using namespace std;
int main ()
{
	int n,k,i,j;
	int tc = 1;
	double ave;
	int a[1010];
	char ch[100];
	while ( scanf("%d%d",&n,&k) && !(n==0&&k==0) )
	{
		if ( tc != 1 )
			printf("\n");
		for ( i = 0; i < n; i++ )
		{
			scanf("%s",&ch);
			a[i] = strlen(ch);
		}
		qsort(a,n,sizeof(a[0]),cmp);
		for ( i = 0; i < n; i+=k )
		{
			ave = 0.0;
			for ( j = 0; j < k; j++ )
				ave += a[i+j];
			ave /= double(k);
			for ( j = 0; j < k; j++ )
			{
				if ( ave-a[i+j] > 2 || a[i+j]-ave > 2 )
				{
					ave = -1;
					break;
				}
			}
			if ( ave == -1 )
				break;
		}
		if ( ave == -1 )
			printf("Case %d: no\n",tc);
		else
			printf("Case %d: yes\n",tc);
		tc++;
	}
	return 0;
}