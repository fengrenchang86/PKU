#include <iostream>
using namespace std;
int w,h,n;
struct ac
{
	int x1,x2,y1,y2;
}rec[60];
int map[30][30];
int count;
void dfs ( int i, int j, int value, int t )
{
	map[i][j] = count;
	if ( i-1 >= rec[t].x1 && i-1 < rec[t].x2 && map[i-1][j] == value )
		dfs(i-1,j,value,t);
	if ( i+1 >= rec[t].x1 && i+1 < rec[t].x2 && map[i+1][j] == value )
		dfs(i+1,j,value,t);
	if ( j-1 >= rec[t].y1 && j-1 < rec[t].y2 && map[i][j-1] == value )
		dfs(i,j-1,value,t);
	if ( j+1 >= rec[t].y1 && j+1 < rec[t].y2 && map[i][j+1] == value )
		dfs(i,j+1,value,t);
}
void DFS ( int i, int j, int value )
{
	map[i][j] = -1;
	if ( i-1 >= 0 && i-1 < h && map[i-1][j] == value )
		DFS(i-1,j,value);
	if ( i+1 >= 0 && i+1 < h && map[i+1][j] == value )
		DFS(i+1,j,value);
	if ( j-1 < w && j-1 >= 0 && map[i][j-1] == value )
		DFS(i,j-1,value);
	if ( j+1 < w && j+1 >= 0 && map[i][j+1] == value )
		DFS(i,j+1,value);
}
int main ()
{
	int i,j,k,temp;
	while ( cin>>w>>h && !(w==0&&h==0) )
	{
		cin>>n;
		count = 0;
		for ( i = 0; i <= h; i++ )
		{
			for ( j = 0; j <= w; j++ )
				map[i][j] = 0;
		}
		for ( i = 0; i < n; i++ )
		{
			cin>>rec[i].x1>>rec[i].y1>>rec[i].x2>>rec[i].y2;
			if ( rec[i].x1 > rec[i].x2 )
				swap(rec[i].x1,rec[i].x2);
			if ( rec[i].y1 > rec[i].y2 )
				swap(rec[i].y1,rec[i].y2);
			temp = count;
			for ( j = rec[i].x1; j < rec[i].x2; j++ )
			{
				for ( k = rec[i].y1; k < rec[i].y2; k++ )
				{
					if ( map[j][k] <= temp )
					{
						count++;
						dfs(j,k,map[j][k],i);
					}
				}
			}
		}
		count = 0;
		for ( i = 0; i < h; i++ )
		{
			for ( j = 0; j < w; j++ )
			{
				if ( map[i][j] != -1 )
				{
					DFS(i,j,map[i][j]);
					count++;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}