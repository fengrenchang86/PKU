#include <iostream>
using namespace std;
char str[10000];
int nPos, n, final;
int Flag = -1;
int A();
int B();
int C();
int Exp();
int C()
{
	int k = 0;
	while(str[nPos] >= '0' && str[nPos] <= '9')
	{
		k *= 10;
		k += (str[nPos] - '0');
		nPos++;
	}
	return k;
}
int B()
{
	if (Flag)
	{
		return 0;
	}
	if (str[nPos] >= '0' && str[nPos] <= '9')
	{
		return C();
	}
	else
	{
		return Exp();
	}
}
int Exp()
{
	if (Flag)
	{
		return 0;
	}
	int k, j = 0;;
	if (str[nPos] == '(')
	{
		nPos++;
		j = 1;
	}
	
	k = A();
	while(str[nPos] == '+' || str[nPos] == '-')
	{
		if (str[nPos] == '+')
		{
			nPos++;
			k += A();
		}
		else
		{
			nPos++;
			k -= A();
		}
	}
	if (j == 1)
	{
		nPos++;
	}
	return k;
}
int A()
{
	if (Flag)
	{
		return 0;
	}
	int k = B();
	int j;
	while(str[nPos] == '*' || str[nPos] == '/')
	{
		if (str[nPos] == '*')
		{
			nPos++;
			k *= B();
		}
		else
		{
			nPos++;
			j = B();
			if (j != 0)
			{
				k /= j;
			}
			else
			{
				Flag = -1;
			}
		}
	}
	return k;
}
void Dfs(int i)
{
	if (Flag)
	{
		return;
	}
	while(str[i] != '?' && str[i] != NULL)
	{
		i++;
	}
	if (str[i] == '?')
	{
		str[i] = '+';
		Dfs(i + 1);
		str[i] = '-';
		Dfs(i + 1);
		str[i] = '*';
		Dfs(i + 1);
		str[i] = '/';
		Dfs(i + 1);
		str[i] = '?';
	}
	else
	{
		nPos = 0;
		int k = Exp();
		if (k == final)
		{
			Flag = 1;
		}
	}
}
int main()
{
	int k;
//	cin>>str;
//	cout<<Exp()<<endl;
	scanf("%d", &k);
	while(k--)
	{
		scanf("%s %d", &str, &final);
		Flag = 0;
		Dfs(0);
		if (Flag)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}