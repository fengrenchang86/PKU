#include <iostream>
#include <stdlib.h>
using namespace std;
int a[22];
int v[22];
int n;
bool flag;
int cmp( const void *a, const void *b )
{
	return *(int*)b - *(int*)a;
}
void dfs ( int pos, int sum, int t )
{
	if ( sum == t )
	{
		flag = true;
		return;
	}
	if ( pos > n )
		return ;
/*	if ( a[pos] != a[pos-1] && t+a[pos] <= sum && v[pos] == 0 )
	{
		v[pos] = 1;
		dfs(pos+1,sum,t+a[pos]);
		if ( flag == true )
			return;
		v[pos] = 0;
	}
	else if ( a[pos] == a[pos-1] && t+a[pos] <= sum && v[pos-1]==1 && v[pos]==0 )
	{
		v[pos] = 1;
		dfs(pos+1,sum,t+a[pos]);
		if ( flag == true )
			return;
		v[pos] = 0;
	}
*/
	if ( v[pos] == 0 && t+a[pos] <= sum )
	{
		v[pos] = 1;
		dfs(pos+1,sum,t+a[pos]);
		if ( flag == true )
			return;
		v[pos] = 0;
	}
	dfs ( pos+1,sum,t);
}
int main ()
{
	int sum;
	int tcase;
	int i,j;
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase--;
		sum = 0;
		scanf("%d",&n);
		a[0] = 999999;
		a[n+1] = 0;
		for ( i = 1; i <= n; i++ )
		{
			v[i] = 0;
			scanf("%d",&a[i]);
			sum += a[i];
		}
		if ( sum % 4 != 0 )
		{
			cout<<"no"<<endl;
			continue;
		}
		qsort(a,n+1,sizeof(a[0]),cmp);
		for ( i = 0; i < 3; i++ )
		{
			j = 1;
			while ( v[j] == 1 && j <= n )
				j++;
			v[j] = 1;
			flag = false;
			if ( j > n )
				break;
			dfs (j+1,sum/4,a[j]);
			if ( flag == false )
				break;
		}
		if ( flag == false )
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}