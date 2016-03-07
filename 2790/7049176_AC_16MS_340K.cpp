
#include <iostream>
using namespace std;
int n, m;
int staus[500];
int msg[500];
bool a[500][500];
bool use[500];
int path[500];
bool flag;
void Input()
{
	int i, j;
	char k;
	char ch[1000];
	for (i = 0; i < n; i++)
	{
		msg[i] = 0;
		staus[i] = -1;
		scanf("%s", &ch);
		for (j = 0; j < m; j++)
		{
			if (ch[j] == '1')
			{
				msg[i]++;
				a[i][j] = 1;
			}
			else
			{
				a[i][j] = 0;
			}
		}
	}
	for (j = 0; j < m; j++)
	{
		use[j] = 0;
	}
}
void dfs(int lay)
{
	int i, j = path[lay-1];
	if (lay == m)
	{
		flag = true;
		return;
	}
	for (i = 0; i < n; i++)
	{
		if (staus[i] > 0 && !a[i][j])
		{
			return;
		}
	}
	for (i = 0; i < n; i++)
	{
		if (a[i][j])
		{
			if (staus[i] == -1)
			{
				staus[i] = msg[i] - 1;
			}
			else
			{
				staus[i]--;
			}
		}
	}
	for (i = 0; i < m; i++)
	{
		if (!use[i])
		{
			path[lay] = i;
			use[i] = 1;
			dfs(lay + 1);
			use[i] = 0;
			if (flag)
			{
				return;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		if (a[i][path[lay-1]])
		{
			staus[i]++;
			if (staus[i] == msg[i])
			{
				staus[i] = -1;
			}
		}
	}
}
int main()
{
	int i;
	scanf("%d %d", &n, &m);
	Input();
	flag = 0;
	path[0] = 0;
	use[0] = 1;
	dfs(1);
	if (flag)
	{
		for (i = 0; i < m; i++)
		{
			printf("%d\n", path[i]);
		}
	}
	return 0;
}