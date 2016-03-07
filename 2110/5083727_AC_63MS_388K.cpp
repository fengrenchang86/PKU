#include <iostream>
using namespace std;
int nArray[120][120];
bool visit[120][120];
int nDir[4][2] = {{1,0}, {-1,0}, {0, 1}, {0, -1}};
int nAns, n;
int nLowest, nHightest;
void dfs(int x, int y)
{
	visit[x][y] = true;
	int i, dx, dy;
	for(i = 0; i < 4; i++)
	{
		dx = (nDir[i][0] + x);
		dy = (nDir[i][1] + y);
		if(dx < 1 || dy < 1 || dx > n || dy > n)
			continue;
		if(nLowest <= nArray[dx][dy] && nArray[dx][dy] <= nHightest)
		{
			if(!visit[dx][dy])
				dfs(dx, dy);
		}
	}
}
void Input()
{
	int i, j;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			scanf("%d", &nArray[i][j]);
		}
	}
}
void Solve()
{
	int nBegin, nEnd, nMid;
	nAns = 2000000;
	for(nLowest = 0; nLowest <= 110; nLowest++)
	{
		nBegin = nLowest;
		nEnd = 110 < (nBegin + nAns) ? 110 : (nBegin + nAns);
		while(nBegin < nEnd)
		{
			nMid = (nBegin + nEnd) / 2;
			nHightest = nMid;
			memset(visit, 0, sizeof(visit));
			if(nArray[1][1] >= nLowest && nArray[1][1] <= nHightest)
				dfs(1, 1);
			if(visit[n][n])
			{
				nAns = nHightest - nLowest;
				nEnd = nMid;
			}
			else
				nBegin = nHightest + 1;
		}
	}
	printf("%d\n", nAns);
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		Input();
		Solve();
	}
	return 0;
}