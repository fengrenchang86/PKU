#include <iostream>
using namespace std;
struct BIGNUM
{
	int nSize;
	int dig[50];
}t[60];
int n;
int a[60];
void ShowBigNumber(BIGNUM *x)
{
	printf("%d", x->dig[x->nSize-1]);
	int i;
	for (i = x->nSize - 2; i >= 0; i--)
	{
		printf("%04d", x->dig[i]);
	}
}
void Multiply(BIGNUM *x, int k, BIGNUM *y)
{
	int i;
	for (i = 0; i < x->nSize; i++)
	{
		y->dig[i] = x->dig[i] * k;
	}
	y->dig[i] = 0;
	for (i = 0; i < x->nSize; i++)
	{
		y->dig[i+1] += y->dig[i] / 10000;
		y->dig[i] %= 10000;
	}
	if (y->dig[i])
	{
		y->nSize = x->nSize + 1;
	}
	else
	{
		y->nSize = x->nSize;
	}
}
void Add(BIGNUM *x, BIGNUM *y, BIGNUM *z)
{
	int i, nCarry = 0;
	z->dig[0] = 0;
	for (i = 0; i < x->nSize && i < y->nSize; i++)
	{
		z->dig[i] = (x->dig[i] + y->dig[i]);
	}
	while (i < x->nSize)
	{
		z->dig[i] = (x->dig[i]);
		i++;
	}
	while (i < y->nSize)
	{
		z->dig[i] = y->dig[i];
		i++;
	}
	z->nSize = i;
	z->dig[i] = 0;
	for (i = 0; i < z->nSize; i++)
	{
		z->dig[i+1] += (z->dig[i] / 10000);
		z->dig[i] %= 10000;
	}
	if (z->dig[i])
	{
		z->nSize++;
	}
}
void Init()
{
	t[1].nSize = 1;
	t[1].dig[0] = 1;
	int i;
	for (i = 2; i <= 50; i++)
	{
		Multiply(&t[i-1], i, &t[i]);
	}
}
bool Input()
{
	char ch[1000];
	scanf(" %s", &ch);
	if (ch[0] != '(')
	{
		return false;
	}
	int i = 1, j = 0;
	n = 0;
	while (ch[i] != 0)
	{
		if (ch[i] < '0' || ch[i] > '9')
		{
			i++;
			continue;
		}
		while (ch[i] >= '0' && ch[i] <= '9')
		{
			n *= 10;
			n += (ch[i] - '0');
			i++;
		}
		break;
	}
	while (ch[i] != 0)
	{
		if (ch[i] < '0' || ch[i] > '9')
		{
			i++;
			continue;
		}
		a[j] = 0;
		while (ch[i] >= '0' && ch[i] <= '9')
		{
			a[j] *= 10;
			a[j] += (ch[i] - '0');
			i++;
		}
		j++;
	}
	return true;
}
void Solve(int tc)
{
	BIGNUM x, y, z;
	int i, j, k;
	x.nSize = 1;
	x.dig[0] = 1;
	for (i = 0; i < n; i++)
	{
		k = 0;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
				k++;
		}
		if (k != 0)
		{
			Multiply(&t[n-i-1], k, &y);
			Add(&x, &y, &z);
			x = z;
		}
	}
	if (tc != 1)
		printf(",");
	ShowBigNumber(&x);
}
int main()
{
	Init();
	int tc = 1;
	while (Input())
	{
		Solve(tc);
		tc++;
	}
	printf("\n");
	return 0;
}