#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int n, l, m, len;
bool c[601][601];
int dp[101][601];
char table[601][12];
struct ac
{
	int id;
	char str[12];
}a[601], b[601];
int cmp(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	return strcmp(c->str, d->str);
}
void SolveTable()
{
	len = strlen(table[0]);
	int i, j;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < len-1; j++)
			a[i].str[j] = table[i][j];
		for(j = 0; j < len-1; j++)
			b[i].str[j] = table[i][j+1];
		a[i].str[j] = b[i].str[j] = NULL;
		a[i].id = b[i].id = i;
	}
	qsort(a, m, sizeof(a[0]), cmp);
	qsort(b, m, sizeof(b[0]), cmp);
}
void SolveConnect()
{
	int i = 0, j = 0, k;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < m; j++)
			c[i][j] = false;
	}
	i = j = 0;
	while(i < m && j < m)
	{
		k = strcmp(a[i].str, b[j].str);
		if(k > 0)
			j++;
		else if(k < 0)
			i++;
		else
		{
			k = j;
			c[b[j].id][a[i].id] = true;
			do
			{
				j = k;
				do
				{
					c[b[j].id][a[i].id] = true;
					j++;
				}while(j < m && strcmp(b[j-1].str, b[j].str) == 0);
				i++;
			}while(i < m && strcmp(a[i-1].str, a[i].str) == 0);
		}
	}
}
void Solve()
{
	int i, j, k = len;
	for(i = 0; i <= l; i++)
	{
		for(j = 0; j <= m; j++)
			dp[i][j] = 0;
	}
	for(j = 0; j < m; j++)
		dp[k][j] = 1;
	for(i = k+1; i <= l; i++)
	{
		for(j = 0; j < m; j++)
		{
			for(k = 0; k < m; k++)
			{
				if(c[k][j])
					dp[i][j] += dp[i-1][k];
			}
		}
	}
	k = 0;
	for(j = 0; j < m; j++)
		k += dp[l][j];
	printf("%d\n", k);
}
void Input()
{
	int i;
	for(i = 0; i < m; i++)
		scanf(" %s", &table[i]);
}
int main ()
{
	while(scanf("%d %d %d", &n, &l, &m) != EOF)
	{
		if(n == 0 && l == 0 && m == 0)
			break;
		Input();
		SolveTable();
		SolveConnect();
		Solve();
	}
	return 0;
}
