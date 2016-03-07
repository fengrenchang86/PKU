#include <iostream>
#include <stdlib.h>
using namespace std;
#define N 102
#define inf 2000000000
int n, m;
struct ac
{
	int x, y, len;
}t[N*N];
bool visit[N];
int father[N];
int GetFather(int k)
{
	while(father[k] != k)
		k = father[k];
	return k;
}
int cmp(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	return c->len - d->len;
}
void Input()
{
	int i;
	for(i = 0; i <= n; i++)
		father[i] = i;
	for(i = 0; i < m; i++)
	{
		scanf("%d %d %d", &t[i].x, &t[i].y, &t[i].len);
	}
	qsort(t, m, sizeof(t[0]), cmp);
}
int Kru(int edge)
{
	int i, j, fx, fy, x, y;
	for(i = 0; i <= m; i++)
		father[i] = i;
	memset(visit, false, sizeof(visit));
	j = 0;
	for(i = edge; i < m && j < n - 1; i++)
	{
		x = t[i].x;
		y = t[i].y;
		if(visit[x] == false)
			fx = -1;
		else
			fx = GetFather(x);
		if(visit[y] == false)
			fy = -1;
		else
			fy = GetFather(y);
		if(fx == -1 && fy == -1)
		{
			visit[x] = visit[y] = true;
			father[x] = y;
			j ++;
		}
		else if(fx == -1)
		{
			visit[x] = true;
			father[x] = fy;
			j++;
		}
		else if(fy == -1)
		{
			visit[y] = true;
			father[y] = fx;
			j++;
		}
		else if(fx != fy)
		{
			father[fx] = fy;
			j++;
		}
	}
	if(j == n-1)
		return t[i-1].len - t[edge].len;
	else
		return inf;
}
void Solve()
{
	int i, j, k = inf;
	for(i = 0; i < m; i++)
	{
		j = Kru(i);
		if(j < k)
			k = j;
	}
	if(k == inf)
		printf("-1\n");
	else
		printf("%d\n", k);
}
int main()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		if(n == 0 && m == 0)
			break;
		Input();
		Solve();
	}
	return 0;
}