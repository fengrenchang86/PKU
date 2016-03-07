#include <iostream>
using namespace std;
bool visit[110];
int a[110][10];
void Init()
{
	int i, j;
	for(i = 0; i <= 100; i++)
	{
		for(j = 0; j < 10; j++)
			a[i][j] = 0;
	}
}
void Solve(int n)
{
	memset(visit, false, sizeof(visit));
	int x = 1;
	int y;
	while(visit[x] == false)
	{
		visit[x] = true;
		x *= 10;
		y = x / n;
		if(y == 0)
		{
			a[n][0]++;
			continue;
		}
		a[n][y]++;
		x = x - y * n;
		if(x == 0)
			break;
	}
}
void AllSolve()
{
	int i, j;
	Init();
	for(i = 2; i <= 100; i++)
	{
		Solve(i);
//		printf("%d:", i);
//		for(j = 0; j <= 9; j++)
//		{
//			if(a[i][j] == true)
//				printf(" %d", j);
//		}
//		printf("\n");
	}
}
int main()
{
	AllSolve();
	int n, k;
	int i, j, x;
	while(scanf("%d %d", &n, &k) != EOF)
	{
		x = 0;
		for(i = 2; i <= n; i++)
		{
			x += a[i][k];
		}
		printf("%d\n", x);
	}
	return 0;
}