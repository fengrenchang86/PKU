#include <iostream>
using namespace std;
char a[3100][3100];
int n, m, v;
char ch;
char t[10][10];
int acPow[40];
void Input()
{
	int i;
	cin.ignore();
	for (i = 0; i < n; i++)
	{
		cin.getline(t[i], 10);
	}
	scanf("%d", &m);
}
void Make(int lay, int x, int y)
{
	int i, j;
	if (lay == 1)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				a[x+i][y+j] = t[i][j];
			}
		}
		return;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (t[i][j] != ' ')
			{
				Make(lay - 1, x + i * acPow[lay-1], y + j * acPow[lay-1]);
			}
		}
	}
}
void Solve()
{
	int i, j;
	acPow[1] = n;
	for (i = 2; i <= m; i++)
	{
		acPow[i] = acPow[i-1] * n;
	}
	for (i = 0; i < acPow[m]; i++)
	{
		for (j = 0; j < acPow[m]; j++)
		{
			a[i][j] = ' ';
		}
	}
	Make(m, 0, 0);
	for (i = 0; i < acPow[m]; i++)
	{
		for (j = 0; j < acPow[m]; j++)
		{
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			break;
		}
		Input();
		Solve();
	}
	return 0;
}