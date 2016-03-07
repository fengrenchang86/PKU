#include <iostream>
using namespace std;
__int64 inf = __int64(2)<<32;
__int64 minf = -inf;
int n,m;
int a[20];
void dfs ( __int64 x, int op, __int64 y, int pos )
{
	if ( pos == n+1 )
	{
		if ( !(op == 1 && x+y == 0 || op == 2 && x-y == 0) )
			return;
		m++;
		if ( m > 20 )
			return;
		int i;
		printf("1");
		for ( i = 2; i <= n; i++ )
		{
			if ( a[i] == 1 )
				printf(" + ");
			else if ( a[i] == 2 )
				printf(" - ");
			else
				printf(" . ");
			printf("%d",i);
		}
		printf("\n");
		return;
	}
	if ( op == 1 )
	{
		a[pos] = 1;
		dfs(x+y,1,pos,pos+1);
	}
	else
	{
		a[pos] = 1;
		dfs(x-y,1,pos,pos+1);
	}
	if ( op == 1 )
	{
		a[pos] = 2;
		dfs(x+y,2,pos,pos+1);
	}
	else
	{
		a[pos] = 2;
		dfs(x-y,2,pos,pos+1);
	}
	__int64 k;
	if ( pos >= 10 )
		k = y*100+pos;
	else
		k = y*10+pos;
	if ( k <= 50000 && k >= -50000  )
	{
		a[pos] = 3;
		dfs(x,op,k,pos+1);
	}
}
int main  ()
{
	while ( cin>>n )
	{
		m = 0;
		dfs(0,1,1,2);
		printf("%d\n",m);
	}
	return 0;
}