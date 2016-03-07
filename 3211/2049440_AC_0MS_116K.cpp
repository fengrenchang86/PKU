#include <iostream>
#include <string.h>
using namespace std;
char col[20][20];
int a[20][120];
int l[120];
int flag=0;
void sort( int k, int n )
{
	int i,j,q;
	for ( i = 0; i < n-1; i++ )
	{
		for ( j = i+1; j < n; j++ )
		{
			if ( a[k][i] < a[k][j] )
			{
				q = a[k][i];
				a[k][i] = a[k][j];
				a[k][j] = q;
			}
		}
	}
}
void dfs ( int t, int sum, int position, int k )
{
	if ( t == sum )
	{
		flag = 1;
		return;
	}
	int i = position;
	while ( l[position] == 1 || t+a[k][position] > sum )
	{
		if ( position >= a[k][110] )
			break;
		position++;
	}
	if ( position >= a[k][110] )
		return;	
	if ( t + a[k][position] == sum )
	{
		flag = 1;
		return;
	}
	t += a[k][position];
	l[position] = 1;
	dfs(t,sum,position+1,k);
	l[position] = 0;
	if ( flag == 1 )
		return;
	if ( t != sum )
	{
		t -= a[k][position];
		dfs(t,sum,position+1,k);
	}
}
int main ()
{
	int i,j,m,n;
	char put[20];
	int num;
	int time;
	while  ( scanf("%d%d",&m,&n) && !(m==0&&n==0 ) )
	{
		for ( i = 0; i <= m; i++ )
			a[i][110]= a[i][111]= 0;
		for ( i = 0; i < m; i++ )
			scanf("%s",col[i]);
		for ( i = 0; i < n; i++ )
		{
			scanf("%d %s",&num,put);
			for ( j = 0; j < m; j++ )
				if ( strcmp(put,col[j])==0 )
					break;
			a[j][a[j][110]++] = num;
			a[j][111] += num;
		}
		for ( i = 0; i < m; i++ )
			sort(i,a[i][110]);
		time = 0;
		for ( i = 0; i < m; i++ )
		{
			for ( j = 0; j <= a[i][110]; j++ )
				l[i] = 0;
			for ( j = (a[i][111]+1)/2; j <= a[i][111]; j++ )
			{
				dfs(0,j,0,i);
				if ( flag == 1 )
				{
					flag = 0;
					time += j;
					break;
				}
				flag = 0;
			}
		}
		cout<<time<<endl;
	}
	return 1;
}