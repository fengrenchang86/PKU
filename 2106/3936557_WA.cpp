#include<iostream>
using namespace std;
char str[1000];
int pos;

bool expression();
bool A();
bool B();
bool bracket();
bool GetData();

bool GetData()
{
	if(str[pos] == '!')
	{
		pos++;
		return !GetData();
	}
	else if(str[pos] == 'V')
	{
		pos++;
		return true;
	}
	else
	{
		pos++;
		return false;
	}
}
void Fix()
{
	int i, j;
	i = j = 0;
	while(str[i] != 0)
	{
		if(str[i] != ' ')
			str[j++] = str[i];
		i++;
	}
	str[j] = NULL;
}
bool expression()
{
	bool x, y;
	x = A();
	while(str[pos] == '|')
	{
		pos++;
		y = A();
		x = x || y;
	}
	return x;
}
bool A()
{
	bool x;
	x = B();
	while(str[pos] == '&')
	{
		pos++;
		x = x && B();
	}
	return x;
}
bool B()
{
	if(str[pos] == '(')
	{
		return bracket();
	}
	else
	{
		return GetData();
	}
}
bool bracket()
{
	pos++;
	bool x = expression();
	pos++;
	return x;
}
int main ()
{
	int tc = 1;
	bool x;
	while(cin.getline(str, 1000, '\n'))
	{
		pos = 0;
		Fix();
		x = expression();
		printf("Expression %d: ", tc++);
		if(x)
			printf("V\n");
		else
			printf("F\n");
	}
	return 0;
}