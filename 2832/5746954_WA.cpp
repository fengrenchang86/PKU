#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int id;
	int len;
	int val;
}query[55555];
struct ACMEDGE
{
	int x, y, len;
}edge[55555];
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
		father[k] = GetFather(father[k]);
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
	struct ACMEDGE*c = (ACMEDGE*)a;
	struct ACMEDGE*d = (ACMEDGE*)b;
	return c->len > d->len;
}
void Input()
{
	Init();
	int i;
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d", &edge[i].x, &edge[i].y, &edge[i].len);
	}
	qsort(edge, m, sizeof(ACMEDGE), cmpEdge);
	for (i = 0; i < q; i++)
	{
		scanf("%d", &query[i].len);
		query[i].id = i;
	}
	qsort(query, q, sizeof(ac), cmpVal);
}
void Solve()
{
	int i = 0, j = 0;
	int fx, fy, xx, yy;
	int ans = 0;
	while (j < q)
	{
		while (i < m && edge[i].len <= query[j].len)
		{
			fx = GetFather(edge[i].x);
			fy = GetFather(edge[i].y);
			if (fx != fy)
			{
				xx = vset[fx];
				yy = vset[fy];
				ans -= (xx*(xx-1)/2);
				ans -= (yy*(yy-1)/2);
				ans += (xx+yy)*(xx+yy-1)/2;
				father[fx] = fy;
				vset[fy] += vset[fx];
			}
			i++;
		}
		query[j].val = ans;
		j++;
	}
	qsort(query, q, sizeof(ac), cmpID);
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


