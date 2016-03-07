#include <iostream>
#include <queue>
using namespace std;
#define INF 1000000000
struct wa
{
	int v, gas, money;
	bool operator()(wa &x, wa &y)
	{
		return x.money > y.money;
	}
};
struct NODE
{
	int v, len;
	NODE *next;
}*pTable[1002];
int cost[1002][102];
int price[1002];
bool visit[1002];
priority_queue<wa, vector<wa>, wa>acque;
//queue<wa>acque;
int n, m, c;
int Final;
void Insert(int x, int y, int len)
{
	NODE *p = new NODE;
	p->len = len;
	p->v = y;
	p->next = pTable[x];
	pTable[x] = p;
}
bool dfs(int node)
{
	visit[node] = true;
	if (node == Final)
	{
		return true;
	}
	NODE *p = pTable[node];
	while (p)
	{
		if (!visit[p->v] && p->len <= c)
		{
			if(dfs(p->v))
				return true;
		}
		p = p->next;
	}
	return false;
}
void Input()
{
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &price[i]);
	}
	int x, y, len;
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &x, &y, &len);
		Insert(x, y, len);
		Insert(y, x, len);
	}
}
int AcDIJ(int nStart)
{
	int i, j, ans = INF;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= c; j++)
		{
			cost[i][j] = INF;
		}
	}
	wa x, y;
	NODE *p;
	x.v = nStart;
	for (j = 0; j <= c; j++)
	{
		cost[nStart][j] = j * price[nStart];
		x.gas = j;
		x.money = cost[nStart][j];
		acque.push(x);
	}
	while (!acque.empty())
	{
		x = acque.top();
	//	x = acque.front();
		acque.pop();
		if (cost[x.v][x.gas] < x.money)
		{
			continue;
		}
		p = pTable[x.v];
		while (p)
		{
			y.gas = x.gas - p->len;
			if (y.gas < 0)
			{
				p = p->next;
				continue;
			}
			y.v = p->v;
			y.money = x.money;
			while (y.gas <= c)
			{
				if (cost[y.v][y.gas] > y.money)
				{
					cost[y.v][y.gas] = y.money;
					acque.push(y);
				}
				else
					break;
				y.gas++;
				y.money += price[y.v];
			}
			p = p->next;
		}
	}
	return ans;
}
void Solve()
{
	int i, q;
	int nStart, nEnd;
	scanf("%d", &q);
	for (i = 0; i < q; i++)
	{
		scanf("%d %d %d", &c, &nStart, &nEnd);
		memset(visit, 0, sizeof(visit));
		Final = nEnd;
		if (!dfs(nStart))
		{
			printf("impossible\n");
			continue;
		}
		AcDIJ(nStart);
		if (cost[nEnd][0] != INF)
		{
			printf("%d\n", cost[nEnd][0]);
		}
		else
		{
			printf("impossible\n");
		}
	}
}
int main()
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		Input();
		Solve();
	}
	return 0;
}
