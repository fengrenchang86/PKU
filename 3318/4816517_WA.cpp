
#include <iostream>
using namespace std;

int a[501][501], b[501][501], c[501][501];
int x[501], y[501],z[501];
int n;

void Input()
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			scanf("%d", &b[i][j]);
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			scanf("%d", &c[i][j]);
	}
	for(i = 0; i < n; i++)
	{
		x[i] = rand();
		printf("%d\n", x[i]);
	}
}

void Solve()
{
	int i, j, k;
	for(i = 0; i < n; i++)
	{
		y[i] = 0;
		for(j = 0; j < n; j++)
		{
			y[i] += b[i][j]*x[j];
		}
	}

	for(i = 0; i < n; i++)
	{
		z[i] = 0;
		for(j = 0; j < n; j++)
		{
			z[i] += a[i][j]*y[j];
		}
	}

	for(i = 0; i < n; i++)
	{
		y[i] = 0;
		for(j = 0; j < n; j++)
		{
			y[i] += c[i][j]*x[j];
		}
	}

	for(i = 0; i < n; i++)
	{
		if(z[i] != y[i])
			break;
	}
	if(i < n)
		printf("NO\n");
	else
		printf("YES\n");
}

int main()
{
	while(scanf("%d", &n) != EOF)
	{
		Input();
		Solve();
	}
	return 0;
}