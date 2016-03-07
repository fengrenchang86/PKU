#include <iostream>
using namespace std;
int x, y, n, len;
int main()
{
	int tc, k;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d %d", &len, &n);
		y = 0;
		x = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &k);
			if (k > x)
				x = k;
			if (len - k > x)
				x = len - k;
			if (k <= len/2)
			{
				if (k > y)
					y = k;
			}
			else
			{
				if (len-k > y)
					y = len-k;
			}
		}
		printf("%d %d\n", y, x);
	}
	return 0;
}