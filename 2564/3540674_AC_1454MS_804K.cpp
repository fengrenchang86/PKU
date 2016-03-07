#include <iostream>
#include <string>
using namespace std;
char a[26000][20];
int dp[26000];
char edit[20];
int n;
void init ()
{
	int i;
	for ( i = 0; i < n; i++ )
		dp[i] = 1;
}
int comp ( char *t, char *p )
{
	int i=0;
	while ( t[i] != 0 && p[i] != 0 )
	{
		if ( t[i] < p[i] )
			return -1;
		else if ( t[i] > p[i] )
			return 1;
		i++;
	}
	if ( t[i] == 0 && p[i] == 0 )
		return 0;
	else if ( t[i] ==0 )
		return -1;
	else
		return 1;
}
int acm( int m, char *t )
{
	int begin = 0;
	int end = m;
	int mid=(begin+end)/2;
	int k;
	while ( begin < end )
	{
		mid = (begin+end)/2;
		k = strcmp(a[mid],t);
		if ( k == 0 )
			return mid;
		else if ( k < 0 )
			begin = mid+1;
		else
			end = mid;
	}
	if ( strcmp(a[begin],t) == 0 )
		return begin;
	return -1;
}
int main ()
{
	n = 0;
	int i,j,k,len;
	char save[20];
	while ( scanf("%s",&a[n]) != EOF )
		n++;
	init();
	for ( i = 1; i < n; i++ )
	{
		len = strlen(a[i]);
		for ( j = 0; a[i][j] != 0; j++ )
		{
			strcpy(save,a[i]);
			for ( save[j] = 'a'; save[j] < 'z'; save[j]++ )
			{
				if ( comp(save,a[i]) != -1 )
					continue;
				k = acm(i-1,save);
				if ( k != -1 && dp[i] < dp[k]+1 )
					dp[i] = dp[k]+1;
			}
			strcpy(save,a[i]);
			for ( k = j; a[i][k] != 0; k++ )
				save[k] = save[k+1];
			if ( comp(save,a[i]) == -1 )
			{
				k = acm(i-1,save);
				if ( k != -1 && dp[i] < dp[k]+1 )
					dp[i] = dp[k]+1;
			}
			strcpy(save,a[i]);
			k = len;
			save[len+1] = 0;
			while ( k > j )
			{
				save[k] = save[k-1];
				k--;
			}
			for ( save[j] = 'a'; save[j] < 'z'; save[j]++ )
			{
				if ( comp(save,a[i]) != -1 )
					continue;
				k = acm(i-1,save);
				if ( k != -1 && dp[i] < dp[k]+1 )
					dp[i] = dp[k]+1;
			}
		}
	}
	j = 1;
	for ( i = 0; i < n; i++ )
	{
		if ( dp[i] > j )
			j = dp[i];
	}
	printf("%d\n",j);
	return 0;
}