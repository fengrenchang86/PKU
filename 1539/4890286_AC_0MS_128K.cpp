#include <iostream>
using namespace std;
char szStr[200];
bool visit[30];
int val[30];
int pos;
int A();
int ope();
int Bope();
int Letter();
int Exp()
{
	int x = A();
	int op, y;
	op = ope();
	while(op)
	{
		y = A();
		x += op*y;
		op = ope();
	}
	return x;
}
int A()
{
	int x, y;
	x = Bope();
	if(x != 0)
	{
		y = Letter();
		val[y-1] += x;
		return y + x;
	}
	else
	{
		y = Letter();
		x = Bope();
		if(x != 0)
			val[y-1] += x;
		return y;
	}
	return 1;
}
int ope()
{
	if(szStr[pos] == '+')
	{
		pos++;
		return 1;
	}
	else if(szStr[pos] == '-')
	{
		pos++;
		return -1;
	}
	else
		return 0;
}
int Bope()
{
	if(szStr[pos] == '+' && szStr[pos+1] == '+')
	{
		pos += 2;
		return 1;
	}
	else if(szStr[pos] == '-' && szStr[pos+1] == '-')
	{
		pos += 2;
		return -1;
	}
	else
		return 0;
}
int Letter()
{
	if(szStr[pos] >= 'a' && szStr[pos] <= 'z')
	{
		pos++;
		visit[szStr[pos-1] - 'a'] = true;
		return (szStr[pos-1] - 'a' + 1);
	}
	else if(szStr[pos] >= 'A' && szStr[pos] <= 'Z')
	{
		pos++;
		visit[szStr[pos-1] - 'A'] = true;
		return (szStr[pos-1] - 'A' + 1);
	}
	else
		return 0;
}
int main()
{
	int i, j;
	char cStr[100];
	while(gets(cStr))
	{
		memset(visit, false, sizeof(visit));
		for(i = 0; i < 26; i++)
			val[i] = i+1;
		j = 0;
		for(i = 0; cStr[i] != NULL; i++)
		{
			if(cStr[i] != ' ')
				szStr[j++] = cStr[i];
		}
		szStr[j] = NULL;
		pos = 0;
		printf("Expression: %s\n    value = %d\n", cStr, Exp());
		for(i = 0; i < 26; i++)
		{
			if(visit[i])
			{
				printf("    %c = %d\n", char(i+'a'), val[i]);
			}
		}
	}
	return 0;
}