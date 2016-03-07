#include <iostream>
using namespace std;
#define N 15
__int64 sum[N], a[N], d[N];
__int64 c[N] = {0, 4,32,317,3163,31623, 316228, 3162278, 31622777};
int f(__int64 A, int B)
{
	int i;
	for (i = 1; i < N; i++)
	{
		if (A / a[i] == 0)
		{
			break;
		}
	}
	return  (A/a[i-B]) % 10;
}
void Init()
{
	a[0] = 0;
	a[1] = 1;
	sum[0] = 0;
	int i;
	for (i = 2; i < N; i++)
	{
		a[i] = a[i-1] * 10;
	}
	for (i = 1; i < N; i++)
	{
		sum[i] = i * 9 * a[i];
	}
	for (i = 1; i < 8; i++)
	{
		d[i] = (c[i]-a[i])*(2*i-1) + (a[i+1]-c[i])*2*i;
	}
}
int GetAns1(__int64 x)
{
	int i;
	for (i = 1; i < N; i++)
	{
		x -= sum[i];
		if (x <= 0)
		{
			break;
		}
	}
	if (x == 0)
	{
		return 9;
	}
	x += sum[i];
	__int64 A;
	int B;
	A = x / i + a[i];
	B = x % i;
	if (B == 0)
	{
		B = i;
		A--;
	}
	return f(A, B);
}
int GetAns2(__int64 x)
{
	int i;
	for (i = 1; i < 9; i++)
	{
		x -= d[i];
		if (x <= 0)
		{
			break;
		}
	}
	if (x == 0)
	{
		return 1;
	}
	x += d[i];
	__int64 A;
	int B;
	if (x <= (c[i] - a[i]) * (2*i-1))
	{
		A = x / (2 * i-1) + a[i];
		B = x % (2*i-1);
		if (B == 0)
		{
			B = 2 * i - 1;
			A--;
		}
		A *= A;
		return f(A, B);
	}
	else
	{
		x -= (c[i] - a[i]) * (2*i-1);
		A = x / (2*i) + c[i];
		B = x % (2*i);
		if (B == 0)
		{
			B = 2 * i;
			A--;
		}
		A *= A;
		return f(A, B);
	}
}
int main()
{
	Init();
	__int64 x, y;
	int ans;
	while(scanf("%I64d", &x) != EOF)
	{
		if (x == 0)
		{
			break;
		}
		ans = GetAns1(x) + GetAns2(x);
		x++;
		while(1)
		{
			y = GetAns1(x) + GetAns2(x);
			if (y >= 10)
			{
				ans++;
				break;
			}
			else if (y < 9)
			{
				break;
			}
			x++;
		}
		ans %= 10;
		printf("%d\n", ans);
	}
	return 0;
}