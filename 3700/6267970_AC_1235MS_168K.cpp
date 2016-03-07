#include <iostream>

#include <stdlib.h>
using namespace std;
int st1[50], st2[50];
int a[100], b[100];
bool c[100];
int n, ans;
int nMax, nMin;
int cmp(const void*a, const void*b)
{
	return *(int*)a - *(int*)b;
}
void dfs(int lay, int n1, int n2)
{
	if (n1 + n2 >= ans)
	{
		return;
	}
	if (lay == n)
	{
		ans = n1 + n2;
		return;
	}
	bool t1(0), t2(0);
	int i, j1, j2, k, nTop;
	
	if (c[lay] == false)
	{
		k = nMax;
		j2 = -1;
		for (i = 0; i < n2; i++)
		{
			nTop = st2[i];
			if (a[lay] < nTop && (j2 == -1 || k > nTop))
			{
				j2 = i;
				k = nTop;
			}
		}
		if (j2 != -1)
		{
			int tmp = st2[j2];
			st2[j2] = a[lay];
			dfs(lay + 1, n1, n2);
			st2[j2] = tmp;
		}
		else
			t2 = 1;

		k = nMin;
		j1 = -1;
		for (i = 0; i < n1; i++)
		{
			nTop = st1[i];
			if (a[lay] > nTop && (j1 == -1 || k < nTop))
			{
				j1 = i;
				k = nTop;
			}
		}
		if (j1 != -1)
		{
			int tmp = st1[j1];
			st1[j1] = a[lay];
			dfs(lay + 1, n1, n2);
			st1[j1] = tmp;
		}
		else
			t1 = 1;
		if (t1)
		{
			int tmp = st1[j1];
			st1[n1] = a[lay];
			dfs(lay + 1, n1 + 1, n2);
			st1[n1] = tmp;
		}
		if (t2)
		{
			int tmp = st2[j2];
			st2[n2] = a[lay];
			dfs(lay + 1, n1, n2 + 1);
			st2[n2] = tmp;
		}
	}
	else
	{
		k = nMin;
		j1 = -1;
		for (i = 0; i < n1; i++)
		{
			nTop = st1[i];
			if (a[lay] > nTop && (j1 == -1 || k < nTop))
			{
				j1 = i;
				k = nTop;
			}
		}
		if (j1 != -1)
		{
			int tmp = st1[j1];
			st1[j1] = a[lay];
			dfs(lay + 1, n1, n2);
			st1[j1] = tmp;
		}
		else
			t1 = 1;

		k = nMax;
		j2 = -1;
		for (i = 0; i < n2; i++)
		{
			nTop = st2[i];
			if (a[lay] < nTop && (j2 == -1 || k > nTop))
			{
				j2 = i;
				k = nTop;
			}
		}
		if (j2 != -1)
		{
			int tmp = st2[j2];
			st2[j2] = a[lay];
			dfs(lay + 1, n1, n2);
			st2[j2] = tmp;
		}
		else
			t2 = 1;
		if (t2)
		{
			int tmp = st2[j2];
			st2[n2] = a[lay];
			dfs(lay + 1, n1, n2 + 1);
			st2[n2] = tmp;
		}
		if (t1)
		{
			int tmp = st1[j1];
			st1[n1] = a[lay];
			dfs(lay + 1, n1 + 1, n2);
			st1[n1] = tmp;
		}
	}
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			break;
		}
		int i;
		ans = 8;
		nMin = 2000000000;
		nMax = -2000000000;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			b[i] = a[i];
			if (a[i] < nMin)
			{
				nMin = a[i];
			}
			if (a[i] > nMax)
			{
				nMax = a[i];
			}
		}
		qsort(b, n, sizeof(b[0]), cmp);
		for (i = 0; i < n; i++)
		{
			if (a[i] > b[n/2])
			{
				c[i] = true;
			}
			else
				c[i] = false;
		}
		for (i = 1; i <= 8; i++)
		{
			ans = i;
			dfs(0, 0, 0);
			if (ans < i)
			{
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}