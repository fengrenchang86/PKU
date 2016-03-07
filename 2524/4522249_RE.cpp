#include <iostream>
using namespace std;

int father[50010];
int root;
int n, m;
void GetFather(int x)
{
	if(father[x] == -1)
	{
		root = x;
		return;
	}
	GetFather(father[x]);
	father[x] = root;
}
void Solve(int tc)
{
	int i, x, y;
	for(i = 0; i <= n; i++)
		father[i] = -1;
	for(i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		if(x == y)
			continue;
		if(father[x] == -1)
		{
			GetFather(y);
			father[root] = x;
		}
		else if(father[y] == -1)
		{
			GetFather(x);
			father[root] = y;
		}
		else
		{
			GetFather(x);
			x = root;
			GetFather(y);
			y = root;
			if(x != y)
				father[x] = y;
		}
	}
	x = 0;
	for(i = 1; i <= n; i++)
	{
		if(father[i] == -1)
			x++;
	}
	printf("Case %d: %d\n", tc, x);
}
int main()
{
	int tc = 0;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		tc++;
		if(n + m == 0)
			break;
		Solve(tc);
	}
	return 0;
}