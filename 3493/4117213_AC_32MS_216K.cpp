#include <iostream>
using namespace std;
int n, m;
int a[100][100];
void Init()
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	}
}
void Solve()
{
	int i, j;
	__int64 k = 0;
	for(i =0 ; i < n; i++)
	{
		for(j = 0; j <m; j++)
		{
			if(i > 0 && a[i-1][j] * a[i][j] > 0)
				k += a[i-1][j] * a[i][j];
			if(j > 0 && a[i][j-1] * a[i][j] > 0)
				k += a[i][j-1] * a[i][j];
		}
	}
	printf("%I64d\n", k);
}
int main()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		Init();
		Solve();
	}
	return 0;
}