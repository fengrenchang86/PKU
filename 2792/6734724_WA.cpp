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
		if (ch[pos-1] == '+')
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
	Factor(nType);
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
		if (ch[pos-1] == '*')
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
	return 1;
}

int main()
{
	int i;
	while (scanf(" %s", &ch) != EOF)
	{
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