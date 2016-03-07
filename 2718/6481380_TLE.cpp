#include <iostream>
using namespace std;
int c[20];
bool visit[20];
char ch[1000];
int n;
__int64 ans;
void Input()
{
	gets(ch);
	int i, j, x;
	memset(visit, 0, sizeof(visit));
	i = 0;
	j = 0;
	while (ch[i] != NULL)
	{
		x = 0;
		while (ch[i] >= '0' && ch[i] <= '9')
		{
			x *= 10;
			x += (ch[i] - '0');
			i++;
		}
		visit[x] = true;
		j++;
		i++;
	}
	n = j;
}
void dfs(int lay)
{
	int i;
	if (lay == n)
	{
		__int64 x = 0;
		__int64 j;
		__int64 x1, x2;
		for (i = 0; i < lay; i++)
		{
			x *= 10;
			x += c[i];
		}
		j = 10;
		while (1)
		{
			x1 = x / j;
			x2 = x % j;
			if (x1 == 0)
			{
				break;
			}
			if (abs(x1 - x2) < ans)
			{
				ans = abs(x1-x2);
			}
			j *= 10;
		}
		return;
	}
	for (i = 0; i < 10; i++)
	{
		if (visit[i])
		{
			visit[i] = 0;
			c[lay] = i;
			dfs(lay + 1);
			visit[i] = 1;
		}
	}
}
void Solve()
{
	Input();
	ans = 2000000000;
	dfs(0);
	printf("%I64d\n", ans);
}
int main()
{
	int x;
	scanf("%d", &x);
	cin.ignore();
	while (x--)
	{
		Solve();
	}
	return 0;
}