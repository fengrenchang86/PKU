#include <iostream>
#include <stdlib.h>
using namespace std;

struct ac
{
	int x, y;
}path[1010][1010];
int f[1010][1010];
int a[1010], b[1010];
int n, m, nNum;

void Input()
{
	int i;
//	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for(i = 0; i < m; i++)
		scanf("%d", &b[i]);
}
void AcPrint(int lay, int x, int y)
{
	if(lay == 0 || x == -1 || y == -1)
		return;
	if(a[x] == b[y])
	{
		AcPrint(lay-1, path[x][y].x, path[x][y].y);
		printf("%d ", a[x]);
	}
	else
	{
		AcPrint(lay, path[x][y].x, path[x][y].y);
	}
}
void Solve()
{
	int i, j, k;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			path[i][j].x = -1;
			path[i][j].y = -1;
		}
	}
	if(a[0] == b[0])
		f[0][0] = 1;
	else
		f[0][0] = 0;
	for(j = 1; j < m; j++)
	{
		if(a[0] == b[j])
			f[0][j] = 1;
		else
			f[0][j] = f[0][j-1];
	}
	for(i = 1; i < n; i++)
	{
		k = 0;
		for(j = 0; j < m; j++)
		{
			f[i][j] = f[i-1][j];
			path[i][j].x = i-1;
			path[i][j].y = j;
			if(a[i] > b[j] && (f[i][j] > f[i][k]))
			{
		//		path[i][j].x = i;
		//		path[i][j].y = k;
				k = j;
			}
			if(a[i] == b[j] && (f[i][j] < f[i][k]+1 && b[k] < b[j]))
			{
				f[i][j] = f[i][k]+1;
				path[i][j].x = i;
				path[i][j].y = k;
			}
		}
	}
	printf("%d\n", f[n-1][m-1]);
	AcPrint(f[n-1][m-1], n-1, m-1);
	printf("\n");
}
int main()
{
	int tc = 1;
//	scanf("%d", &tc);
//	while(tc--)
	while(scanf("%d", &n) != EOF)
	{
		Input();
		Solve();
//		if(tc)
//			printf("\n");
	}
	return 0;
}