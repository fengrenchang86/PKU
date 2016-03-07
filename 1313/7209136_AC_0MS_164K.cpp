#include <iostream>
#include <vector>
using namespace std;
int n;
int f[200][2];
int b[200][2];
void Solve()
{
	int m = (n+3) / 4;
	int i = 1, j = 1;
	int k = 1;
	memset(f, 0, sizeof(f));
	memset(b, 0, sizeof(b));
	while (k <= n)
	{
		f[i][1] = k++;
		if (k > n)
		{
			break;
		}
		b[i][0] = k++;
		i++;
		if (i > m)
		{
			i--;
			break;
		}
	}
	while (k <= n)
	{
		b[i][1] = k++;
		if (k > n)
		{
			break;
		}
		f[i][0] = k++;
		i--;
	}
	printf("Printing order for %d pages:\n", n);
	for (i = 1; i <= m; i++)
	{
		if (f[i][0] || f[i][1])
		{
			printf("Sheet %d, front:", i);
			if (f[i][0])
				printf(" %d,", f[i][0]);
			else
				printf(" Blank,");
			if (f[i][1])
				printf(" %d\n", f[i][1]);
			else
				printf(" Blank\n");
		}
		if (b[i][0] || b[i][1])
		{
			printf("Sheet %d, back :", i);
			if (b[i][0])
				printf(" %d,", b[i][0]);
			else
				printf(" Blank,");
			if (b[i][1])
				printf(" %d\n", b[i][1]);
			else
				printf(" Blank\n");
		}
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
		Solve();
	}
	return 0;
}
