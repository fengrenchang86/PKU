#include <iostream>
using namespace std;
int use[1000000];
int main()
{
	int i, n;
	int x, y, z, nCount;
	while (scanf("%d", &n) != EOF)
	{
		memset(use, 0, sizeof(use));
		i = 1;
		x = n;
		use[x] = 1;
		while (1)
		{
			if (x >= 10000)
			{
				x = (x/10) % 10000;
			}
			x *= x;
			x %= 1000000;
			if (use[x] != 0)
			{
				break;
			}
			use[x] = i;
			i++;
		}
		printf("%d %d %d\n", x, i-use[x], i);
	}
	return 0;
}