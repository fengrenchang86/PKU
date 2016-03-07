#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
#define NTABLE 40
#define MTABLE 200
#define inf 20000000000000.00
char table[NTABLE][MTABLE];
double c[NTABLE][NTABLE];
double dis[NTABLE];
int n, m, t;
int GetNumber(char *str);

void input()
{
	char str1[MTABLE], str2[MTABLE];
	double exc;
	t = 0;
	int i, j, k;
	for(i = 0; i < n; i++)
		scanf(" %s", &table[i]);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			c[i][j] = 0;
		dis[i] = inf;
	}
	scanf("%d", &m);
	for(i = 0; i < m; i++)
	{
		scanf(" %s %lf %s", &str1, &exc, &str2);
		j = GetNumber(str1);
		k = GetNumber(str2);
		if(j == -1)
		{
			strcpy(table[t], str1);
			j = t;
			t++;
		}
		if(k == -1)
		{
			strcpy(table[t], str2);
			k = t;
			t++;
		}
		if(c[j][k] < exc)
			c[j][k] = exc;
	}
}
int GetNumber(char *str)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(strcmp(str, table[i]) == 0)
			return i;
	}
	return -1;
}
bool solve()
{
	int i, j, k;
	dis[0] = 100;
	bool tag = true;
	for(k = 0; k < m; k++)
	{
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				if(c[i][j] == 0)
					continue;
				if(dis[j] < dis[i] * c[i][j])
				{
					dis[j] = dis[i] * c[i][j];
				}
			}
		}
	}
	for(k = 0; k <= n && tag; k++)
	{
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				if(c[i][j] == 0)
					continue;
				if(dis[j] < dis[i] * c[i][j])
					return false;
			}
		}
	}
	return true;
}
int main ()
{
	int tc = 1;
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0)
			break;
		input();
		printf("Case %d: ", tc++);
		if(!solve())
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}