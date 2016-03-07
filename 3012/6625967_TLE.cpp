#include <iostream>
using namespace std;
int n, k, m;

__int64 acmPower(int x, int y)
{
	if (y == 0)
	{
		return 1;
	}
	else if (y == 1)
	{
		return x;
	}
	else if (y % 2 == 0)
	{
		__int64 z = acmPower(x, y/2);
		return (z % m * z % m) % m;
	}
	else
	{
		__int64 z=  acmPower(x, y/2);
		return (x%m * z % m * z % m) % m;
	}
}
void Input()
{
	scanf("%d %d %d", &n, &k, &m);
	int nSize = k / 4 + 1;
	int x;
	switch(k % 4)
	{
	case 0:
		x = 1;
		break;
	case 1:
		x = 10;
		break;
	case 2:
		x = 100;
		break;
	case 3:
		x = 1000;
		break;
	}
	__int64 t = x;
	while (nSize > 1)
	{
		t = (__int64)(t) % (__int64)m;
		nSize--;
		t *= 10000;
	}
	t ++;
	t = t % m;
//	int x = Mod(acm);
	__int64 ans = acmPower(t, n);
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