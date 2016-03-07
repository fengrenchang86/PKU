#include <iostream>
using namespace std;
int pre[100][100];
char key[100],word[100];
void p ( int x, int y )
{
	if ( x == 0 )
	{
		printf("%c: ",key[x]);
		for ( int i = pre[x][y]; i<=y; i++ )
			printf("%c",word[i]);
		printf("\n");
		return;
	}
	p(x-1,pre[x][y]);
	printf("%c: ",key[x]);
	int i;
	for ( i = pre[x][y]+1; i <= y; i++ )
		printf("%c",word[i]);
	printf("\n");
}
int main ()
{
	int tcase,len1,len2,it=1;
	int cost[100][100];
	int dp[100][100];
	int r[100];
	int i,j,k,min;
	scanf("%d",&tcase);
	while ( tcase-- )
	{
		scanf("%d%d",&len1,&len2);
		scanf(" %s",&key);
		scanf(" %s",&word);
		for ( i = 0; i < len2; i++ )
			scanf("%d",&r[i]);
		for ( j = 0; j < len2; j++ )
			cost[j][j] = r[j];
		for ( i = 0; i < len2; i++ )
		{
			for ( j = i+1; j < len2; j++ )
				cost[i][j] = cost[i][j-1]+r[j]*(j-i+1);
		}
		for ( j = 0; j < len2; j++ )
			dp[0][j] = cost[0][j];
		for ( j =1; j < len2; j++ )
		{
			dp[j][j] = dp[j-1][j-1]+r[j];
			pre[j][j] = j-1;
		}
		for ( i = 1; i < len1; i++ )
		{
			for ( j = i+1; j < len2; j++ )
			{
				min = 2000000000;
				for ( k = i-1; k < j; k++ )
				{
					if ( dp[i-1][k]+cost[k+1][j] < min )
					{
						min = dp[i-1][k] + cost[k+1][j];
						pre[i][j] = k;
						dp[i][j] = min;
					}
				}
			}
		}
		printf("Keypad #%d:\n",it);
		it++;
		p(len1-1,len2-1);printf("\n");

	}
	return 0;
}
