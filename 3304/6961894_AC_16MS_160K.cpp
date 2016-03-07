#include <iostream>
#include <math.h>
using namespace std;
double e = 1e-8;
struct ac
{
	double x, y;
};
struct wa
{
	double b, k;
	bool chuizhi;
};
struct ce
{
	ac p1, p2;
}t[200];
int n;
bool xiangjiao(wa zhixian, ce xianduan)
{
	if (zhixian.chuizhi)
	{
		if (fabs(xianduan.p1.x-zhixian.b) < e || fabs(xianduan.p2.x-zhixian.b) < e)
		{
			return true;
		}
		if ((xianduan.p1.x-zhixian.b)*(xianduan.p2.x-zhixian.b) > 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		double d1, d2;
		d1 = zhixian.k * xianduan.p1.x + zhixian.b;
		d2 = zhixian.k * xianduan.p2.x + zhixian.b;
		if (fabs(d1 - xianduan.p1.y) < e || fabs(d2 - xianduan.p2.y) < e)
		{
			return true;
		}
		if ((d1-xianduan.p1.y) * (d2-xianduan.p2.y) > 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	return false;
}
void Input()
{
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%lf %lf %lf %lf", &t[i].p1.x, &t[i].p1.y, &t[i].p2.x, &t[i].p2.y);
	}
}
bool Judge(wa zhixian)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (!xiangjiao(zhixian, t[i]))
		{
			return false;
		}
	}
	return true;
}
double GetDDist(ac p1, ac p2)
{
	double d = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
	return sqrt(d);
}
void Solve()
{
	if (n < 3)
	{
		printf("Yes!\n");
		return;
	}
	wa zhixian;
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (t[i].p1.x == t[j].p1.x)
			{
				zhixian.chuizhi = true;
				zhixian.b = t[i].p1.x;
			}
			else
			{
				zhixian.chuizhi = false;
				zhixian.k = (t[i].p1.y - t[j].p1.y) / (t[i].p1.x - t[j].p1.x);
				zhixian.b = t[i].p1.y - zhixian.k * t[i].p1.x;
			}
			if (GetDDist(t[i].p1, t[j].p1) > e && Judge(zhixian))
			{
				printf("Yes!\n");
				return;
			}
			if (t[i].p1.x == t[j].p2.x)
			{
				zhixian.chuizhi = true;
				zhixian.b = t[i].p1.x;
			}
			else
			{
				zhixian.chuizhi = false;
				zhixian.k = (t[i].p1.y - t[j].p2.y) / (t[i].p1.x - t[j].p2.x);
				zhixian.b = t[i].p1.y - zhixian.k * t[i].p1.x;
			}
			if (GetDDist(t[i].p1, t[j].p2) > e && Judge(zhixian))
			{
				printf("Yes!\n");
				return;
			}
			if (t[i].p2.x == t[j].p1.x)
			{
				zhixian.chuizhi = true;
				zhixian.b = t[i].p2.x;
			}
			else
			{
				zhixian.chuizhi = false;
				zhixian.k = (t[i].p2.y - t[j].p1.x) / (t[i].p2.x - t[j].p1.x);
				zhixian.b = t[i].p2.y - zhixian.k * t[i].p2.x;
			}
			if (GetDDist(t[i].p2, t[j].p1) > e && Judge(zhixian))
			{
				printf("Yes!\n");
				return;
			}
			if (t[i].p2.x == t[j].p2.x)
			{
				zhixian.chuizhi = true;
				zhixian.b = t[i].p2.x;
			}
			else
			{
				zhixian.chuizhi = false;
				zhixian.k = (t[i].p2.y - t[j].p2.y) / (t[i].p2.x - t[j].p2.x);
				zhixian.b = t[i].p2.y - zhixian.k * t[i].p2.x;
			}
			if (GetDDist(t[i].p2, t[j].p2) > e && Judge(zhixian))
			{
				printf("Yes!\n");
				return;
			}
		}
	}
	printf("No!\n");
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		Input();
		Solve();
	}
	return 0;
}