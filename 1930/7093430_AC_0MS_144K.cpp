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
	long long x, y, tx, ty;
	long long ansx, ansy;
	int z;
	int i, j;
	while (scanf(" %s", &ch) != EOF)
	{
		ansx = 0;
		ansy = -1;
		if (ch[0] == '0' && ch[1] == NULL)
		{
			break;
		}
		x = 0;
		y = 1;
		for (i = 2; ch[i] != '.'; i++)
		{
			x *= 10;
			x += (ch[i] - '0');
			y *= 10;
		}
		y --;
		if (x == 0)
		{
			printf("0/1\n");
			continue;
		}
		z = gcd(x, y);
		ansx = x / z;
		ansy = y/ z;
		x = 0;
		y = 1;
		for (i = 2; ch[i+1] != '.'; i++)
		{
			x *= 10;
			x += (ch[i] - '0');
			y *= 10;
			ty = 1;
			tx = 0;
			for (j = i+1; ch[j] != '.'; j++)
			{
				tx *= 10;
				tx += (ch[j] - '0');
				ty *= 10;
			}
			tx = x * (ty-1) + (tx);
			ty = y * (ty-1);
			if (tx == 0)
			{
				z = 1;
			}
			else
			{
				z = gcd(tx,ty);
			}
			tx /= z;
			ty /= z;
			if (ansy > ty)
			{
				ansx = tx;
				ansy = ty;
			}
		}
		printf("%lld/%lld\n", ansx, ansy);
	}
	return 0;
}