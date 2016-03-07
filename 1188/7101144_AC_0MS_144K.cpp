#include <iostream>
using namespace std;
int x, y, z, dx, dy, dz;
int n;
void Solve()
{
	int a, b, c, da, db, dc;
	int i, k;
	scanf("%d %d %d %d", &x, &y, &z, &k);
	dx = x + k;
	dy = y + k;
	dz = z + k;
	for (i = 1; i < n; i++)
	{
		scanf("%d %d %d %d", &a, &b, &c, &k);
		if (x == dx || y == dy || z == dz)
		{
			continue;
		}
		da = a + k;
		db = b + k;
		dc = c + k;
		if (dx <= a || da <= x || dy <= b || db <= y || dz <= c || dc <= z)
		{
			x = dx;
			continue;
		}
		if (x < a && da < dx)
		{
			x = a;
			dx = da;
		}
		else if (x < da && da < dx)
		{
			dx = da;
		}
		else if (x < a && a < dx)
		{
			x = a;
		}
		if (y < b && db < dy)
		{
			y = b;
			dy = db;
		}
		else if (y < db && db < dy)
		{
			dy = db;
		}
		else if (y < b && b < dy)
		{
			y = b;
		}
		if (z < c && dc < dz)
		{
			z = c;
			dz = dc;
		}
		else if (z < dc && dc < dz)
		{
			dz = c;
		}
		else if (z < c && c < dz)
		{
			z = c;
		}
	}
	printf("%d\n", (dx-x)*(dy-y)*(dz-z));
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			break;
		}
		Solve();
	}
	return 0;
}