#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
using namespace std;
#define INF 2000000000
struct ac
{
	int x, y;
}t[111000];
int m, n;
vector<ac>vec;
int cmp(const void *a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	if (c->x != d->x)
	{
		return c->x - d->x;
	}
	else
	{
		return c->y - d->y;
	}
}
void Input()
{
	n = 0;
	while (scanf("%d %d", &t[n].x, &t[n].y) != EOF)
	{
		if (t[n].x == 0 && t[n].y == 0)
		{
			break;
		}
		if (t[n].y < 0 || t[n].x > m)
		{
			continue;
		}
		n++;
	}
	qsort(t, n, sizeof(t[0]), cmp);
}
void Solve()
{
	int i, j, k;
	vec.clear();
	int x(0), y(-1);
	for (i = 0; i < n; i++)
	{
		y = k = -1;
		for (j = i; j < n && t[j].x <= x; j++)
		{
			if (t[j].y >= x && t[j].y > y)
			{
				y = t[j].y;
				k = j;
			}
		}
		if (k == -1)
		{
			printf("No solution\n");
			return;
		}
		vec.push_back(t[k]);
		x = t[k].y;
		if (x >= m)
		{
			break;
		}
	}
	if (vec.size() == 0 || vec[vec.size()-1].y < m)
	{
		printf("No solution\n");
		return;
	}
	printf("%d\n", vec.size());
	for (i = 0; i < vec.size(); i++)
	{
		printf("%d %d\n", vec[i].x, vec[i].y);
	}
}
int main()
{
	scanf("%d", &m);
	Input();
	Solve();
	return 0;
}