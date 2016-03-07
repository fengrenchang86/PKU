#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define NMAX 120000
struct AC_POINT
{
	int x, y, nId;
}kUp[NMAX], kDown[NMAX], kPoint[NMAX];
int nDisPoint, n;
int nDis[NMAX];
int cmp(const void*a, const void*b)
{
	struct AC_POINT *c = (AC_POINT*)a;
	struct AC_POINT *d = (AC_POINT*)b;
	if(c->x != d->x)
		return c->x - d->x;
	else
		return d->y - c->y;
}

int AcRight(AC_POINT t[], int a, int b, int c)//判断t[a], t[b], t[c]是否右拐
{
	int m = (t[b].x - t[a].x) * (t[c].y - t[a].y) - (t[c].x - t[a].x) * (t[b].y - t[a].y);
	return m < 0;
}
int Make_UP(int n)
{
	int i, k;
	if(nDisPoint != kPoint[0].nId)
	{
		kUp[0] = kPoint[0];
		kUp[1] = kPoint[1];
		i = 2;
	}
	else
	{
		kUp[0] = kPoint[1];
		kUp[1] = kPoint[2];
		i = 3;
	}
	k = 2;
	while(i < n)
	{
		if(kPoint[i].nId == nDisPoint)
		{
			i++;
			continue;
		}
		kUp[k] = kPoint[i];
		while(k > 1 && AcRight(kUp, k-2, k-1, k) == 0)
		{
			kUp[k-1] = kPoint[k];
			k--;
		}
		k++;
		i++;
	}
	return k;
}
int Make_DOWN(int n)
{
	int i, k;
	if(nDisPoint != kPoint[n-1].nId)
	{
		kDown[0] = kPoint[n-1];
		kDown[1] = kPoint[n-2];
		i = n-3;
	}
	else
	{
		kDown[0] = kPoint[n-2];
		kDown[1] = kPoint[n-3];
		i = n-4;
	}
	k = 2;
	while(i >= 0)
	{
		if(kPoint[i].nId == nDisPoint)
		{
			i--;
			continue;
		}
		kDown[k] = kPoint[i];
		while(k > 1 && AcRight(kDown, k-2, k-1, k) == 0)
		{
			kDown[k-1] = kDown[k];
			k--;
		}
		k++;
		i--;
	}
	return k;
}
double GetArea(int x1, int y1, int x2, int y2, int x3, int y3)
{
	double s = (double)fabs(((double)(x1*y2) + double(x2*y3) + double(x3*y1) - double(x1*y3) - double(x2*y1) - double(x3*y2)) / 2.0);
	return s;
}
void Input()
{
	int i, x, y;
	for(i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		kPoint[i].x = x;
		kPoint[i].y = y;
		kPoint[i].nId = i;
	}
	qsort(kPoint, n, sizeof(kPoint[0]), cmp);	
}
void Solve()
{
	nDisPoint = -1;
	int nUp, nDown, i, j, k, m = 0;
	double fArea, ans = 2000000000.0;
	nUp = Make_UP(n);
	nDown = Make_DOWN(n);
	for(i = 0; i < nUp; i++)
	{
		nDis[m++] = kUp[i].nId;
	}
	for(i = 1; i < nDown-1; i++)
	{
		nDis[m++] = kDown[i].nId;
	}
	for(i = 0; i < m; i++)
	{
		nDisPoint = nDis[i];
		nUp = Make_UP(n);
		nDown = Make_DOWN(n);
		fArea = 0.0;
		if(nDisPoint != kUp[0].nId)
			k = 0;
		else
			k = 1;
		for(j = 1; j < nUp-1; j++)
		{
			fArea += GetArea(kUp[k].x, kUp[k].y, kUp[j].x, kUp[j].y, kUp[j+1].x, kUp[j+1].y);
		}
		for(j = 0; j < nDown-1; j++)
		{
			fArea += GetArea(kUp[k].x, kUp[k].y, kDown[j].x, kDown[j].y, kDown[j+1].x, kDown[j+1].y);
		}
		if(fArea < ans)
			ans = fArea;
	}
	printf("%.2lf\n", ans);
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0)
			break;
		Input();
		Solve();
	}
	return 0;
}