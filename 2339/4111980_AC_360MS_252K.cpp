#include <iostream>
#include <string>
using namespace std;
char **a, **b, **c;
int n, m;
void Init()
{

	int i = 0, j = 0;
	a = new char*[120];
	b = new char*[120];
	for(i = 0; i < 120; i++)
	{
		a[i] = new char[120];
		b[i] = new char[120];
	}
}
char GetChar(int i, int j)
{
	if(i - 1 >= 0)
	{
		if(a[i][j] == 'P' && a[i-1][j] == 'S')
			return 'S';
		else if(a[i][j] == 'S' && a[i-1][j] == 'R')
			return 'R';
		else if(a[i][j] == 'R' && a[i-1][j] == 'P')
			return 'P';
	}
	if(i + 1 < n)
	{
		if(a[i][j] == 'P' && a[i+1][j] == 'S')
			return 'S';
		else if(a[i][j] == 'S' && a[i+1][j] == 'R')
			return 'R';
		else if(a[i][j] == 'R' && a[i+1][j] == 'P')
			return 'P';
	}
	if(j - 1 >= 0)
	{
		if(a[i][j] == 'P' && a[i][j-1] == 'S')
			return 'S';
		else if(a[i][j] == 'S' && a[i][j-1] == 'R')
			return 'R';
		else if(a[i][j] == 'R' && a[i][j-1] == 'P')
			return 'P';
	}
	if(j + 1 < m)
	{
		if(a[i][j] == 'P' && a[i][j+1] == 'S')
			return 'S';
		else if(a[i][j] == 'S' && a[i][j+1] == 'R')
			return 'R';
		else if(a[i][j] == 'R' && a[i][j+1] == 'P')
			return 'P';
	}
	return a[i][j];
}
void Input()
{
	int i;
	char str[120];
	for(i = 0; i < n; i++)
	{
		scanf("%s", &str);
		strcpy(a[i], str);
	}
}
void Solve()
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			b[i][j] = GetChar(i, j);
		}
	}
	c = a;
	a = b;
	b = c;
}
void Print()
{
	int i, j;
	for(i =0 ; i < n; i++)
	{
		for(j =0 ; j < m; j++)
			printf("%c", a[i][j]);
		printf("\n");
	}
}
int main()
{
	Init();
	int i, k, tc;
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d %d %d", &n, &m, &k);
		Input();
		for(i = 0; i < k; i++)
			Solve();
		Print();
		if(tc != 0)
			printf("\n");
	}
	return 0;
}