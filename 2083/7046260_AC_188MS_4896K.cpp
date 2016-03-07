#include <iostream>
#include <vector>
#include <queue>
bool c[2200][2200];
int ac[10];
using namespace std;
int n;
void acm(int x, int y, int k)
{
	if (k > 1)
	{
		acm(x, y, k-1);
		acm(x, y+2*ac[k-1], k-1);
		acm(x+ac[k-1], y+ac[k-1], k-1);
		acm(x + 2*ac[k-1], y, k-1);
		acm(x+2*ac[k-1], y + 2*ac[k-1], k-1);
	}
	else
	{
		c[x][y] = 1;
	}
}
int main()
{
	int i, j;
	ac[1] = 1;
	for (i = 2; i <= 7; i++)
	{
		ac[i] = ac[i-1] * 3;
	}
	memset(c, 0, sizeof(c));
	acm(0, 0, 7);
	while (scanf("%d", &n) != EOF)
	{
		if (n == -1)
		{
			break;
		}
		for (i = 0; i < ac[n]; i++)
		{
			for (j = 0; j < ac[n]; j++)
			{
				if (c[i][j])
				{
					printf("X");
				}
				else
				{
					printf(" ");
				}
			}
			printf("\n");
		}
		printf("-\n");
	}
	return 0;
}