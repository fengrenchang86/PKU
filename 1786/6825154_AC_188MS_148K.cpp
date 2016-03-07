#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int nType;
	int nDig;
}t[4][13];
char str[1000];
char ch;
char table[4][10] = {"South", "West", "North", "East"};
int cmp(const void*a, const void*b)
{
	struct ac *c = (ac*)a;
	struct ac *d = (ac*)b;
	if (c->nType != d->nType)
	{
		return c->nType - d->nType;
	}
	else
	{
		return c->nDig - d->nDig;
	}
}
int x, y;
void Input()
{
	scanf(" %s", &str);
	ac p;
	int i, n = strlen(str);
	for (i = 0; i < n; i += 2)
	{
		if (str[i] == 'C')
		{
			p.nType = 0;
		}
		else if (str[i] == 'D')
		{
			p.nType = 1;
		}
		else if (str[i] == 'S')
		{
			p.nType = 2;
		}
		else
		{
			p.nType = 3;
		}
		if (str[i+1] >= '2' && str[i+1] <= '9')
		{
			p.nDig = str[i+1] - '0';
		}
		else if (str[i+1] == 'A')
		{
			p.nDig = 14;
		}
		else if (str[i+1] == 'T')
		{
			p.nDig = 10;
		}
		else if (str[i+1] == 'J')
		{
			p.nDig = 11;
		}
		else if (str[i+1] == 'Q')
		{
			p.nDig = 12;
		}
		else
		{
			p.nDig = 13;
		}
		t[x%4][y] = p;
		x++;
		if (x % 4 == 0)
		{
			y++;
		}
	}
}
char ACM(int dig)
{
	if (dig >= 2 && dig <= 9)
	{
		return char(dig + '0');
	}
	else if (dig == 14)
	{
		return 'A';
	}
	else if (dig == 10)
	{
		return 'T';
	}
	else if (dig == 11)
	{
		return 'J';
	}
	else if (dig == 12)
	{
		return 'Q';
	}
	else
		return 'K';
}
char WF(int ntype)
{
	switch (ntype)
	{
	case 0:
		return 'C';
	case 1:
		return 'D';
	case 2:
		return 'S';
	case 3:
		return 'H';
	default:
		break;
	}
	return 'C';
}
int main()
{
	int k;
	int tc = 1;
	while (scanf(" %c", &ch) != EOF)
	{
		if (ch == '#')
		{
			break;
		}
		if (tc != 1)
		{
			printf("\n");
		}
		tc++;
		switch (ch)
		{
		case 'E':
			k = 0;
			break;
		case 'S':
			k = 3;
			break;
		case 'W':
			k = 2;
			break;
		case 'N':
			k = 1;
			break;
		default:
			break;
		}
		x = y = 0;
		Input();
		Input();
		qsort(t[0], 13, sizeof(t[0][0]), cmp);
		qsort(t[1], 13, sizeof(t[1][0]), cmp);
		qsort(t[2], 13, sizeof(t[2][0]), cmp);
		qsort(t[3], 13, sizeof(t[3][0]), cmp);
		int i, j;
		for (i = 0; i < 4; i++)
		{
			printf("%s player:\n+---+---+---+---+---+---+---+---+---+---+---+---+---+\n|", table[i]);
			for (j = 0; j < 13; j++)
			{
				char c = ACM(t[k][j].nDig);
				printf("%c %c|", c, c);
			}
			printf("\n|");
			for (j = 0; j < 13; j++)
			{
				char c = WF(t[k][j].nType);
				printf(" %c |", c);
			}
			printf("\n|");
			for (j = 0; j < 13; j++)
			{
				char c = ACM(t[k][j].nDig);
				printf("%c %c|", c, c);
			}
			printf("\n+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
			k++;
			k %= 4;
		}
	}

	
	return 0;
}