#include <iostream>
using namespace std;
bool visit[7];
int a[7][3];
int ans;
int org;
void dfs(int lay, int k, int sum, int pos)
{
	if (lay == 5)
	{
		if (a[k][pos] != org)
		{
			return;
		}
		if (sum > ans)
		{
			ans = sum;
		}
		return;
	}
	visit[k] = true;
	int i;
	for (i = 0; i < 6; i++)
	{
		if(!visit[i])
		{
			if(a[k][pos] == a[i][0])
			{
				dfs(lay + 1, i, sum + a[i][2], 1);
			}
			if (a[k][pos] == a[i][1])
			{
				dfs(lay + 1, i, sum + a[i][0], 2);
			}
			if (a[k][pos] == a[i][2])
			{
				dfs(lay + 1, i, sum + a[i][1], 0);
			}
		}
	}
	visit[k] = false;
}
void Solve()
{
	memset(visit, false, sizeof(visit));
	ans = -1;
	org = a[0][2];
	dfs(0, 0, a[0][1], 0);

	org = a[0][0];
	dfs(0, 0, a[0][2], 1);

	org = a[0][1];
	dfs(0, 0, a[0][0], 2);
	if (ans == -1)
	{
		printf("none\n");
	}
	else
	{
		printf("%d\n", ans);
	}
}
int main()
{
	int i;
	char ch;
	while(1)
	{
		for (i = 0; i < 6; i++)
		{
			scanf("%d %d %d", &a[i][2], &a[i][1], &a[i][0]);
		}
		scanf(" %c", &ch);
		Solve();
		if (ch == '$')
		{
			break;
		}
	}
	return 0;
}