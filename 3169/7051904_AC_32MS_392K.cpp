#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool yueshu[1010][1010];
#define INF 2000000000
struct EDGE
{
	int y, val;
};
vector<EDGE>pList[1010];
queue<int>que;
bool bInQue[1010];
int CountToQue[1010];
int dis[1010];
int n;
void Insert(int x, int y, int val)
{
	EDGE e;
	e.val = val;
	e.y = y;
	pList[x].push_back(e);
}
int SPFA()
{
	int i, k, nTop;
	EDGE e;
	for (i = 1; i <= n; i++)
	{
		dis[i] = INF;
	}
	memset(bInQue, 0, sizeof(bInQue));
	memset(CountToQue, 0, sizeof(CountToQue));
	while (!que.empty())
	{
		que.pop();
	}
	que.push(1);
	bInQue[1] = true;
	CountToQue[1] = 1;
	dis[1] = 0;
	while (!que.empty())
	{
		nTop = que.front();
		que.pop();
		bInQue[nTop] = 0;
		if (CountToQue[nTop] > n)
		{
			return -1;
		}
		for (i = 0; i < pList[nTop].size(); i++)
		{
			e = pList[nTop][i];
			if (dis[e.y] > dis[nTop] + e.val)
			{
				dis[e.y] = dis[nTop] + e.val;
				if (!bInQue[e.y])
				{
					bInQue[e.y] = 1;
					CountToQue[e.y]++;
					que.push(e.y);
				}
			}
		}
	}
	if (dis[n] != INF)
	{
		return dis[n] - dis[1];
	}
	return -2;
}
int main()
{
	int m1, m2, i;
	int x, y, val;
	scanf("%d %d %d", &n, &m1, &m2);
	for (i = 0; i < m1; i++)
	{
		scanf("%d %d %d", &x, &y, &val);
		Insert(x, y, val);
		Insert(y, x, 0);
	}
	for (i = 0; i < m2; i++)
	{
		scanf("%d %d %d", &x, &y, &val);
		Insert(y, x, -val);
	}
	val = SPFA();
	printf("%d\n", val);
	return 0;
}