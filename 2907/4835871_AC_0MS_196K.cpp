#include <iostream>
using namespace std;

int c[12][12];
struct ac
{
	int x, y;
}t[12];
int startX, startY, n, m, l;
bool visit[12];
int ans;
void Input()
{
	scanf("%d %d", &n, &m);
	scanf("%d %d", &startX, &startY);
	scanf("%d", &l);
	int i, j;
	for(i = 1; i <= l; i++)
	{
		scanf("%d %d", &t[i].x, &t[i].y);
	}
	for(i = 1; i <= l; i++)
	{
		for(j = i+1; j <= l; j++)
		{
			c[i][j] = c[j][i] = abs(t[i].x - t[j].x) + abs(t[i].y - t[j].y);
		}
		c[i][i] = 0;
		c[0][i] = c[i][0] = abs(t[i].x - startX) + abs(t[i].y - startY);
	}
	memset(visit, false, sizeof(visit));
	ans = 2000000000;
}
void dfs(int lay, int nDis, int pos)
{
	if(lay == l+1)
	{
		nDis += c[0][pos];
		if(nDis < ans)
			ans = nDis;
	}
	int i;
	for(i = 1; i <= l; i++)
	{
		if(visit[i] == false)
		{
			visit[i] = true;
			dfs(lay+1, nDis + c[i][pos], i);
			visit[i] = false;
		}
	}
}

void Solve()
{
	ans = 2000000000;
	dfs(1, 0, 0);
	printf("The shortest path has length %d\n", ans);
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		Input();
		Solve();
	}
	return 0;
}