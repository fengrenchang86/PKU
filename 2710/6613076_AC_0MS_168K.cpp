#include <iostream>
using namespace std;
struct BIGNUM
{
	int nSize;
	int dig[200];
};
int a[1000];
int n,b,d,e;
void ShowBigNum(BIGNUM x)
{
	printf("%d", x.dig[x.nSize-1]);
	for (int i = x.nSize - 2; i >= 0; i--)
	{
		printf("%04d", x.dig[i]);
	}
	printf("\n");
}
void Multi(BIGNUM x, int k, BIGNUM &y)
{
	int i;
	for (i = 0; i < x.nSize; i++)
	{
		y.dig[i] = x.dig[i] * k;
	}
	y.dig[i] = 0;
	for (i = 0; i < x.nSize; i++)
	{
		y.dig[i+1] += y.dig[i]/10000;
		y.dig[i] %= 10000;
	}
	if (y.dig[i] > 0)
	{
		y.nSize = x.nSize + 1;
	}
	else
	{
		y.nSize = x.nSize;
	}
}
int Divide(BIGNUM x, int k, BIGNUM &y)
{
	int i, t = 0;
	for (i = x.nSize - 1; i >= 0; i--)
	{
		y.dig[i] = (t * 10000 + x.dig[i]) / k;
		t = (t * 10000 + x.dig[i]) % k;
	}
	x.nSize--;
	while (x.nSize > 0)
	{
		if (y.dig[x.nSize])
		{
			break;
		}
		x.nSize--;
	}
	y.nSize = x.nSize + 1;
	return t;
}
void Minue(BIGNUM x, int k, BIGNUM &y)
{
	int i = 0, t = 0;
	if (x.dig[0] >= k)
	{
		x.dig[0] -= k;
		y = x;
	}
	else
	{
		x.dig[0] -= k;
		for (i = 0; i < x.nSize && x.dig[i] < 0; i++)
		{
			x.dig[i] += 10000;
			x.dig[i+1] --;
		}
		if (x.dig[x.nSize-1] == 0)
		{
			x.nSize--;
		}
		y = x;
	}
}
int main()
{
	BIGNUM x, y, z;
	int i;
	int tc = 1;
	int nc;
	scanf("%d", &nc);
	for (tc = 1; tc <= nc; tc++)
	{
		scanf("%d %d %d %d", &n, &d, &b, &e);
		printf("Problem set %d: %d / %d, base 7 digits %d through %d: ", tc, n, d, b, e);
		n %= d;
		x.dig[0] = 1;
		x.nSize = 1;
		for (i = 0; i <= e; i++)
		{
			Multi(x, 7, y);
			x = y;
		}
		Multi(x, n, y);
		Divide(y, d, x);
		for (i = e; i >= 0; i--)
		{
			a[i] = Divide(x, 7, y);
			x = y;
		}
		for (i = b; i <= e; i++)
		{
			printf("%d", a[i]);
		}
		printf("\n");
	}
	return 0;
}