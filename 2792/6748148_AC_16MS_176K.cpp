#include <iostream>
using namespace std;
char ch[1200];
bool v[1200];
int s[1200];
int match[1200];
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
		if (nType == 2)
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
		if (nType == 0)
		{
			Term(0);
		}
		else if (ch[pos-1] == '+')
		{
			Term(1);
		}
		else
		{
			Term(2);
		}
		t++;
	}
	return t;
}
int Term(int nType)
{
	int tmpPos = pos;
	int t = Factor(0);
	if (nType != 0 && (t == 1 || ch[pos] != '*' && ch[pos] != '/'))
	{
		pos = tmpPos;
		Factor(nType);
	}
	else if (nType != 0)
	{
		pos = tmpPos;
		Factor(-1);
	}
	while (ch[pos] == '*' || ch[pos] == '/')
	{
		if (nType == 4)
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
		int p = pos;
		t = Factor(0);
		pos = p;
		if (nType == 0)
		{
			pos = match[p] + 1;
		}
		else if (ch[pos-1] == '*')
		{
			if (t == 1)
			{
				Factor(3);
			}
			else
			{
				Factor(-1);
			}
		}
		else if (ch[pos-1] == '/')
		{
			if (t == 1)
			{
				Factor(4);
			}
			else
			{
				Factor(-1);
			}
		}
	}
	return 1;
}
int Factor(int nType)
{
	if (nType == 0 && s[pos] > 0)
	{
		int pp = pos;
		pos = match[pos] + 1;
		return s[pp];
	}
	int tmpPos = pos;
	int t = 1;
	if (ch[pos] == '(')
	{
		pos++;
		t = Expression(abs(nType));
		if (nType > 0)
		{
			v[tmpPos] = 0;
			v[pos] = 0;
		}
		match[tmpPos] = pos;
		pos ++;
	}
	else
	{
		pos ++;
	}
	s[tmpPos] = t;
	return t;
}

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
		for (i = 0; i < x; i++)
		{
			s[i] = -1;
			match[i] = i;
		}
		pos = 0;
		Expression(1);
		for (i = 0; i < x; i++)
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

/*
a*(b*c)
a*((b+c))
((a-b)-(c-d)-(z*z*g/f)/(p*(t))*((y-u)))
q
a/(b*c/(d+e))-(f+g/(h/i))
(a-b)+c
a-(b+c)*(c/d)
a-((b+c))*(c/d)
(a+b)-c
a+(f+g/(h/i))
a-((b+c)*e*(c/d))
(a+b)*(c+d)
(a+b)*(c/d)
a-(b*c)+(d+f)/(q)
*/