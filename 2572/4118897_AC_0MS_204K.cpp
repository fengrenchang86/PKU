#include <iostream>
#include <string>
using namespace std;
char strA[100], strB[100], strC[100], str[100];
char strAns[100];
int lenA, lenB, lenC;
void Init()
{
	int i;
	lenA = lenB = lenC = 0;
	for(i = 0; str[i] != '+'; i++)
	{
		strA[lenA++] = str[i];
	}
	strA[lenA] = NULL;
	i++;
	while(str[i] != '=')
	{
		strB[lenB++] = str[i];
		i++;
	}
	strB[lenB] = NULL;
	i++;
	while(str[i] != NULL)
	{
		strC[lenC++] = str[i];
		i++;
	}
	i = lenC - 1;
	while(i > 1 && strC[i] == '0')
		i--;
	i++;
	lenC = i;
	strC[lenC] = NULL;
}
void Fix(char *str)
{
	int i, n = strlen(str);
	i = n-1;
	while(i > 1 && str[i] == '0')
		i--;
	i++;
	str[i] = NULL;
}
void Solve()
{
	int i, carry = 0, n = lenA > lenB ? lenA : lenB;
	for(i = 0; i < lenA && i < lenB; i++)
	{
		strAns[i] = (strA[i] + strB[i] - '0' - '0' + carry) % 10 + '0';
		carry = (strA[i] + strB[i] - '0' - '0' + carry) / 10;
	}
	while(i < lenA)
	{
		strAns[i] = (strA[i] - '0' + carry) % 10 + '0';
		carry = (strA[i] - '0' + carry) / 10;
		i++;
	}
	while(i < lenB)
	{
		strAns[i] = (strB[i] - '0' + carry) % 10 + '0';
		carry = (strB[i] - '0' + carry) / 10;
		i++;
	}
	strAns[i++] = carry + '0';
	strAns[i] = NULL;
	Fix(strAns);
	if(strcmp(strAns, strC) == 0)
		printf("True\n");
	else
		printf("False\n");
}
int main()
{
	while(scanf(" %s", str) != EOF)
	{
		if(strcmp(str, "0+0=0") == 0)
		{
			printf("True\n");
			break;
		}
		Init();
		Solve();
	}
	return 0;
}