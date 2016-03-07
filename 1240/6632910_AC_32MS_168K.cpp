#include <iostream>
using namespace std;

char str1[100], str2[100];

int c[30][30];
int a[256];
int n;

__int64 dfs(int pos1, int pos2, int len)
{
	pos1++;
	len--;
	if (len == 0)
	{
		return 1;
	}
	int i, j, k;
	__int64 ans = 1;
	__int64 t;
	j = 0;
	for (i = 0; i < len;)
	{
		k = a[str1[pos1+i]];
		t = dfs(pos1 + i, pos2 + i, k - pos2 - i+ 1);
		ans *= t;
		j++;
		i += (k-pos2 - i +1);
	}
	ans *= c[n][j];
	return ans;
}
void Solve()
{
	scanf(" %s %s", str1, str2);
	memset(a, 0, sizeof(a));
	int i, len = strlen(str2);
	for (i = 0; i < len; i++)
	{
		a[str2[i]] = i;
	}
	__int64 ans = dfs(0, 0, len);
	printf("%I64d\n", ans);
}
int main()
{
	int i, j;
	for (i = 0; i <= 30; i++)
	{
		c[i][0] = 0;
		c[i][1] = i;
	}
	for (i = 2; i <= 20; i++)
	{
		for (j = 2; j <= i; j++)
		{
			c[i][j] = c[i-1][j] + c[i-1][j-1];
		}
	}
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			break;
		}
		Solve();
	}
	return 0;
}