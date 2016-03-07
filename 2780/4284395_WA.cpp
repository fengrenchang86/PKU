#include <iostream>
using namespace std;
struct ac
{
	int x, y;
}a[1200];
int n, ans;
int c[2200][2200];
int gcd(int x, int y)
{
	if(x % y == 0)
		return y;
	return gcd(y, x % y);
}
void Init()
{
	int i, j;
	for(i = 0; i <= 2000; i++)
	{
		for(j = 0; j <= 2000; j++)
			c[i][j] = 0;
	}
}
void Input()
{
	int i;
	for(i = 0; i < n; i++)
		scanf("%d %d", &a[i].x, &a[i].y);
}
void Solve()
{
	int i, j, x, y, z;
	Init();
	ans = 0;
	for(i = 0; i < n; i++)
	{
		for(j = i+1; j < n; j++)
		{
			y = a[i].y - a[j].y;
			x = a[i].x - a[j].x;
			if(x < 0)
			{
				x *= -1;
				y *= -1;
			}
			if(x != 0 && y != 0)
			{
				z = gcd(abs(x), abs(y));
				x /= z;
				y /= z; 
			}
			else if(y != 0)
				y = 1;
			else if(x != 0)
				x = 1;
			x += 1000;
			y += 1000;
			c[x][y]++;
			if(ans < c[x][y])
				ans = c[x][y];
		}
	}
	printf("%d\n", ans);
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