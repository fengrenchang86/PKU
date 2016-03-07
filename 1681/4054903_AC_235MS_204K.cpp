#include <iostream>
#include <string>
using namespace std;
const int inf = 2147483647;
char a[20][20],b[20][20];
int n,ans;
void input()
{
	int i,j;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
		for ( j = 0; j < n; j++ )
			scanf(" %c",&b[i][j]);
	for ( i = 0; i < n; i++ )
		for ( j = 0 ; j < n; j++ )
			a[i][j] = b[i][j];
	ans = inf;
}
void change ( int x, int y )
{
	if ( x < 0 || y < 0 || y >= n || x >= n )
		return;
	if ( a[x][y] == 'w' )
		a[x][y] = 'y';
	else
		a[x][y] = 'w';
}
void dfs ( int lay, int num )
{
	char ch[20],bh[20];
	strcpy(ch,a[0]);
	strcpy(bh,a[1]);
	int i,j,k=num;
	if ( lay == n )
	{
		for ( i = 2; i < n; i++ )
			for ( j =0 ; j < n; j++ )
				a[i][j] = b[i][j];
		for ( i = 1; i < n; i++ )
		{
			for ( j = 0; j < n; j++ )
			{
				if ( a[i-1][j] == 'w' )
				{
					change(i,j);
					change(i-1,j);
					change(i+1,j);
					change(i,j-1);
					change(i,j+1);
					k++;
					if ( k >= ans )
					{
						strcpy(a[0],ch);
						strcpy(a[1],bh);
						return;
					}
				}
			}
		}
		for ( i = 0; i < n; i++ )
		{
			if ( a[n-1][i] == 'w' )
				break;
		}
		if ( i == n && k < ans )
			ans = k;
		strcpy(a[0],ch);
		strcpy(a[1],bh);
		return;
	}
	dfs(lay+1,num);
	a[1][lay] = b[1][lay];
	change(0,lay-1);
	change(0,lay);
	change(1,lay);
	change(0,lay+1);
	dfs(lay+1,num+1);
	change(0,lay-1);
	change(0,lay);
	change(1,lay);
	change(0,lay+1);
	strcpy(a[0],ch);
	strcpy(a[1],bh);
}
int main ()
{
	int tc;
	scanf("%d",&tc);
	while ( tc-- )
	{
		input();
		dfs(0,0);
		if ( ans == inf )
			printf("inf\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}