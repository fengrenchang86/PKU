#include <iostream>
#include <stdlib.h>
using namespace std;
int a[100009];
int b[2009];
int dp[2][100009];
int n, m;
#define INF 2100000000
int GetMin(int x, int y)
{
	return x < y ? x : y;
}
int cmp(const void*a, const void*b)
{
	return *(int*)a - *(int*)b;
}
int Find(int key)
{
	int nBegin, nEnd, nMid;
	nBegin = 0;
	nEnd = m-1;
	while(nBegin < nEnd)
	{
		nMid = (nBegin + nEnd)/2;
		if (a[nMid] > key)
		{
			nEnd = nMid;
		}
		else
		{
			nBegin = nMid + 1;
		}
	}
	return nBegin;
}
int Find2(int key)
{
	int nBegin, nEnd, nMid;
	nBegin = 0;
	nEnd = m-1;
	while(nBegin < nEnd)
	{
		nMid = (nBegin + nEnd)/2;
		if (a[nMid] >= key)
		{
			nEnd = nMid;
		}
		else
		{
			nBegin = nMid + 1;
		}
	}
	return nBegin;
}
void Input()
{
	int i;
	for (i = 0; i < m; i++)
	{
		scanf("%d", &a[i]);
//		a[i] = 1000000;
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
//		b[i] = 0;
	}
	qsort(a, m, sizeof(a[0]), cmp);
	qsort(b, n, sizeof(b[0]), cmp);
}
void Solve()
{
	int i, j;
	int x, y, k, t;
	int px, py;
	int k1;
	for (i = 0; i < m; i++)
	{
		dp[0][i] = dp[1][i] = INF;
	}
	for (i = 0; i < m; i++)
	{
		dp[0][i] = abs(a[i] - b[0]);
		if (i > 0 && dp[0][i] > dp[0][i-1])
		{
			dp[0][i] = dp[0][i-1];
		}
	}
	while(i < m)
	{
		dp[0][i] = dp[0][i-1];
		i++;
	}
	px = 0;
	py = m;
	for (i = 1; i < n; i++)
	{
		k = i % 2;
		t = (i - 1)%2;
		k1 = Find(b[i]);
		x = k1 - n - 1 + i;
		y = k1 + i + 1 ;
		if(x < i)
			x = i;
		if(y > m)
			y = m;
		
		dp[k][x-1] = INF;
		for (j = x; j < y; j++)
		{
			if (j-1  >= px && j-1 < py)
			{
				dp[k][j] = GetMin(dp[t][j-1] + abs(b[i] - a[j]), dp[k][(j-1)]);
			}
			else
			{
				dp[k][j] = dp[k][j-1];
			}
		}
		px = x;
		py = y;
	}
	printf("%d\n", dp[(n-1)%2][y-1]);
}
int main()
{

	while (scanf("%d %d", &m, &n) != EOF)
	{
		Input();
		Solve();
	}
	return 0;
}


void Test()
{
		char ch[10];
	while(cin>>ch)
	{
		int k = 0;
		if(ch[0] >= 'a')
			k = ch[0] - 'a' + 10;
		else if(ch[0] >= 'A')
			k = ch[0] - 'A' + 10;
		else
			k = ch[0] - '0';
		k *= 16;
		if(ch[1] >= 'a')
			k += ch[1] - 'a' + 10;
		else if (ch[1] >= 'A')
			k += ch[1] - 'A' + 10;
		else
			k += ch[1] - '0';
		cout<<k<<endl;
	}
}