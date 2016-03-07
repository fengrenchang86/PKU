#include <iostream>
using namespace std;
#define N 310
#define INF 2000000
int d[N][N];
int a[N];
int n, m;
void Input()
{
	int i, j, k, x;
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
			d[i][j] = INF;
	}
	for(i = 0; i < m; i++)
	{
		scanf("%d", &x);
		for(j = 0; j < x; j++)
			scanf("%d", &a[j]);
		for(j = 0; j < x; j++)
		{
			for(k = j+1; k < x; k++)
				d[a[j]][a[k]] = d[a[k]][a[j]] = 1;
		}
	}
	for(i = 1; i <= n; i++)
		d[i][i] = 0;
}
void Solve()
{
	int i, j , k;
	for(k =	1; k <= n; k++)
	{
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				if(d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[j][i] = d[i][k] + d[k][j];
			}
		}
	}
	k = INF;
	for(i = 1; i <= n; i++)
	{
		a[i] = 0;
		for(j = 1; j <= n; j++)
		{
			if(i == j)
				continue;
			a[i] += d[i][j];
		}
		a[i] *= 100;
		a[i] /= (n-1);
		if(a[i] < k)
			k = a[i];
	}
	printf("%d\n", k);
}
int main()
{
	Input();
	Solve();
	return 0;
}