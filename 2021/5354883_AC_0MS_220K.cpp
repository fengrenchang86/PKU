#include <iostream>
#include <string>
using namespace std;
struct ac
{
	char name[30];
	int dis;
}t[300];

int c[120][120];

int n, m;
int cmp(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	if (c->dis != d->dis)
	{
		return d->dis - c->dis;
	}
	else
	{
		return strcmp(c->name, d->name);
	}
}
int Find(char *p)
{
	int i;
	for(i = 0; i < m; i++)
	{
		if(strcmp(p, t[i].name) == 0)
			return i;
	}
	strcpy(t[i].name, p);
	m++;
	return i;
}
void Input()
{
	scanf("%d", &n);
	strcpy(t[0].name, "Ted");
	m = 1;
	int i, dis;
	char a[50], b[50];
	int x, y;
	int j;
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= n; j++)
		{
			c[i][j] = 0;
		}
	}
	for(i = 0; i < n; i++)
	{
		scanf(" %s %s %d", &a, &b, &dis);
		x = Find(a);
		y = Find(b);
		c[x][y] = dis;
	}
}
void dfs(int v, int len)
{
	t[v].dis = len;
	int i;
	for(i = 0; i < m; i++)
	{
		if(c[v][i] > 0)
			dfs(i, len - c[v][i]);
	}
}
void Solve(int tc)
{
	int i;
	for(i = 0; i < m; i++)
		t[i].dis = 0;
	dfs(0, 100);
	qsort(t, m, sizeof(t[0]), cmp);
	printf("DATASET %d\n", tc);
	for(i = 1; i < m; i++)
	{
		printf("%s %d\n", t[i].name, t[i].dis);
	}
}
int main()
{
	int tc = 1;
	int i;
	scanf("%d", &tc);
	for(i = 1; i <= tc; i++)
	{
		Input();
		Solve(i);
	}
	return 0;
}