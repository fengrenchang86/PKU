#include <iostream>
using namespace std;
int p[12], v[12];
bool visit[12];
int maxCost, n,d;
void dfs(int lay, int x, int y, int costY, bool isX)
{
	if(costY > maxCost)
		maxCost = costY;
	if(lay == n)
		return;
	int i;
	for(i = 0; i < n; i++)
	{
		if(visit[i])
			continue;
		visit[i] = true;
		if(isX)
		{
			if(x+v[i]-y<=d)
				dfs(lay+1, x+p[i], y, costY, true);
			else
				dfs(lay+1, x+p[i], y, costY, false);
		}
		else
		{
			if(y+v[i]-x<=d)
				dfs(lay+1, x, y+p[i], costY+v[i], false);
			else
				dfs(lay+1, x, y+p[i], costY+v[i], true);
		}
		visit[i] = false;
	}
}
void init()
{
	scanf("%d %d", &n, &d);
	memset(visit, false, sizeof(visit));
	maxCost = 0;
	int i;
	for(i = 0; i < n; i++)
		scanf("%d %d", &p[i], &v[i]);
}
int main()
{
	init();
	dfs(0, 0, 0, 0, true);
	printf("%d\n", maxCost);
	return 0;
}