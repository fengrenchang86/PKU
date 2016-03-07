#include <iostream>
#include <string>
using namespace std;
int len,m,end;
bool flag;
char t[300];
char in[500];
int max[300];
int min[300];
int sum[300][300];
int ans[300];
void init()
{
	int i,j;
	for ( i = 0; in[i] != '='; i++ )
		t[i] = in[i];
	t[i] = NULL;
	i++;
	j = 0;
	while ( in[i] != NULL )
	{
		j *= 10;
		j += in[i]-'0';
		i++;
	}
	m = j;
	flag = false;
}
void run ()
{
	int i,k;
	len = strlen(t);
	for ( i = 0; i < len; i++ )
	{
		sum[i][i] = t[i]-'0';
		if ( t[i] == '0' )
			continue;
		for ( k = 1; k < 5 && i+k < len; k++ )
			sum[i][i+k] = sum[i][i+k-1]*10+t[i+k]-'0';
	}
	min[len-1] = max[len-1] = t[len-1]-'0';
	max[len] = 0;
	for ( i = len-2; i >= 0; i-- )
	{
		min[i] = min[i+1]+(t[i]-'0');
		max[i] = 0;
		if ( t[i] == '0' )
			continue;
		for ( k = 0; k < 5 && i+k<len; k++ )
		{
			if ( sum[i][i+k] + max[i+k+1] > max[i] )
				max[i] = sum[i][i+k]+max[i+k+1];
		}
	}
}
void dfs ( int i, int lay, int data )
{
	if ( i == len )
	{
		if ( data == m )
		{
			end = lay;
			flag = true;
		}
		return;
	}
	int k,x;
	for ( k = 0; k < 5 && i+k < len; k++ )
	{
		x = data+sum[i][i+k];
		if ( m-x >= min[i+k+1] && m-x <= max[i+k+1] )
		{
			ans[lay] = i+k+1;
			dfs(i+k+1,lay+1,x);
			if ( flag == true )
				return;
		}
	}
}
void print()
{
	int i,j=0;
	for ( i = 0; i < end; i++ )
	{
		while ( j < ans[i] )
		{
			printf("%c",t[j]);
			j++;
		}
		if ( i < end-1 )
			printf("+");
		else
			printf("=%d\n",m);
	}
}
int main ()
{
	int tc= 1,i;
	while ( scanf(" %s",&in) != EOF )
	{
		if ( strcmp(in,"0=0")==0 )
			return 0;
		printf("%d. ",tc);
		tc++;
		init();
		run();
/*		for ( i = 0; i < 5 && i < len; i++ )
		{
			dfs(i,0,sum[0][i]);
			if ( flag == true )
				break;
		}
*/		dfs(0,0,0);
		if ( flag == true )
			print();
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}