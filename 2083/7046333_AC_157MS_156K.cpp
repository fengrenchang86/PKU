#include <iostream>
int ac[10];
using namespace std;
int n;
void acm(int x, int y, int k, int i, int j)
{
	if (k > 1)
	{
		if (i >= x && i < x + ac[k-1] && j >= y && j < y + ac[k-1])
		{
			acm(x, y, k-1, i, j);
		}
		else if (i >= x && i < x + ac[k-1] && j >= y+2*ac[k-1] && j < y+3*ac[k-1])
		{
			acm(x, y+2*ac[k-1], k-1, i, j);
		}
		else if (i >= x+ac[k-1] && i < x+2*ac[k-1] && j >= y+ac[k-1] && j < y+2*ac[k-1])
		{
			acm(x+ac[k-1], y+ac[k-1], k-1, i, j);
		}
		else if (i >= x+2*ac[k-1] && i < x+3*ac[k-1] && j >= y && j < y+ac[k-1])
		{
			acm(x+2*ac[k-1], y, k-1, i, j);
		}
		else if (i >= x+2*ac[k-1] && i < x+3*ac[k-1] && j >= y+2*ac[k-1] && j < y+3*ac[k-1])
		{
			acm(x+2*ac[k-1], y+2*ac[k-1], k-1, i, j);
		}
		else
			printf(" ");
	}
	else
	{
		printf("X");
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
				acm(0, 0, 7, i, j);
			}
			printf("\n");
		}
		printf("-\n");
	}
	return 0;
}