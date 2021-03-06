#include <iostream>
using namespace std;
int father[60000];
int relation[60000];
int n, m;
int GetFather(int k)
{
	if (father[k] != -1)
	{
		int x = father[k];
		father[k] = GetFather(father[k]);
		relation[k] = (relation[k] + relation[x]) % 3;
		return father[k];
	}
	else
	{
		relation[k] = 0;
		return k;
	}
}

int JudgeIsFalse(int x, int y, int nRelation)
{
	int fx = GetFather(x);
	int fy = GetFather(y);
	if (fx != fy)
	{
		father[fx] = fy;
		relation[fx] = (relation[y]-relation[x]+nRelation+6) % 3;
		return 0;
	}
	else if ((relation[x]-relation[y]+3)%3 == nRelation)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void Solve()
{
	int i, j;
	int d, x, y;
	for (i = 0; i <= n; i++)
	{
		father[i] = -1;
		relation[i] = 0;
	}
	int k = 0;
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &d, &x, &y);
		if (x > n || y > n)
		{
			j = 1;
		}
		else if (x == y && d != 1)
		{
			j = 1;
		}
		else
		{
			j = JudgeIsFalse(x, y, d-1);
		}
		k += j;
	}
	printf("%d\n", k);
}
int main()
{
	scanf("%d %d", &n, &m);
	Solve();
	return 0;
}