#include <iostream>
#include <stdlib.h>
using namespace std;
int a[21000];
int n,m;
int cmp ( const void*a, const void*b )
{
	return *(int*)a - *(int*)b;
}
int erfen ( int nbegin, int nend, int nx )
{
	if ( nbegin == nend )
		return nbegin;
	int nmid = (nbegin+nend)/2;
	if ( a[nmid] + nx <= m )
		return erfen(nmid+1,nend,nx);
	else
		return erfen(nbegin,nmid,nx);
}
int main ()
{
	int i,j,k=0;
	scanf("%d%d",&n,&m);
	for ( i = 0; i < n; i++ )
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(a[0]),cmp);
	a[n] = 2000000000;
	for ( i = 0; i < n-1; i++ )
	{
		j =  erfen(i+1,n,a[i])-1;
		k += (j-i);
	}
	printf("%d\n",k);
	return 0;
}