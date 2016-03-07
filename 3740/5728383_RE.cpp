#include <iostream>
using namespace std;
int n, m;
int a[20][400];
void Input()
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	int k, p;
	for (j = 0; j < n; j++)
	{
		k = 0;
		p = 0;
		for (i = 0; i < m; i++)
		{
			if (a[i][j] == 1)
			{
				k++;
			}
		}
		if (k != 1)
		{
			printf("It is impossible\n");
			return;
		}
	}
	printf("Yes, I found it\n");
}
int main()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		Input();
	}
	return 0;
}