#include <iostream>
#include <stdlib.h>
using namespace std;
int a[30];
int visit[30];
int n,m,k;
bool flag;
int cmp ( const void *a, const void *b )
{
	return *(int*)b-*(int*)a;
}
void dfs ( int i, int sum )
{
	if ( i > n || sum > k )
		return;
	if ( sum == k )
	{
		flag = true;
		return;
	}
	if ( visit[i-1] == m || a[i] != a[i-1] )
	{
		visit[i] = m;
		dfs(i+1,sum+a[i]);
		visit[i] = 0;
	}
	dfs(i+1,sum);
	
}
int main ()
{
	int i,tcase,sum;
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase--;
		m = 1;
		flag = false;
		sum = 0;
		scanf("%d",&n);
		visit[0] = m;
		a[0] = 200000;
		for ( i = 1; i <= n; i++ )
		{
	//		a[i] = rand()%10000+1;
	//		printf("%d ",a[i]);
			scanf("%d",&a[i]);
			visit[i] = 0;
			sum += a[i];
		}
	//	printf("\n");
		if ( n < 4 || sum%4 != 0 )
		{
			cout<<"no"<<endl;
			continue;
		}
		k = sum/4;
		qsort(a,n+1,sizeof(a[0]),cmp);
		for ( i = 1; i <= 3; i++ )
		{
			m = i;
			flag = false;
			dfs(1,0);
			if ( flag == false )
				break;
		}
		if ( flag == false )
			cout<<"no"<<endl;
		else
			cout<<"yes"<<endl;
	}
	return 0;
}