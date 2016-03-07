#include <iostream>
using namespace std;
int father[110000];
int same[110000];
int n, m;
void Init()
{
	int i;
	for (i = 1; i <= n; i++)
	{
		same[i] = 0;
		father[i] = i;
	}
}
int GetFather(int v)
{
	if (father[v] == v)
	{
		return v;
	}
	int x = father[v];
	father[v] = GetFather(x);
	same[v] = (same[v] + same[x]) % 2;
	return father[v];
}
int Judge(int x, int y)
{
	int fx = GetFather(x);
	int fy = GetFather(y);
	if (fx != fy)
		return -1;
	else if (same[x] == same[y])
		return 0;
	else
		return 1;
}
void Join(int x, int y)
{
	int fx = GetFather(x);
	int fy = GetFather(y);
	father[fx] = fy;
	same[fx] = (same[x] + same[y] + 1) % 2;
}
void Solve()
{
	char ch;
	int i, k, x, y;
	for (i = 0; i < m; i++)
	{
		scanf(" %c %d %d", &ch, &x, &y);
		if (ch == 'D')
		{
			Join(x, y);
		}
		else
		{
			k = Judge(x, y);
			if (k == -1)
				printf("Not sure yet.\n");
			else if (k == 0)
				printf("In the same gang.\n");
			else
				printf("In different gangs.\n");
		}
	}
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d %d", &n, &m);
		Init();
		Solve();
	}
	return 0;
}