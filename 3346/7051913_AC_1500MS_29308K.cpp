// pku6.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>
#include <queue>
using namespace std;
#define INF 2000000000
char a[102][102];
struct ac
{
	int v;
	ac *next;
}*table[10101];
struct ACM
{
	int x, y, z, day;
	bool operator()(ACM &m1, ACM &m2)
	{
		return m1.day > m2.day;
	}
};
priority_queue<ACM, vector<ACM>, ACM>que;
int n, m;
int visit[10001];
int nCount, finalID;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int dp[101][101][30];
void Insert(int x, int y)
{
	ac *p = new ac;
	p->v = y;
	p->next = table[x];
	table[x] = p;
//	printf("insert(%d,%d) to (%d,%d) ------ %c to %c\n", x/m, x%m, y/m, y%m, a[x/m][x%m], a[y/m][y%m]);
}
void dfs(int father, int node)
{
	visit[node] = true;
	int i, dx, dy, z;
	for (i = 0; i < 4; i++)
	{
		dx = dir[i][0] + node / m;
		dy = dir[i][1] + node % m;
		z = dx * m + dy;
		if (visit[z] != 0 || dx < 0 || dy < 0 || dx >= n || dy >= m)
		{
			continue;
		}
		if (a[dx][dy] == '.')
		{
			dfs(father, z);
		}
		else if(a[dx][dy] >= '1' && a[dx][dy] <= '9' || a[dx][dy] == '$' || a[dx][dy] == '#')
		{
			visit[z] = true;
			Insert(father, z);
		}
	}
}
bool Input()
{
	n = 0;
	int i;
	for (i = 0; i < 10101; i++)
	{
		table[i] = NULL;
	}
	while(cin.getline(a[n], 101, '\n'))
	{
		if (a[0][0] == '-')
		{
			return false;
		}
		if (a[n][0] == 0)
		{
			break;
		}
		m = strlen(a[n]);
		n++;
	}
	if (a[0][0] == '-')
	{
		return false;
	}
	return true;
}
void Solve()
{
	int i, j, k;
	int ans = INF;
	int x, y;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (a[i][j] >= 'A' && a[i][j] <= 'Z' || a[i][j] >= '1' && a[i][j] <= '9' || a[i][j] == '$' || a[i][j] == '#')
			{
				memset(visit, 0, sizeof(visit));
				dfs(i * m + j, i * m + j);
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			for (k = 0; k <= 26; k++)
			{
				dp[i][j][k] = INF;
			}
		}
	}
	ACM r,s;
	ac *p;
	while (!que.empty())
	{
		que.pop();
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (a[i][j] == '#')
			{
				dp[i][j][0] = 0;
				r.day = 0;
				r.x = i;
				r.y = j;
				r.z = 0;
				que.push(r);
			}
			else if(a[i][j] >= 'A' && a[i][j] <= 'Z')
			{
				dp[i][j][a[i][j]-'A'+1] = 0;
				r.day = 0;
				r.x = i;
				r.y = j;
				r.z = a[i][j] - 'A' + 1;
				que.push(r);
			}
		}
	}
	while (!que.empty())
	{
		s = que.top();
		que.pop();
		if (dp[s.x][s.y][s.z] < s.day)
		{
			continue;
		}
		k = s.x * m + s.y;
		p = table[k];
		while (p != NULL)
		{
			x = p->v / m;
			y = p->v % m;
			if (a[x][y] == '$')
			{
				if (s.day < ans)
				{
					ans = s.day;
				}
			}
			else if(a[x][y] >= '1' && a[x][y] <= '9')
			{
				r.x = x;
				r.y = y;
				if (s.z > 0)
				{
					r.z = s.z - 1;
					r.day = s.day;
					if (dp[r.x][r.y][r.z] > r.day)
					{
						dp[r.x][r.y][r.z] = r.day;
						que.push(r);
					}
				}
				r.z = s.z;
				r.day = s.day + a[x][y] - '0';
				if (dp[r.x][r.y][r.z] > r.day)
				{
					dp[r.x][r.y][r.z] = r.day;
					que.push(r);
				}
			}
			p = p->next;
		}
	}
	if (ans == INF)
	{
		printf("IMPOSSIBLE\n");
	}
	else
	{
		printf("%d\n",ans);
	}
}
int main()
{
	while(Input())
	{
		Solve();
	}
	return 0;
}