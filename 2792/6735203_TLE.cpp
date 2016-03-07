#include <iostream>
using namespace std;
char ch[1200];
bool v[1200];
int pos;
int Expression(int nType);
int Term(int nType);
int Factor(int nType);
int Expression(int nType)
{
	int t = 1;
	Term(nType);
	while (ch[pos] == '+' || ch[pos] == '-')
	{
		if (nType == 1)
		{
			if (ch[pos] == '+')
			{
				ch[pos] = '-';
			}
			else
			{
				ch[pos] = '+';
			}
		}
		pos++;
		if (nType == -1)
		{
			Term(-1);
		}
		else if (ch[pos-1] == '+')
		{
			Term(0);
		}
		else
		{
			Term(1);
		}
		t++;
	}
	return t;
}
int Term(int nType)
{
	int p = pos;
	int t = Factor(-1);
	if (t == 1 || ch[pos] != '*' && ch[pos] != '/')
	{
		pos = p;
		Factor(nType);
	}
	while (ch[pos] == '*' || ch[pos] == '/')
	{
		if (nType == 3)
		{
			if (ch[pos] == '*')
			{
				ch[pos] = '/';
			}
			else
			{
				ch[pos] = '*';
			}
		}
		pos++;
		if (nType == -1)
		{
			Factor(-1);
		}
		else if (ch[pos-1] == '*')
		{
			Factor(2);
		}
		else
		{
			Factor(3);
		}
	}
	return 1;
}
int Factor(int nType)
{
	int t = 1;
	if (ch[pos] == '(')
	{
		pos++;
		int p = pos;
		if (nType == 2 || nType == 3)
		{
			t = Expression(-1);
			if (t == 1)
			{
				pos = p;
				v[pos-1] = 0;
				t = Expression(nType);
				v[pos] = 0;
				pos++;
			}
			else
			{
				pos++;
			}
		}
		else if (nType == 0 || nType == 1)
		{
			v[pos-1] = 0;
			t = Expression(nType);
			v[pos] = 0;
			pos++;
		}
		else
		{
			t = Expression(nType);
			pos++;
		}
	}
	else
	{
		pos ++;
	}
	return t;
}
int s[1200];
int main()
{
	int i, top, x, y;
	while (scanf(" %s", &ch) != EOF)
	{
		top = 0;
		x = y = -1;
		for (i = 0; ch[i] != NULL; i++)
		{
			if (ch[i] == '(')
			{
				s[top] = i;
				top++;
			}
			else if (ch[i] == ')')
			{
				if (s[top-1] + 1 == x && y + 1 == i)
				{
					ch[x] = ch[y] = '.';
				}
				x = s[top-1];
				y = i;
				top--;
			}
		}
		x = 0;
		for (i = 0; ch[i] != NULL; i++)
		{
			if (ch[i] != '.')
			{
				ch[x] = ch[i];
				x++;
			}
		}
		ch[x] = 0;
		memset(v, 1, sizeof(v));
		pos = 0;
		Expression(0);
		for (i = 0; ch[i] != NULL; i++)
		{
			if (v[i])
			{
				printf("%c", ch[i]);
			}
		}
		printf("\n");
	}
	return 0;
}