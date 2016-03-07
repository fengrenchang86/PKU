#include <iostream>
#include <math.h>
using namespace std;
double a[20];
double b[20];
int main()
{
	int i;
	a[0] = 1.0;
	b[0] = 1.0;
	for (i = 1; i <= 10; i++)
	{
		a[i] = a[i-1] * 10.0;
		b[i] = b[i-1] / 10.0;
	}
	int n;
	__int64 y;
	double x, z, t;
	int yy;
	while(scanf("%d %d", &n, &yy)!=EOF)
	{
		x = (double)yy / a[n];
		for (i = 0; i <= 1000000; i++)
		{
			z = (double(i) + x);
			z *= z;
			y = (__int64)z;
			t = sqrt(double(y));
			if (int((t - int(t)) * a[n]) == yy)
			{
				printf("%I64d\n", y);
				break;
			}
			y ++;
			t = sqrt(double(y));
			if (int((t - int(t)) * a[n]) == yy)
			{
				printf("%I64d\n", y);
				break;
			}
		}
	}
	return 0;
}