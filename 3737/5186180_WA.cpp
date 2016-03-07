#include <iostream>
#include <math.h>
using namespace std;
double s;
double r;
double R;
double h;
double v;
double pi = 2.0 * asin(1.0);
void PrintOut(double a)
{
	double x = a * 1000;
	int y = int(x);
	double b = x - y;
	if(y % 10 < 5)
	{
		printf("%.2lf\n", a);
	}
	else
	{
		printf("%.2lf\n", a+0.005);
	}
}
int main()
{
	while(scanf("%llf", &s) != EOF)
	{
		r = sqrt(double(s) / 4.0 / pi);
		R = double(s - pi * r * r) / pi / r;
		h = sqrt(double(R*R) - double(r*r));
		v = sqrt(double(s*s*s) / 8.0 / pi / pi / pi);
		v = v / 3.0 * pi;
		PrintOut(v);
		PrintOut(h);
		PrintOut(r);
//		printf("%.2llf\n%.2llf\n%.2llf\n", v, h, r);
	}
	return 0;
}