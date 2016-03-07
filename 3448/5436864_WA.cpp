#include <iostream>
using namespace std;
char res[12000];
char str[12000];
int pos;
int v;
int regedit[10];
int GetDig(char ch)
{
	switch(ch)
	{
	case 'O':
		return 0;
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	}
	return -1;
}
void Cat(char ch, int x)
{
	int i;
	for (i = 0; i < x; i++)
	{
		res[v++] = ch;
	}
}
void CatStr(char *pstr)
{
	int i;
	for (i = 0; pstr[i] != NULL; i++)
	{
		res[v++] = pstr[i];
	}
}
void intToch(int key)
{
	if (key < 0 || key > 10000)
	{
		strcpy(res, "Error");
		return;
	}
	int i, k;
	v = 0;
	if (key > 1000)
	{
		i = 1000;
	}
	else if(key > 100)
	{
		i = 100;
	}
	else if(key > 10)
	{
		i = 10;
	}
	else
		i = 1;
	while(i >= 1)
	{
		k = key / i;
		key %= i;
		if (k < 4)
		{
			if (i == 1000)
			{
				Cat('M', k);
			}
			else if(i == 100)
			{
				Cat('C', k);
			}
			else if(i == 10)
			{
				Cat('X', k);
			}
			else
			{
				Cat('I', k);
			}
		}
		else if (k == 4)
		{
			if (i == 1000)
			{
				Cat('M', k);
			}
			else if(i == 100)
			{
				CatStr("CD");
			}
			else if(i == 10)
			{
				CatStr("XL");
			}
			else if(i == 1)
			{
				CatStr("IV");
			}
		}
		else if (k < 9)
		{
			if (i == 1000)
			{
				Cat('M', k);
			}
			else if(i == 100)
			{
				Cat('D', 1);
				Cat('C', k-5);
			}
			else if (i == 10)
			{
				Cat('L', 1);
				Cat('X', k-5);
			}
			else if(i == 1)
			{
				Cat('V', 1);
				Cat('I', k-5);
			}
		}
		else
		{
			if (i == 1000)
			{
				Cat('M', k);
			}
			else if(i == 100)
			{
				CatStr("CM");
			}
			else if(i == 10)
			{
				CatStr("XC");
			}
			else if(i == 1)
			{
				CatStr("IX");
			}
		}
		i /= 10;
	}
	res[v] = NULL;
}
int chToint(char *str)
{
	int k = 0;
	int i, x, y;
	for (i = 0; str[i] != NULL; i++)
	{
		if (str[i+1] == NULL)
		{
			k += GetDig(str[i]);
			break;
		}
		x = GetDig(str[i]);
		y = GetDig(str[i+1]);
		if (x == -1 || y == -1)
		{
			return -1;
		}
		if (GetDig(str[i]) < GetDig(str[i+1]))
		{
			k += GetDig(str[i+1]) - GetDig(str[i]);
			i++;
		}
		else
			k += GetDig(str[i]);
	}
	return k;
}
int GetNum()
{
	char ch[12000];
	int i = 0;
	while(str[pos] >= 'A' && str[pos] <= 'Z' || str[pos] >= '0' && str[pos] <= '9')
	{
		ch[i++] = str[pos];
		pos++;
	}
	ch[i] = NULL;
	i = chToint(ch);
	if (i > 0)
	{
		return i;
	}
	if (ch[1] == NULL)
	{
		if(str[0] >= '0' && str[0] <= '9')
			return regedit[str[0]-'0'];
	}
	else
		return -1;
}
int Exp()
{
	int j;
	int k = GetNum();
	if (k == -1)
	{
		return -1;
	}
	while(str[pos] == '+' || str[pos] == '-')
	{
		if (str[pos] == '+')
		{
			pos++;
			j = GetNum();
			if(j == -1)
				return -1;
			k += j;
		}
		else
		{
			pos++;
			j = GetNum();
			if(j == -1)
				return -1;
			k -= j;
		}
	}
	return k;
}
int main()
{
	
	int i;
	for (i = 0; i < 10; i++)
	{
		regedit[i] = -1;
	}
	int x, y;
//	FILE *fp = fopen("e:\\a.txt", "r");
//	while(fscanf(fp, "%s", str) != EOF)
	while(scanf("%s", str) != EOF)
	{
		if (strcmp(str, "RESET") == 0)
		{
			for (i = 0; i < 10; i++)
			{
				regedit[i] = -1;
			}
			printf("Ready\n");
		}
		else if(strcmp(str, "QUIT") == 0)
		{
			printf("Bye\n");
			break;
		}
		else
		{
			x = str[0] - '0';
			pos = 2;
			y = Exp();
			if (y < 0 || y > 10000)
			{
				printf("Error\n");
			}
			else
			{
				regedit[x] = y;
				intToch(y);
				printf("%c=%s\n", str[0], res);
			}
		}
	}
	return 0;
}