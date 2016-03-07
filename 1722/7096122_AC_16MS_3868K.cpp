#include <iostream>
#include <queue>
using namespace std;
#define INF 1000000000

int a[120];
int n, m;
short path[120][20010];
bool v[120][20010];
bool oper[120];
void MakeOper(int pos, short val)
{
	if (pos == 1)
	{
		return;
	}
	short x = path[pos][val];
	if (x < val)
	{
		oper[pos] = 1;
	}
	else
	{
		oper[pos] = 0;
	}
	MakeOper(pos-1, x);
}
void ShowAns()
{
	int i, j = 0;
	for (i = 1; i < n; i++)
	{
		if (oper[i+1])
		{
			printf("%d\n", i-j);
			j++;
		}
	}
	while (j < n - 1)
	{
		printf("1\n");
		j++;
	}
}
void Solve()
{
	int i, j;
	memset(v, 0, sizeof(v));
	j = a[1] - a[2];
	path[2][j+10000] = a[1] + 10000;
	v[2][j+10000] = 1;
	for (i = 3; i <= n; i++)
	{
		for (j = 0; j <= 20100; j++)
		{
			if (v[i-1][j-a[i]])
			{
				path[i][j] = j-a[i];
				v[i][j] = 1;
			}
			else if (v[i-1][j+a[i]])
			{
				path[i][j] = j + a[i];
				v[i][j] = 1;
			}
		}
	}
	MakeOper(n, short(m+10000));
	ShowAns();
}
void Input()
{
	int i;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
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