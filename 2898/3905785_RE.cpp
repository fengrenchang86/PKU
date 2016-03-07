#include<iostream>
using namespace std;
char a[1020][1020];
int n, m, T;
char ch;
struct Point
{
	int x, y;
}b[1020];
void MissHH()
{
	int i = 1;
	while(scanf(" %s", &a[i]))
	{
		if(a[i][0] < 'a' || a[i][0] > 'z')
			break;
		i++;
	}
	n = i;
	m = strlen(a[0]);
	T = 0;
	i = 0;
	while(a[n][i] != 0)
	{
		T *= 10;
		T += (a[n][i] - '0');
		i++;
	}
	for(i = 0; i < T; i++)
		scanf(" %d %d", &b[i].x, &b[i].y);
}
void dfs(int x, int y)
{
	a[x][y] = '.';
	if(x-1 >= 0 && a[x-1][y] == ch)
		dfs(x-1, y);
	if(x+1 < m && a[x+1][y] == ch)
		dfs(x+1, y);
	if(y-1 >= 0 && a[x][y-1] == ch)
		dfs(x, y-1);
	if(y+1 < m && a[x][y+1] == ch)
		dfs(x, y+1);
}
void MoveLeft()
{
	int i, j, k;
	for(i = 0; i < n; i++)
	{
		k = 0;
		for(j = 0; j < m; j++)
		{
			if(a[i][j] != '.')
				a[i][k++] = a[i][j];
		}
		while(k < m)
			a[i][k++] = '.';
	}
}
void MoveDown()
{
	int i, j, k;
	for(j = 0; j < m; j++)
	{
		k = n-1;
		for(i = n-1; i >= 0; i--)
		{
			if(a[i][j] != '.')
				a[k--][j] = a[i][j];
		}
		while(k >= 0)
			a[k--][j] = '.';
	}
}
void LoveHH()
{
	int i, j;
	for(i = 0; i < T; i++)
	{
		ch = a[b[i].x-1][b[i].y-1];
		dfs(b[i].x-1, b[i].y-1);
		MoveLeft();
		MoveDown();
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			if(a[i][j] == '.')
				break;
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
}
int main ()
{
	int HH = 1;
	while(scanf("%s", &a[0]) != EOF)
	{
		MissHH();
		printf("Test case #%d:\n", HH++);
		LoveHH();
	}
	return 0;
}