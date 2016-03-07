#include <iostream>
using namespace std;
int a[11][11];
int visit[11][11];
int score[11];
int n, m;
int nCount;
bool flag;
void VisitSet0()
{
	int i, j;
	for(i = 0; i <= 10; i++)
	{
		for(j = 0; j <= 10; j++)
			visit[i][j] = 0;
		score[i] = 0;
	}
}
void Input()
{
	int i, j;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= i; j++)
			scanf("%d", &a[i][j]);
	}
}
void dfs(int x, int y)
{
	visit[x][y] = 1;
	nCount++;
	if(x - 1 >= 1 && x != y)
	{
		if(a[x-1][y] == 0)
			flag = true;
		else if(a[x-1][y] == a[x][y] && visit[x-1][y] == 0)
			dfs(x-1, y);
	}
	if(x + 1 <= n)
	{
		if(a[x+1][y] == 0)
			flag = true;
		else if(a[x+1][y] == a[x][y] && visit[x+1][y] == 0)
			dfs(x+1,y);
	}
	if(y - 1 >= 1)
	{
		if(a[x][y-1] == 0)
			flag = true;
		else if(a[x][y-1] == a[x][y] && visit[x][y-1] == 0)
			dfs(x, y-1);
	}
	if(y + 1 <= n && x != y)
	{
		if(a[x][y+1] == 0)
			flag = true;
		else if(a[x][y+1] == a[x][y] && visit[x][y+1] == 0)
			dfs(x, y+1);
	}
	if(x-1 >= 1 && y-1 >= 1)
	{
		if(a[x-1][y-1] == 0)
			flag = true;
		else if(a[x-1][y-1] == a[x][y] && visit[x-1][y-1] == 0)
			dfs(x-1, y-1);
	}
	if(x + 1 <= n && y + 1 <= n)
	{
		if(a[x+1][y+1] == 0)
			flag = true;
		else if(a[x+1][y+1] == a[x][y] && visit[x+1][y+1] == 0)
			dfs(x+1, y+1);
	}
}
int getScore()
{
	int i, ans = 0;
	for(i = 1; i <= 9; i++)
	{
		if(i != m)
			ans += score[i];
		else
			ans -= score[i];
	}
	return ans;
}
void Solve()
{
	int i, j, ans = -100000;
	int di, dj;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= i; j++)
		{
			if(a[i][j] != 0)
				continue;
			a[i][j] = m;
			VisitSet0();
			for(di = 1; di <= n; di++)
			{
				for(dj = 1; dj <= di; dj++)
				{
					if(visit[di][dj] == 0 && a[di][dj] != 0)
					{
						flag = 0;
						nCount = 0;
						dfs(di, dj);
						if(flag == false)
							score[a[di][dj]] += nCount;
					}
				}
			}
			di = getScore();
			if(di > ans)
				ans = di;
			a[i][j] = 0;
		}
	}
	printf("%d\n", ans);
}

int main()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		if(n == 0 && m == 0)
			break;
		Input();
		Solve();
	}
	return 0;
}