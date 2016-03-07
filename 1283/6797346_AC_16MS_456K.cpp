#include <iostream>
using namespace std;

struct BIGNUM
{
	__int64 dig[202];
}t[202];

void Multi(BIGNUM *a, BIGNUM *b)
{
	int i, j;
	BIGNUM c;
	for (i = 0; i <= 200; i++)
	{
		c.dig[i] = 0;
	}
	for (i = 0; i <= 200; i++)
	{
		for (j = 0; j <= 200 - i; j++)
		{
			if (a->dig[i] != 0 && b->dig[j] != 0)
			{
				c.dig[i+j] += a->dig[i] * b->dig[j];
			}
		}
	}
	for (i = 0; i <= 200; i++)
	{
		b->dig[i] = c.dig[i];
	}
}
void Solve()
{
	int i, j, k;
	for (i = 0; i <= 200; i++)
	{
		t[0].dig[i] = 0;
	}
	for (i = 1; i <= 200; i++)
	{
		for (j = 0; j <= 200; j+=i)
		{
			if (j % i == 0)
			{
				t[i].dig[j] = 1;
			}
			else
			{
				t[i].dig[j] = 0;
			}
		}
	}
	for (i = 2; i <= 200; i++)
	{
		Multi(&t[i-1], &t[i]);
	}
}
int main()
{
	Solve();
	int x, y;
	while (scanf("%d %d", &x, &y) != EOF)
	{
		if (x + y == 0)
		{
			break;
		}
		printf("%lld\n", t[y].dig[x] - t[y-1].dig[x]);
	}
	return 0;
}
