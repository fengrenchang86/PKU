#include <iostream>
using namespace std;
bool use[500][500];
char a[500][500];
int area[60][60];
int maxx, maxy;
int n, m;
void Input()
{
	scanf("%d %d", &m, &n);
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &area[j][i]);
		}
	}
	for (i = 0; i < 500; i++)
	{
		for (j = 0; j < 500; j++)
		{
			use[i][j] = 0;
			a[i][j] = '.';
		}
	}
	maxx = 0;
	maxy = 0;
}
void Draw(int i, int j, int k)
{
	int x = 3 + 2 * (m - j - 1) + 3 * k;
	int y = (m - j - 1) * 2 + 4 * i;
	if (y+6 >= maxy)
	{
		maxy = y+6;
	}
	if (x+2 >= maxx)
	{
		maxx = x+2;
	}
	a[x+2][y+2] = '+';
	a[x+2][y+3] = '-';
	a[x+2][y+4] = '-';
	a[x+2][y+5] = '-';
	a[x+2][y+6] = '+';

	a[x+1][y+1] = '/';
	a[x+1][y+2] = ' ';
	a[x+1][y+3] = ' ';
	a[x+1][y+4] = ' ';
	a[x+1][y+5] = '/';
	a[x+1][y+6] = '|';

	a[x][y] = '+';
	a[x][y+1] = '-';
	a[x][y+2] = '-';
	a[x][y+3] = '-';
	a[x][y+4] = '+';
	a[x][y+5] = ' ';
	a[x][y+6] = '|';

	a[x-1][y] = '|';
	a[x-1][y+1] = ' ';
	a[x-1][y+2] = ' ';
	a[x-1][y+3] = ' ';
	a[x-1][y+4] = '|';
	a[x-1][y+5] = ' ';
	a[x-1][y+6] = '+';

	a[x-2][y] = '|';
	a[x-2][y+1] = ' ';
	a[x-2][y+2] = ' ';
	a[x-2][y+3] = ' ';
	a[x-2][y+4] = '|';
	a[x-2][y+5] = '/';

	a[x-3][y] = '+';
	a[x-3][y+1] = '-';
	a[x-3][y+2] = '-';
	a[x-3][y+3] = '-';
	a[x-3][y+4] = '+';
}
int main()
{
	int i, j, k;
	Input();
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			for (k = 0; k < area[i][j]; k++)
			{
				Draw(i, j, k);
			}
		}
	}
	for (i = maxx; i >= 0; i--)
	{
		for (j = 0; j <= maxy; j++)
		{
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
