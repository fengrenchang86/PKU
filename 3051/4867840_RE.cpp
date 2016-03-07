#include <iostream>
using namespace std;
char a[100][1100];
bool visit[100][1100];
int nCount;
int w, h;
int dir[4][2] = {{0,1},{0,-1}, {1,0},{-1,0}};
void dfs(int x, int y)
{
	if(visit[x][y])
		return;
	visit[x][y] = true;
	nCount++;
	int i;
	for(i = 0; i < 4; i++)
	{
		if(x+dir[i][0] >= 0 && x + dir[i][0] < h && y + dir[i][1] >= 0 && y + dir[i][1] < w && a[x+dir[i][0]][y+dir[i][1]] == '*')
		{
			dfs(x+dir[i][0], y+dir[i][1]);
		}
	}
}
void Solve()
{
	int i, j;
	int ans = 0;
	for(i = 0; i < h; i++)
	{
		for(j = 0; j < w; j++)
		{
			if(a[i][j] == '*')
				visit[i][j] = false;
			else
				visit[i][j] = true;
		}
	}
	for(i = 0; i < h; i++)
	{
		for(j = 0; j < w; j++)
		{
			if(!visit[i][j])
			{
				nCount = 0;
				dfs(i, j);
				if(nCount > ans)
					ans = nCount;
			}
		}
	}
	printf("%d\n", ans);
}
void Input()
{
	int i;
	for(i = 0; i < h; i++)
		scanf(" %s", a[i]);
}
int main()
{
	while(scanf("%d %d", &w, &h) != EOF)
	{
		Input();
		Solve();
	}
	return 0;
}