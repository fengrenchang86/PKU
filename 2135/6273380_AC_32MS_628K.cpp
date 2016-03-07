#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1000000000
struct EDGE
{
	int x, y;
	int Rongliang;
	int Cost;
}e[20010];
int preE[1010];
int dist[1010];
queue<int>que;
bool bInQue[1010];
vector<int>pList[1010];
int n, m;
void Insert(int x, int id)
{
	pList[x].push_back(id);
}
void Init()
{
	int i;
	for (i = 0; i <= 1000; i++)
	{
		pList[i].clear();
	}
}
void Input()
{
	int i, x, y, len;
	Init();
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &x, &y, &len);
		e[2 * i].Cost = len;
		e[2 * i].Rongliang = 1;
		e[2 * i].x = x;
		e[2 * i].y = y;
		Insert(x, 2 * i);
		e[2 * i + 1].Cost = len;
		e[2 * i + 1].Rongliang = 1;
		e[2 * i + 1].x = y;
		e[2 * i + 1].y = x;
		Insert(y, 2 * i + 1);
	}
	e[2 * m].Cost = 0;
	e[2 * m].Rongliang = 2;
	e[2 * m].x = 0;
	e[2 * m].y = 1;
	Insert(0, 2 * m);
}
int FindPath()
{
	int i, nTop, id;
	for (i = 0; i <= n; i++)
	{
		dist[i] = INF;
		bInQue[i] = false;
		preE[i] = -1;
	}
	while (!que.empty())
	{
		que.pop();
	}
	dist[0] = 0;
	que.push(0);
	bInQue[0] = true;
	while (!que.empty())
	{
		nTop = que.front();
		que.pop();
		bInQue[nTop] = false;
		for (i = 0; i < pList[nTop].size(); i++)
		{
			id = pList[nTop][i];
			if (dist[e[id].y] > dist[nTop] + e[id].Cost && e[id].Rongliang > 0)
			{
				dist[e[id].y] = dist[nTop] + e[id].Cost;
				preE[e[id].y] = id;
				if (bInQue[e[id].y] == false)
				{
					que.push(e[id].y);
					bInQue[e[id].y] = true;
				}
			}
		}
	}
	nTop = n;
	while (nTop != 0)
	{
		id = preE[nTop];
		e[id].Rongliang--;
		if (id < 2 * m)
		{
			if (id % 2 == 0)
			{
				e[id+1].Cost = -e[id].Cost;
				e[id+1].Rongliang ++;
			}
			else
			{
				e[id-1].Cost = -e[id].Cost;
				e[id-1].Rongliang++;
			}
		}
		nTop = e[id].x;
	}
	return dist[n];
}
void Solve()
{
	int ans = FindPath() + FindPath();
	printf("%d\n", ans);
}
int main()
{
//	freopen("e:\\d\\tour.7.in", "r", stdin);
	scanf("%d %d", &n, &m);
	Input();
	Solve();
	return 0;
}