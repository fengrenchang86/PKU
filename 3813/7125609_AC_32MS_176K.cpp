#include <iostream>
#include <math.h>
using namespace std;
#define e 0.000000001
#define INF 9000000.0
struct ac
{
	double x, y;
};
ac A,B,C,D,E,F,G,H;
struct line
{
	double k, b;
	bool chuizhi;
	double x;
};
double GetDistance(ac p1, ac p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}
double GetArea(ac p1, ac p2, ac p3)
{
	double ans = 0.0;
	ans = (p1.x * p2.y - p1.y * p2.x + p2.x * p3.y - p2.y *p3.x + p3.x * p1.y - p3.y * p1.x) / 2.0;
	double a = GetDistance(p1, p2);
	double b = GetDistance(p2, p3);
	double c = GetDistance(p1, p3);
	double p = (a + b + c) / 2.0;
	double rt = sqrt(p * (p-a) * (p-b) * (p-c));
	return fabs(ans);
}
line CalueLine(ac p1, ac p2)
{
	line ans;
	if (fabs(p1.x - p2.x) < e)
	{
		ans.chuizhi = 1;
		ans.x = p1.x;
		return ans;
	}
	ans.chuizhi = 0;
	ans.k = (p1.y - p2.y) / (p1.x - p2.x);
	ans.b = p1.y - p1.x * ans.k;
	return ans;
}
int main()
{
	double dBegin, dEnd, dMid, dArea;
	line AC;
	double a;
	while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", 
		&A.x, &A.y, &B.x, &B.y, &C.x, &C.y, & D.x, &D.y, &E.x, &E.y, &F.x, &F.y) != EOF)
	{
		if (A.x == 0 && A.y == 0 && C.x == 0 && C.y == 0 && B.x == 0 && B.y == 0 &&
			E.x == 0 && E.y == 0 && F.x == 0 && F.y == 0 && D.x == 0 && D.y == 0)
		{
			break;
		}
		dArea = GetArea(D, E, F);
		AC = CalueLine(A, C);
		if (AC.chuizhi == 0)
		{
			if (A.x < C.x)
			{
				dBegin = A.x;
				dEnd = INF;
				while (fabs(dBegin-dEnd) > e)
				{
					dMid = (dBegin + dEnd) / 2.0;
					H.x = dMid;
					H.y = AC.k * dMid + AC.b;
					a = GetArea(A, B, H);
					if (a * 2.0 < dArea)
					{
						dBegin = dMid;
					}
					else
					{
						dEnd = dMid;
					}
				}
			}
			else
			{
				dBegin = -INF;
				dEnd = A.x;
				while (fabs(dBegin-dEnd) > e)
				{
					dMid = (dBegin + dEnd) / 2.0;
					H.x = dMid;
					H.y = AC.k * dMid + AC.b;
					a = GetArea(A, B, H);
					if (a * 2.0 > dArea)
					{
						dBegin = dMid;
					}
					else
					{
						dEnd = dMid;
					}
				}
			}
		}
		else
		{
			if (A.y < C.y)
			{
				dBegin = A.y;
				dEnd = INF;
				while (fabs(dBegin-dEnd) > e)
				{
					dMid = (dBegin + dEnd) / 2.0;
					H.y = dMid;
					H.x = AC.x;
					a = GetArea(A, B, H);
					if (a * 2.0 < dArea)
					{
						dBegin = dMid;
					}
					else
					{
						dEnd = dMid;
					}
				}
			}
			else
			{
				dBegin = -INF;
				dEnd = A.y;
				while (fabs(dBegin-dEnd) > e)
				{
					dMid = (dBegin + dEnd) / 2.0;
					H.y = dMid;
					H.x = AC.x;
					a = GetArea(A, B, H);
					if (a * 2.0 > dArea)
					{
						dBegin = dMid;
					}
					else
					{
						dEnd = dMid;
					}
				}
			}
		}
		G.x = H.x-A.x+B.x;
		G.y = H.y-A.y+B.y;
		printf("%.3lf %.3lf %.3lf %.3lf\n", G.x, G.y, H.x, H.y);
	}
	return 0;
}