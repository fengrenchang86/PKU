#include <iostream>
using namespace std;
long long gcd(long long x, long long y)
{
	if (y == 0)
	{
		return x;
	}
	return gcd(y, x%y);
}
char ch[1000];
int main()
{
	long long x, y;
	int z;
	int i;
	while (scanf(" %s", &ch) != EOF)
	{
		if (ch[0] == '0' && ch[1] == NULL)
		{
			break;
		}
		x = 0;
		y = 1;
		for (i = 2; ch[i+1] != '.'; i++)
		{
			x *= 10;
			x += (ch[i] - '0');
			y *= 10;
		}
		if (x == 0 && ch[i] == '0')
		{
			printf("0/1\n");
			continue;
		}
		if (x == 0)
		{
			z = 1;
		}
		else
		{
			z = gcd(x, y);
		}
		x /= z;
		y /= z;
		z = ch[i] - '0';
		x = 9 * x + z;
		y *= 9;
		z = gcd(x, y);
		x /= z;
		y /= z;
		printf("%lld/%lld\n", x, y);
	}
	return 0;
}
