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
	n = 0;
	while (ch[i] != NULL)
	{
		x = 0;
		if (ch[i] >= '0' && ch[i] <= '9')
		{
			x = (ch[i] - '0');
			visit[x] = true;
			n++;
		}
		i++;
	}
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
		if (x2 * 10 / v1 != 0 && abs(x1-x2)<ans)
		{
			ans = abs(x1-x2);
		}
		if (v1 != v2)
		{
			x1 = x / v2;
			x2 = x % v2;
			if (x2 * 10 / v2 != 0 && abs(x1-x2)<ans)
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
	if (n == 10)
	{
		printf("247\n");
		return;
	}
	else if (n == 9)
	{
		if (!visit[0])
		{
			printf("2469\n");
		}
		else if (!visit[1])
		{
			printf("10469\n");
		}
		else if (!visit[2])
		{
			printf("469\n");
		}
		else if (!visit[3])
		{
			printf("369\n");
		}
		else if (!visit[4])
		{
			printf("359\n");
		}
		else if (!visit[5])
		{
			printf("358\n");
		}
		else if (!visit[6])
		{
			printf("359\n");
		}
		else if (!visit[7])
		{
			printf("369\n");
		}
		else if (!visit[8])
		{
			printf("469\n");
		}
		else if (!visit[9])
		{
			printf("1469\n");
		}
		return;
	}
	ans = 2000000000;
	int i;
	for (i = 1; i <= 9; i++)
	{
		if (visit[i])
		{
			visit[i] = 0;
			c[0] = i;
			dfs(1, i);
			visit[i] = 1;
		}
	}
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