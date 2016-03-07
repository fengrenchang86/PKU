#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int id;
	int len;
	int val;
}query[55555];
struct EDGE
{
	int x, y, len;
}edge[52000];
int father[55555];
int vset[55555];
int n, m, q;
void Init()
{
	int i;
	for (i = 0; i <= n; i++)
	{
		father[i] = i;
		vset[i] = 1;
	}
}
int GetFather(int k)
{
	if (k != father[k])
	{
		int t = GetFather(father[k]);
		father[k] = t;
	}
	return father[k];
}
int cmpID(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	return c->id > d->id;
}
int cmpVal(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	return c->len > d->len;
}
int cmpEdge(const void*a, const void*b)
{
	struct EDGE*c = (EDGE*)a;
	struct EDGE*d = (EDGE*)b;
	return c->len > d->len;
}
void Input()
{
	Init();
	int i, x, y, z;
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &edge[i].x, &edge[i].y, &edge[i].len);
	}
	qsort(edge, m, sizeof(edge[0]), cmpEdge);
	for (i = 0; i < q; i++)
	{
		scanf("%d", &query[i].len);
		query[i].id = i;
	}
	qsort(query, q, sizeof(query[0]), cmpVal);
}
void Solve()
{
	int i = 0, j = 0;
	int fx, fy, x, y;
	int ans = 0;
	while (i < m && j < q)
	{
		while (i < m && edge[i].len <= query[j].len)
		{
			fx = GetFather(edge[i].x);
			fy = GetFather(edge[i].y);
			if (fx != fy)
			{
				x = vset[fx];
				y = vset[fy];
				ans -= (x*(x-1)/2);
				ans -= (y*(y-1)/2);
				ans += (x+y)*(x+y-1)/2;
				father[fx] = fy;
				vset[fy] += vset[fx];
				vset[fx] = 0;
			}
			i++;
		}
		query[j].val = ans;
		j++;
	}
	while (j < q)
	{
		query[j].val = ans;
		j++;
	}
	qsort(query, q, sizeof(query[0]), cmpID);
	for (i = 0; i < q; i++)
	{
		printf("%d\n", query[i].val);
	}
}
int main()
{
	//scanf("%d %d %d", &n, &m, &q);
	while(scanf("%d %d %d", &n, &m, &q) != EOF)
	{
		Input();
		Solve();
	}
	return 0;
}


