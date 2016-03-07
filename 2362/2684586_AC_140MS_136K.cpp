#include <iostream>
#include <stdlib.h>
using namespace std;
int a[30];
int visit[30];
int n,m,k;
int flag;
int cmp ( const void *a, const void *b )
{
	return *(int*)b-*(int*)a;
}
void dfs ( int i, int sum )
{
	
	if ( sum == k )
	{
		int j;
//		for ( j = 1; j <= n; j++ )
//			if ( visit[j] == m )
//				cout<<a[j]<<" ";
//		cout<<endl;
		flag++;
		j = 1;
		while ( j <= n && visit[j] != 0 )
			j++;
		if ( j == n+1 )
		{
			flag --;
			return;
		}
		dfs(j,0);
		if ( flag == 3 )
			return;
		flag --;
		return;
	}
	if ( i > n || sum > k )
		return;
	if ( !(a[i]==a[i-1]&&visit[i-1]==0)&&visit[i] == 0 )
	{
		visit[i] = 1;
		dfs(i+1,sum+a[i]);
		if ( flag == 3 )
			return;
		visit[i] = 0;
	}
	dfs(i+1,sum);
	
}
int main ()
{
	int i,j,tcase,sum;
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase--;
		sum = 0;
		scanf("%d",&n);
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
		if ( sum%4 != 0 )
		{
			cout<<"no"<<endl;
			continue;
		}
		k = sum/4;
		qsort(a,n+1,sizeof(a[0]),cmp);
		flag = 0;
		visit[0] = 1;
		dfs(1,0);
		if ( flag == false )
			cout<<"no"<<endl;
		else
			cout<<"yes"<<endl;
	}
	return 0;
}