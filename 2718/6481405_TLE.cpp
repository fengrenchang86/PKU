#include <iostream>
using namespace std;
int c[20];
bool visit[20];
char ch[1000];
int n;
__int64 ans;
int v1, v2;
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
	v1 = v2 = 1;
	for (i = 0; i < n/2; i++)
	{
		v1 *= 10;
	}
	for (i = 0; i < n - n/2; i++)
	{
		v2 *= 10;
	}
}
void dfs(int lay, __int64 x)
{
	int i;
	if (lay == n)
	{
		__int64 j;
		__int64 x1, x2;
		x1 = x / v1;
		x2 = x % v1;
		if (abs(x1-x2)<ans)
		{
			ans = abs(x1-x2);
		}
		if (v1 != v2)
		{
			x1 = x / v2;
			x2 = x % v2;
			if (abs(x1-x2)<ans)
			{
				ans = abs(x1-x2);
			}
		}
		return;
	}
	for (i = 0; i < 10; i++)
	{
		if (visit[i])
		{
			visit[i] = 0;
			c[lay] = i;
			dfs(lay + 1, (__int64)x * (__int64)10 + (__int64)i);
			visit[i] = 1;
		}
	}
}
void Solve()
{
	Input();
	ans = 2000000000;
	dfs(0, 0);
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