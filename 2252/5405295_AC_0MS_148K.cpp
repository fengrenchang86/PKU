#include <iostream>
#include <math.h>
using namespace std;
struct ac
{
	int x;
	int val;
};
char str[1000];
int nPos;
double x;
double Equation();
double Expression();
double Term();
double Factor();
double Number();
double Equation()
{
	double y1, y2;
	nPos = 0;
	y1 = Expression();
	nPos++;
	y2 = Expression();
	return y1 - y2;
}
double Expression()
{
	double ans = Term();
	while(str[nPos] == '+' || str[nPos] == '-')
	{
		if (str[nPos] == '+')
		{
			nPos++;
			ans += Term();
		}
		else
		{
			nPos++;
			ans -= Term();
		}
	}
	return ans;
}
double Term()
{
	double ans = Factor();
	while(str[nPos] == '*')
	{
		nPos++;
		ans *= Factor();
	}
	return ans;
}
double Factor()
{
	double ans(0.0);
	if (str[nPos] == 'x')
	{
		nPos++;
		return x;
	}
	else if(str[nPos] == '(')
	{
		nPos++;
		ans = Expression();
		nPos++;
		return ans;
	}
	else
		return Number();
}
double Number()
{
	double k = 0;
	while(str[nPos] >= '0' && str[nPos] <= '9')
	{
		k *= 10;
		k += (str[nPos] - '0');
		nPos++;
	}
	return k;
}
void Solve()
{
	double y1, y2;
	double k, b;
	x = 1.0;
	y1 = Equation();
	x = 0.0;
	y2 = Equation();
	if (fabs(y1) < 0.00000001 && fabs(y2) < 0.00000001)
	{
		printf("Infinitely many solutions.\n");
		return;
	}
	else if (fabs(y1 - y2) < 0.00000001)
	{
		printf("No solution.\n");
		return;
	}
	b = y2;
	k = y1 - y2;
	x = -1.0 * b / k;
	printf("x = %.6lf\n", x);
}
int main()
{
	int tc = 1;
	while(scanf("%s", str) != EOF)
	{
		printf("Equation #%d\n", tc++);
		Solve();
		printf("\n");
	}
	return 0;
}