#include <iostream>
#include <stdlib.h>
using namespace std;
struct LINE
{
	double b, k;	//Y=KX+B
	bool chuizhi;	//x=b
	int pos;
}line[6000];
struct ac
{
	int x, y;
}part[6000], toy[6000];
int ans[6000];
int n,m,x1,y1,x2,y2;
int cmp(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	if (c->x > d->x)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
void Input()
{
	scanf("%d %d %d %d %d", &m, &x1, &y1, &x2, &y2);
	int i;
	for (i = 0; i < n; i++)
	{
		ans[i] = 0;
		scanf("%d %d", &part[i].x, &part[i].y);
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &toy[i].x, &toy[i].y);
	}
}
int GetAns(int i, int j)
{
	if (line[j].chuizhi)
	{
		if (line[j].b < toy[i].x)
		{
			return -1;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		double d = ((double)toy[i].y - line[j].b) / (double)line[j].k;
		if ((double)toy[i].x < d)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
}
void Solve()
{
	int i, nBegin, nEnd, nMid;
//	qsort(part, n, sizeof(part[0]), cmp);
	for (i = 0; i < n; i++)
	{
		if (part[i].x == part[i].y)
		{
			line[i].chuizhi = 1;
			line[i].b = (double)part[i].x;
		}
		else
		{
			line[i].chuizhi = 0;
			line[i].k = (double)(y2 - y1) / (double)(part[i].y - part[i].x);
			line[i].b = (double)y2 - (double)line[i].k * (double)part[i].y;
		}
	}
	int p = 0;
	for (i = 0; i < m; i++)
	{
		if (GetAns(i, n-1) < 0)
		{
			ans[n-1] ++;
			continue;
		}
		else if (GetAns(i, 0) > 0)
		{
			p ++;
			continue;
		}
		nBegin = 0;
		nEnd = n-1;
		while (nBegin < nEnd)
		{
			nMid = (nBegin + nEnd) / 2;
			if (GetAns(i, nMid) > 0)
			{
				nEnd = nMid;
			}
			else
			{
				nBegin = nMid + 1;
			}
		}
		ans[nBegin-1] ++;
	}
	printf("0: %d\n", p);
	for (i = 0; i < n; i++)
	{
		printf("%d: %d\n", i+1, ans[i]);
	}
}
int main()
{
	int tc = 0;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			break;
		}
		Input();
		if (tc > 0)
		{
			printf("\n");
		}
		tc++;
		Solve();
	}
	return 0;
}