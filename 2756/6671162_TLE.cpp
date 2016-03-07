#include <iostream>
#include <vector>
using namespace std;

struct BIGNUM
{
	int fuhao;
	vector<int>dig;
};
void acSubtract(BIGNUM *x, BIGNUM *y, BIGNUM *z);
void acPlus(BIGNUM *x, BIGNUM *y, BIGNUM *z)
{
	if (x->fuhao != y->fuhao)
	{
		y->fuhao *= -1;
		acSubtract(x, y, z);
		return;
	}
	z->dig.clear();
	int i, nCarry = 0;
	int n1 = x->dig.size(), n2 = y->dig.size();
	for (i = 0; i < n1 && i < n2; i ++)
	{
		z->dig.push_back((nCarry + x->dig[i] + y->dig[i]) % 10000);
		nCarry = (nCarry + x->dig[i] + y->dig[i]) / 10000;
	}
	while (i < n1)
	{
		z->dig.push_back((nCarry + x->dig[i]) % 10000);
		nCarry = (nCarry + x->dig[i]) / 10000;
		i++;
	}
	while (i < n2)
	{
		z->dig.push_back((nCarry + y->dig[i]) % 10000);
		nCarry = (nCarry + y->dig[i]) / 10000;
		i++;
	}
	if (nCarry)
	{
		z->dig.push_back(nCarry);
	}
	z->fuhao = x->fuhao;
}
int Compare(BIGNUM *x, BIGNUM *y)
{
	int n1 = x->dig.size();
	int n2 = y->dig.size();
	if (n1 > n2)
	{
		return 1;
	}
	else if (n1 < n2)
	{
		return -1;
	}
	else
	{
		int i;
		for (i = n1 - 1; i >= 0; i--)
		{
			if (x->dig[i] > y->dig[i])
			{
				return 1;
			}
			else if (x->dig[i] < y->dig[i])
			{
				return -1;
			}
		}
		return 0;
	}
}
void acSubtract(BIGNUM *x, BIGNUM *y, BIGNUM *z)
{
	if (x->fuhao != y->fuhao)
	{
		y->fuhao *= -1;
		acPlus(x, y, z);
		return;
	}
	int n1 = x->dig.size();
	int n2 = y->dig.size();
	z->dig.clear();
	if (Compare(x, y) == -1)
	{
		x->fuhao *= -1;
		y->fuhao *= -1;
		acSubtract(y, x, z);
		return;
	}
	z->fuhao = x->fuhao;
	int i, nCarry = 0;
	for (i = 0; i < n2; i++)
	{
		if (x->dig[i] - y->dig[i] - nCarry >= 0)
		{
			z->dig.push_back(x->dig[i] - y->dig[i] - nCarry);
			nCarry = 0;
		}
		else
		{
			z->dig.push_back(x->dig[i] - y->dig[i] - nCarry + 10000);
			nCarry = 1;
		}
	}
	while (i < n1)
	{
		if (x->dig[i] - nCarry >= 0)
		{
			z->dig.push_back(x->dig[i] - nCarry);
			nCarry = 0;
		}
		else
		{
			z->dig.push_back(x->dig[i] - nCarry + 10000);
			nCarry = 1;
		}
		i++;
	}
}
void ShowBigNum(BIGNUM *x)
{
	int n = x->dig.size() - 1;
	while (n > 0)
	{
		if (x->dig[n] == 0)
		{
			n--;
		}
	}
	if (n == 0 && x->dig[0] == 0)
	{
		printf("0\n");
		return;
	}
	if (x->fuhao == -1)
	{
		printf("-");
	}
	printf("%d", x->dig[n]);
	int i;
	for (i = n-1; i >= 0; i--)
	{
		printf("%04d", x->dig[i]);
	}
	printf("\n");
}
void ToBigNum(char *pCh, BIGNUM *x)
{
	x->dig.clear();
	int pos, i, j, k;
	if (pCh[0] == '+')
	{
		pos = 1;
		x->fuhao = 1;
	}
	else if (pCh[0] == '-')
	{
		pos = 1;
		x->fuhao = -1;
	}
	else
	{
		pos = 0;
		x->fuhao = 1;
	}
	j = 1;
	k = 0;
	for (i = strlen(pCh)-1; i >= pos; i--)
	{
		k += j * (pCh[i] - '0');
		j *= 10;
		if (j == 10000)
		{
			x->dig.push_back(k);
			k = 0;
			j = 1;
		}
	}
	if (j != 1)
	{
		x->dig.push_back(k);
	}
}
int main()
{
	char s1[65536], s2[65536];
	BIGNUM *x, *y, *z;
	x = new BIGNUM;
	y = new BIGNUM;
	z = new BIGNUM;
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%s %s", &s1, &s2);
		ToBigNum(s1, x);
		ToBigNum(s2, y);
		acPlus(x, y, z);
		ShowBigNum(z);
	}
	return 0;
}