#include <iostream>
#include <stdlib.h>
using namespace std;
struct acm
{
	int x, y;
}p[12000];
int n;
int bx, ex, by, ey;
int g_dist;
int cmpX(const void*a, const void*b)
{
	struct acm*c = (acm*)a;
	struct acm*d = (acm*)b;
	return c->x > d->x ? 1 : -1;
}
int cmpY(const void*a, const void*b)
{
	struct acm *c = (acm*)a;
	struct acm *d = (acm*)b;
	return c->y > d->y ? 1 : -1;
}
void Input()
{
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &p[i].x, &p[i].y);
	}
}
void Solve()
{
	if (n % 2 == 1)
	{
		qsort(p, n, sizeof(p[0]), cmpX);
		bx = ex = p[n/2].x;
		qsort(p, n, sizeof(p[0]), cmpY);
		by = ey = p[n/2].y;
	}
	else
	{
		qsort(p, n, sizeof(p[0]), cmpX);
		bx = p[n/2-1].x;
		ex = p[n/2].x;
		qsort(p, n, sizeof(p[0]), cmpY);
		by = p[n/2-1].y;
		ey = p[n/2].y;
	}
	g_dist = 0;
	int i, j = 0;
	for (i = 0; i < n; i++)
	{
		g_dist += (abs(p[i].x - bx) + abs(p[i].y - by));
		if (p[i].x >= bx && p[i].x <= ex && p[i].y >= by && p[i].y <= ey)
		{
			j++;
		}
	}
	j = (ey - by + 1) * (ex - bx + 1) - j;
	if (j == 0)
	{
		bx--;
		ex++;
		by--;
		ey++;
		int dx, dy, dz = 1;
		int dis;
		g_dist = 2000000000;
		j = 0;
		for (dx = bx; dx <= ex; dx++)
		{
			for (dy = by; dy <= ey; dy++)
			{
				dz = 1;
				dis = 0;
				for (i = 0; i < n; i++)
				{
					dz = abs(p[i].x-dx) + abs(p[i].y - dy);
					if (dz == 0)
					{
						break;
					}
					dis += dz;
				}
				if (dz != 0)
				{
					if (dis < g_dist)
					{
						g_dist = dis;
						j = 1;
					}
					else if (dis == g_dist)
					{
						j++;
					}
				}
			}

		}

	}
	printf("%d %d\n", g_dist, j);
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		Input();
		Solve();
	}
	return 0;
}