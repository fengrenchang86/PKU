#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int nArray[120][120];
bool visit[120][120];
vector<int>vec;
vector<int>que;
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
	vec.clear();
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			scanf("%d", &nArray[i][j]);
			vec.push_back(nArray[i][j]);
		}
	}
	que.clear();
	sort(vec.begin(), vec.end());
	que.push_back(vec[0]);
	for(i = 1; i < vec.size(); i++)
	{
		if(vec[i] != vec[i-1])
			que.push_back(vec[i]);
	}
}
void Solve()
{
	int nBegin, nEnd, nMid;
	nAns = 2000000;
	int i;
	for(i = 0; i < que.size(); i++)
	{
		nLowest = que[i];
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