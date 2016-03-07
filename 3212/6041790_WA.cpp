#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	float x, y;
}p[120000], q[120000];
int n;
float sumX[120000], sumY[120000];
int cmpX(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	return c->x - d->x;
}
int cmpY(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	return c->y - d->y;
}
int FindX(float data)
{
	if (data == p[0].x)
	{
		return 0;
	}
	else if (data == p[n-1].x)
	{
		return n-1;
	}
	int nBegin = 0, nEnd = n - 1, nMid = (nBegin + nEnd) / 2;
	while (nBegin < nEnd)
	{
		nMid = (nBegin + nEnd) / 2;
		if (data < p[nMid].x)
		{
			nEnd = nMid;
		}
		else if (data > p[nMid].x)
		{
			nBegin = nMid + 1;
		}
		else
		{
			return nMid;
		}
	}
	return -1;
}
int FindY(float data)
{
	if (data == q[0].y)
	{
		return 0;
	}
	else if (data == q[n-1].y)
	{
		return n-1;
	}
	int nBegin = 0, nEnd = n - 1, nMid = (nBegin + nEnd) / 2;
	while (nBegin < nEnd)
	{
		nMid = (nBegin + nEnd) / 2;
		if (data < q[nMid].y)
		{
			nEnd = nMid;
		}
		else if (data > q[nMid].y)
		{
			nBegin = nMid + 1;
		}
		else
		{
			return nMid;
		}
	}
	return -1;
}
void Input()
{
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%f %f", &p[i].x, &p[i].y);
		q[i].x = (p[i].x - p[i].y) / 2;
		q[i].y = (p[i].x + p[i].y) / 2;
		p[i] = q[i];
	}
}
void Solve()
{
	qsort(p, n, sizeof(p[0]), cmpX);
	qsort(q, n, sizeof(q[0]), cmpY);
	int i, j, k;
	double tmp;
	double ans = 2000000000;
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
	scanf("%d", &n);
	Input();
	Solve();
	return 0;
}