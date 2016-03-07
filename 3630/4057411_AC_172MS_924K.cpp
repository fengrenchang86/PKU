#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
char a[10010][12];
int cmp(const void * a,const void * b)
{
	return strcmp((char*)(a),(char*)(b));
}
bool comp ( char *x, char *y )
{
	int i=0;
	while ( x[i] != NULL && y[i] != NULL )
	{
		if ( x[i] != y[i] )
			return true;
		i++;
	}
	return false;
}
void solve ()
{
	int n,i;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
		scanf(" %s",a[i]);
	qsort(a,n,sizeof(a[0]),cmp);
	for ( i = 0; i < n-1; i++ )
	{
		if ( comp(a[i],a[i+1]) == false )
			break;
	}
	if ( i == n-1 )
		printf("YES\n");
	else
		printf("NO\n");
}
int main ()
{
	int tc;
	scanf("%d",&tc);
	while ( tc-- )
		solve();
	return 0;
}