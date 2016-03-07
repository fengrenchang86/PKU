#include <iostream>
using namespace std;
struct ac
{
	char chExp[300];
	int val;
	int visit;
}acm[26][10];
int flag, m;
int Exp(char *ch, int &pos);
int A(char *ch, int &pos);
int B(char *ch, int &pos);
int C(char *ch, int &pos);
int Exp(char *ch, int &pos)
{
	if (ch[0] == 0)
	{
		return 0;
	}
	int x = A(ch, pos);
	int op;
	while (ch[pos] == '+' || ch[pos] == '-')
	{
		if (ch[pos] == '+')
		{
			op = 1;
		}
		else
		{
			op = -1;
		}
		pos++;
		x += op * A(ch, pos);
		if (flag == -1)
		{
			return 0;
		}
	}
	return x;
}
int A(char *ch, int &pos)
{
	int x = B(ch, pos), y;
	int op;
	while (ch[pos] == '*' || ch[pos] == '/')
	{
		if (ch[pos] == '*')
		{
			op = 1;
		}
		else
		{
			op = -1;
		}
		pos++;
		if (op == 1)
		{
			x *= B(ch, pos);
		}
		else
		{
			y = B(ch, pos);
			if (y == 0)
			{
				x = 0;
			}
			else
			{
				x /= y;
			}
		}
		if (flag == -1)
		{
			return 0;
		}
	}
	return x;
}
int B(char *ch, int &pos)
{
	int x = 0;
	if (ch[pos] == '(')
	{
		pos++;
		x = Exp(ch, pos);
		pos++;
	}
	else
	{
		x = C(ch, pos);
	}
	if (flag == -1)
	{
		return 0;
	}
	return x;
}
int C(char *ch, int &pos)
{
	if (flag == -1)
	{
		return 0;
	}
	int x;
	if (ch[pos] >= '0' && ch[pos] <= '9' || ch[pos] == '-')
	{
		int op = 1;
		if (ch[pos] == '-')
		{
			op = -1;
			pos++;
		}
		x = 0;
		while (ch[pos] >= '0' && ch[pos] <= '9')
		{
			x *= 10;
			x += (ch[pos]-'0');
			pos++;
		}
		x *= op;
	}
	else
	{
		int i = ch[pos++] - 'A';
		int j = ch[pos++] - '0';
		int k = 0;
		if (acm[i][j].visit == 0)
		{
			acm[i][j].visit = 1;
			if (acm[i][j].chExp[0] == NULL)
			{
				x = 0;
			}
			else
			{
				x = Exp(acm[i][j].chExp, k);
			}
			acm[i][j].val = x;
			acm[i][j].visit = 2;
		}
		else if (acm[i][j].visit == 1)
		{
			flag = -1;
			return 0;
		}
		else
		{
			x = acm[i][j].val;
		}
	}
	return x;
}
void Input()
{
	int i, j, k, x, y;
	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 10; j++)
		{
			acm[i][j].chExp[0] = 0;
			acm[i][j].visit = 0;
			acm[i][j].val = 0;
		}
	}
	char ch[300];
	for (i = 0; i < m; i++)
	{
		cin.getline(ch, 300, '\n');
		if (ch[0] == 0)
		{
			continue;
		}
		k = 0;
		for (j = 0; ch[j] != 0; j++)
		{
			if (ch[j] >= '0' && ch[j] <= '9' ||
				ch[j] >= 'A' && ch[j] <= 'Z' ||
				ch[j] == '(' || ch[j] == ')' ||
				ch[j] == '+' || ch[j] == '-' ||
				ch[j] == '*' || ch[j] == '/')
			{
				ch[k++] = ch[j];
			}
		}
		ch[k] = 0;
		x = ch[0] - 'A';
		y = ch[1] - '0';
		for (j = 2; ch[j] != 0; j++)
		{
			acm[x][y].chExp[j-2] = ch[j];
		}
		acm[x][y].chExp[j-2] = 0;
	}
}
int main()
{
	int pos = 0 ;
	while (scanf("%d", &m) != EOF)
	{
		cin.ignore();
		Input();
		acm[0][1].visit = 1;
		flag = 0;
		pos = 0;
		int ans = Exp(acm[0][1].chExp, pos);
		if (flag == 0)
		{
			printf("%d\n", ans);
		}
		else
		{
			printf("1000000\n");
		}
	}
	return 0;
}