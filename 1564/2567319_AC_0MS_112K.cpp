#include <iostream>
#include <stdlib.h>
using namespace std;
int cmp ( const void*a, const void *b )
{
	return *(int*)b-*(int*)a;
}
bool visit[200];
int a[200];
bool flag;
int sum,n;
void dfs ( int i, int t )
{
	if ( t == sum )
	{
		flag = true;
		int j;
		for ( j = 1; j < i; j++ )
			if ( visit[j] == true )
				break;
		printf("%d",a[j]);
		j++;
		while ( j < i )
		{
			if ( visit[j] == true )
				printf("+%d",a[j]);
			j++;
		}
		printf("\n");
		return;
	}
	else if ( t > sum )
		return;
	else if ( i > n )
		return;
	if ( visit[i-1] == true )
	{
		visit[i] = true;
		dfs(i+1,t+a[i]);
		visit[i] =false;
	}
	else if (  a[i] != a[i-1] )
	{
		visit[i] = true;
		dfs(i+1,t+a[i]);
		visit[i] = false;
	}
	dfs(i+1,t);
}
int main ()
{
	int i;
	while ( scanf("%d%d",&sum,&n) && !(n==0&&sum==0) )
	{
		for ( i = 1; i <= n; i++ )
		{
			scanf("%d",&a[i]);
			visit[i] =false;
		}
		printf("Sums of %d:\n",sum);
		visit[0] = true;
		a[0] = 2000000;
		qsort(a,n+1,sizeof(a[0]),cmp);
		flag = false;
		dfs(1,0);
		if ( flag == false )
			printf("NONE\n");
	}
	return 0;
}