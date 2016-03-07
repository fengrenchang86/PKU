#include<iostream>
#include<queue>
using namespace std;
char str[10000];
bool visit[100];
int number[100];
bool c[100][100];
int pos, n;
bool flag;
void Fix()
{
	int i = 0, j = 0;
	pos = n = 0;
	flag = false;
	memset(visit, false, sizeof(visit));
	memset(number, 0, sizeof(number));
	for(i = 0; i < 100; i++)
	{
		for(j = 0; j < 100; j++)
			c[i][j] = false;
	}
	i = 0;
	j = 0;
	while(str[i] != NULL)
	{
		if(str[i] != ' ')
			str[j++] = str[i];
		i++;
	}
	str[j] = NULL;
}
int GetNumber()
{
	int k = 0;
	while(str[pos] >= '0' && str[pos] <= '9')
	{
		k *= 10;
		k += (str[pos] - '0');
		pos++;
	}
	return k;
}
void MissHH(int node)
{
	int k;
	if(node > n)
		n = node;
	while(str[pos] == '(')
	{
		pos++;
		k = GetNumber();
		c[k][node] = c[node][k] = true;
		number[k]++;
		number[node]++;
		MissHH(k);
		pos++;
	}
}

void LoveHH()
{
	int i, j;
	for(i = 1; i <= n; i++)
	{
		if(number[i] == 1)
		{
			for(j = 1; j <= n; j++)
			{
				if(c[i][j])
				{
					if(flag == false)
					{
						flag = true;
						printf("%d", j);
					}
					else
						printf(" %d", j);
					c[i][j] = c[j][i] = false;
					number[i]--;
					number[j]--;
					LoveHH();
					return;
				}
			}
		}
	}
}
int main ()
{
	int node;
	while(gets(str))
	{
		Fix();
		pos++;
		node = GetNumber();
		MissHH(node);
		pos++;
		LoveHH();
		printf("\n");
	}
	return 0;
}