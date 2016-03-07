#include <iostream>
using namespace std;
#define INF 20000
struct BIGNUM
{
	int nSize;
	int dig[INF];
}t[20];
int overflow;
void Show(BIGNUM *a)
{
	int i;
	printf("%d", a->dig[a->nSize - 1]);
	for (i = a->nSize - 2; i >= 0; i--)
	{
		printf("%04d", a->dig[i]);
	}
	printf("\n");
}
void Cheng(BIGNUM *a, BIGNUM *b, BIGNUM *c)
{
	int i, j;
	c->nSize = a->nSize + b->nSize;
	for (i = 0; i <= c->nSize; i++)
	{
		c->dig[i] = 0;
	}
	for (i = 0; i < a->nSize; i++)
	{
		for (j = 0; j < b->nSize; j++)
		{
			c->dig[i+j] += a->dig[i] * b->dig[j];
			c->dig[i+j+1] += c->dig[i+j] / 10000;
			c->dig[i+j] %= 10000;
		}
	}
	for (i = 0; i < c->nSize; i++)
	{
		c->dig[i+1] += c->dig[i] / 10000;
		c->dig[i] %= 10000;
	}
	while (c->dig[i] == 0)
	{
		i--;
	}
	c->nSize = i + 1;
}
void Add(BIGNUM *a, BIGNUM *c)
{
	int i, nCarry = 1;
	for (i = 0; i < a->nSize; i++)
	{
		c->dig[i] = (a->dig[i] + nCarry) % 10000;
		nCarry = (a->dig[i] + nCarry) / 10000;
	}
	if (nCarry)
	{
		c->dig[i] = nCarry;
		c->nSize = a->nSize + 1;
	}
	else
	{
		c->dig[i] = 0;
		c->nSize = a->nSize;
	}
}
void Solve()
{
	t[0].dig[0] = 2;
	t[1].dig[0] = 3;
	t[0].nSize = 1;
	t[1].nSize = 1;
	BIGNUM x, y;
	int i, j;
	x = t[0];
	overflow = false;
	for (i = 2; i < 18; i++)
	{
		y = x;
		Cheng(&y, &t[i-1], &x);
		Add(&x, &t[i]);
	}
}
int main()
{
	Solve();
	int i, n;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
		{
			Show(&t[i]);
		}
	}
	{
	}
	return 0;
}