#include<iostream>
using namespace std;
char ch;
char str[300];
int pos;
int pow[30];

int A();
int B();
int bracket();
int expression();

void init()
{
	int i;
	pow[0] = 1;
	for(i = 1; i < 30; i++)
		pow[i] = pow[i-1] * 2;
}
int GetData()
{
	int x = 0;
	pos++;
	while(str[pos] >= 'A' && str[pos] <= 'Z')
	{
		x = x | pow[str[pos]-'A'];
		pos++;
	}
	pos++;
	return x;
}

int expression()
{
	int x = 0;
	x = A();
	while(str[pos] == '+' || str[pos] == '-')
	{
		if(str[pos] == '+')
		{
			pos++;
			x = x | A();
		}
		else
		{
			pos++;
			x = x & ~A();
		}
	}
	return x;
}
int bracket()
{
	pos++;
	int x = expression();
	pos++;
	return x;
}
int B()
{
	if(str[pos] == '{')
		return GetData();
	else
		return bracket();
}
int A()
{
	int x = 0;
	if(str[pos] == '(')
	{
		x = bracket();
	}
	else
		x = B();
	while(str[pos] == '*')
	{
		pos++;
		x = x & B();
	}
	return x;
}

int main ()
{
	int x, i;
	init();
	while(cin.getline(str, 300, '\n'))
	{
		pos = 0;
		x = expression();
		printf("{");
		for(i = 0; i < 26; i++)
		{
			if((x | pow[i]) == x)
				printf("%c", char(i+'A'));
		}
		printf("}\n");
	}
	return 0;
}