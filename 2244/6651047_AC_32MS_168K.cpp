#include <iostream>
using namespace std;
int fun(int n, int m)
{
	int i, r = 0;
	for (i = 2; i <= n; i++)
		r = (r + m) % i;
	if ((r+2-m) % n == 0)
	{
		return n;
	}
	else
	{
		return ((r+2-m) % n + n) % n;
	}
}
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (0 == n)
		{
			break;
		}
		int m;
		for (m = 2; ; m++)
		{
			if (fun(n, m) == 2)
			{
				printf("%d\n", m);
				break;
			}
		}
	}
	return 0;
}