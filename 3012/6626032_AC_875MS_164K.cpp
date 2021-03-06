#include <iostream>
using namespace std;
int n, k, m;

int acmPower(int x, int y)
{
	if (y == 0)
	{
		return 1;
	}
	else if (y == 1)
	{
		return x % m;
	}
	else if (y % 2 == 0)
	{
		__int64 z = acmPower(x, y/2);
		return (int)((z % m * z % m) % m);
	}
	else
	{
		__int64 z=  acmPower(x, y/2);
		return (int)((x%m * z % m * z % m) % m);
	}
}
void Input()
{
	scanf("%d %d %d", &n, &k, &m);
	int ans;
	ans = acmPower(10, k);
	ans = acmPower(ans + 1, n);
	printf("%d\n", (int)ans);
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		Input();
	}
	return 0;
}