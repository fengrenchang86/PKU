#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
struct ac
{
	int x, y;
}t[600];
struct wa
{
	int id1, id2;
	double len;
	int acm;
}a[260000];
int n, m;
int father[600];
int GetFather(int v)
{
	if (father[v] == v)
	{
		return v;
	}
	father[v] = GetFather(father[v]);
	return father[v];
}
int cmp(const void*a, const void*b)
{
	struct wa*c = (wa*)a;
	struct wa*d = (wa*)b;
	if (c->len > d->len)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
void Input()
{
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &t[i].x, &t[i].y);
		father[i] = i;
	}
}
void Solve()
{
	int i, j, k = 0;
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			a[k].id1 = i;
			a[k].id2 = j;
			a[k].len = (double)(t[i].x - t[j].x) * (double)(t[i].x - t[j].x) + 
				(double)(t[i].y - t[j].y) * (double)(t[i].y - t[j].y);
			a[k].len = sqrt(a[k].len);
			a[k].acm = -1;
			k++;
		}
	}
	qsort(a, k, sizeof(a[0]), cmp);
	j = 0;
	int fx, fy, z = 0;
	for (i = 0; i < k && z < n; i++)
	{
		fx = GetFather(a[i].id1);
		fy = GetFather(a[i].id2);
		if (fx != fy)
		{
			father[fx] = fy;
			a[i].acm = z;
			z++;
		}
	}
	if (m == 0)
	{
		m = 1;
	}
	double ans = 0.0;
	for (i = 0; i < k; i++)
	{
		if (a[i].acm == n-1-m)
		{
			ans = a[i].len;
			break;
		}
	}
	printf("%.2lf\n", ans);
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d %d", &m, &n);
		Input();
		Solve();
	}
	return 0;
}