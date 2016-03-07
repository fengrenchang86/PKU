#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	double x, y;
}p[120000], q[120000];
int n;
double sumX[120000], sumY[120000];
int cmpX(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	return c->x > d->x ? 1 : -1;
}
int cmpY(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	return c->y > d->y ? 1 : -1;
}

int FindY(double nData)
{
	if (nData == q[0].y)
	{
		return 0;
	}
	else if (nData == q[n-1].y)
	{
		return n-1;
	}
	int nBegin = 0, nEnd = n - 1, nMid = (nBegin + nEnd) / 2;
	while (nBegin < nEnd)
	{
		nMid = (nBegin + nEnd) / 2;
		if (nData < q[nMid].y)
		{
			nEnd = nMid;
		}
		else if (nData > q[nMid].y)
		{
			nBegin = nMid + 1;
		}
		else
		{
			return nMid;
		}
	}
	if (q[nBegin].y == nData)
	{
		return nBegin;
	}
	else if (q[nEnd].y == nData)
	{
		return nEnd;
	}
	return -1;
}
void Input()
{
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%lf %lf", &p[i].x, &p[i].y);
		q[i].x = double(p[i].x - p[i].y) / 2.0;
		q[i].y = double(p[i].x + p[i].y) / 2.0;
		p[i] = q[i];
	}
}
void Solve()
{
	qsort(p, n, sizeof(p[0]), cmpX);
	qsort(q, n, sizeof(q[0]), cmpY);
	int i, j, k;
	double tmp;
	double ans = 200000000000000;
	sumX[0] = p[0].x;
	sumY[0] = q[0].y;
	for (i = 1; i < n; i++)
	{
		sumX[i] = sumX[i-1] + p[i].x;
		sumY[i] = sumY[i-1] + q[i].y;
	}
	for (i = 0; i < n; i++)
	{
		k = FindY(p[i].y);
		tmp = 0;
		if (i > 0)
		{
			tmp += (p[i].x * i) - sumX[i-1];
		}
		tmp += (sumX[n-1] - sumX[i] - (n - i - 1) * p[i].x) ;
		if (k > 0)
		{
			tmp += (p[i].y * k) - sumY[k-1];
		}
		tmp += (sumY[n-1] - sumY[k] - (n - k - 1) * p[i].y);
		if (tmp < ans)
		{
			ans = tmp;
		}
	}
	printf("%d\n", (int)ans);
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			printf("0\n");
			continue;
		}
		Input();
		Solve();
	}
	return 0;
}