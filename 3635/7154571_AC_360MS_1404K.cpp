#include <iostream>
#include <vector>
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
	NODE(){};
	NODE(int nv, int nlen){
		v = nv; len = nlen;
	}
};
vector<NODE> vecTable[1002];
int cost[1002][102];
bool use[1002][102];
int price[1002];
bool visit[1002];
priority_queue<wa, vector<wa>, wa>acque;
//queue<wa>acque;
int n, m, c;
int Final;
bool dfs(int node)
{
	visit[node] = true;
	if (node == Final)
	{
		return true;
	}
	int i;
	int v, len;
	for (i = 0; i < vecTable[node].size(); i++)
	{
		v = vecTable[node][i].v;
		len = vecTable[node][i].len;
		if (!visit[v] && len <= c)
		{
			if(dfs(v))
				return true;
		}
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
		vecTable[x].push_back(NODE(y, len));
		vecTable[y].push_back(NODE(x, len));
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
			use[i][j] = 0;
		}
	}
	wa x, y;
	NODE p;
	x.v = nStart;
	while (!acque.empty())
	{
		acque.pop();
	}
	for (j = 0; j <= c; j++)
	{
		cost[nStart][j] = j * price[nStart];
		x.gas = j;
		x.money = cost[nStart][j];
		acque.push(x);
		break;
	}
	while (!acque.empty())
	{
		x = acque.top();
		//	x = acque.front();
		acque.pop();
		if (cost[x.v][x.gas] < x.money || use[x.v][x.gas])
		{
			continue;
		}
		if (x.v == Final)
		{
			break;
		}
		use[x.v][x.gas] = 1;
		y = x;
		if (y.gas < c)
		{
			y.gas++;
			y.money += price[y.v];
			if (cost[y.v][y.gas] > y.money)
			{
				cost[y.v][y.gas] = y.money;
				acque.push(y);
			}
		}
		for (i = 0; i < vecTable[x.v].size(); i++)
		{
			p = vecTable[x.v][i];
			y.gas = x.gas - p.len;
			if (y.gas < 0)
			{
				continue;
			}
			y.v = p.v;
			y.money = x.money;
			if (cost[y.v][y.gas] > y.money)
			{
				cost[y.v][y.gas] = y.money;
				acque.push(y);
			}
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