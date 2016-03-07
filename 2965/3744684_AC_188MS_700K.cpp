#include<iostream>
using namespace std;
char a[10][10];
int col[5];
int row[5];
int arr[5][5];
int ans = 2000000000;;
struct ac
{
	int x,y;
}save[70000],hh[70000];
void init()
{
	int i,j;
	for(i = 0; i <= 4; i++ )
	{
		for ( j = 0; j <= 4; j++ )
			arr[i][j] = 0;
		col[i] = 0;
		row[i] = 0;
	}
	for ( i = 0; i < 60000; i++ )
	{
		save[i].x = -1;
		save[i].y = -1;
	}
}
void dfs( int lay, int num )
{
	if( lay == 16 )
	{
		int i,j;
		for ( i = 0; i < 4; i++ )
		{
			for( j = 0; j < 4; j++)
			{
				if(a[i][j] == '+' )
				{
					if((row[i]+col[j]+arr[i][j]) % 2 != 1)
						return;
				}
				else
				{
					if((row[i]+col[j]+arr[i][j]) % 2 != 0)
						return;
				}
			}
		}
		if( num < ans )
		{
			ans = num;
			j = 0;
			for( i = 0; i < 16; i++ )
			{
				if ( save[i].x != -1 && save[i].y != -1 )
					hh[j++] = save[i];
			}
		}
		return;
	}
	int x = lay/4, y = lay % 4;
	save[lay].x = -1;
	save[lay].y = -1;
	dfs(lay+1, num);
	row[x]++;
	col[y]++;
	arr[x][y] ++;
	save[lay].x = x;
	save[lay].y = y;
	dfs(lay+1,num+1);
	arr[x][y] --;
	row[x]--;
	col[y]--;
}
int main ()
{
	int i;
	init();
	for(i = 0; i < 4; i++ )
		cin>>a[i];
	dfs(0,0);
	printf("%d\n",ans);
	for ( i = 0; i < ans; i++ )
	{
		printf("%d %d\n",hh[i].x+1,hh[i].y+1);
	}
	return 0;
}