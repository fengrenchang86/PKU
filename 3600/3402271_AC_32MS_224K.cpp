#include <iostream>
using namespace std;
char big[25][25];
char sub[25][25];
int a[25];
int bign,bigm,subn,subm;
bool flag=false;
void dfs ( int i, int j, int k )
{
	if ( i == bigm && j != subm )
		return;
	if ( j == subm )
	{
		k++;
		int row=1;
		while ( k < bign && row < subn )
		{
			for ( i = 0; i < subm; i++ )
			{
				if ( big[k][a[i]] != sub[row][i] )
					break;
			}
			if ( i == subm )
				row++;
			k++;
		}
		if ( row == subn )
		{
			flag = true;
		}
		return;
	}
	if ( big[k][i] == sub[0][j] )
	{
		a[j] = i;
		dfs(i+1,j+1,k);
	}
	if ( flag == true )
		return;
	dfs(i+1,j,k);
}
int main ()
{
	int i,j;
	scanf("%d%d",&subn,&subm);
	for ( i = 0; i < subn; i++ )
	{
		for ( j = 0; j < subm; j++ )
			cin>>sub[i][j];
	}
	scanf("%d%d",&bign,&bigm);
	for ( i = 0; i < bign; i++ )
	{
		for ( j = 0; j < bigm; j++ )
			cin>>big[i][j];
	}
	for ( i = 0; i < bign; i++ )
	{
		dfs(0,0,i);
		if ( flag == true )
			break;
	}
	if ( flag == true )
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}