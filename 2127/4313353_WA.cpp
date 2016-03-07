#include <iostream>
#include <stdlib.h>
using namespace std;

int c[1010][1010];
int a[1010], b[1010];
int ga[1010], gb[1010];
int dp[1010], path[1010];
int t[1010];
int n, m, nNum;

int cmp(const void*a, const void*b)
{
	return *(int*)a > *(int*)b ? 1 : -1;
}
int Find(int data)
{
	int start = 0, end = nNum - 1, mid;
	while(start < end)
	{
		mid = (start + end) / 2;
		if(data == t[mid])
			return mid;
		else if(data < t[mid])
			end = mid;
		else
			start = mid+1;
	}
	return start;
}
void Input()
{
	int i;
//	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for(i = 0; i < m; i++)
		scanf("%d", &b[i]);
}
void Init()
{
	int i, j = 0;
	for(i = 0; i < n; i++)
		t[j++] = a[i];
	for(i = 0; i < m; i++)
		t[j++] = b[i];
	nNum = j;
	qsort(t, j, sizeof(t[0]), cmp);
	j = 1;
	for(i = 1; i < nNum; i++)
	{
		if(t[i] != t[i-1])
			t[j++] = t[i];
	}
	nNum = j;
	for(i = 0; i < nNum; i++)
		dp[i] = 0;
	for(i = 0; i < n; i++)
	{
		ga[i] = Find(a[i]);
		dp[ga[i]] = 1;
	}
	for(i = 0; i < m; i++)
	{
		gb[i] = Find(b[i]);
		if(dp[gb[i]])
			dp[gb[i]] ++;
	}
	for(i = 0; i < nNum; i++)
	{
		if(dp[i] >= 2)
			dp[i] = 1;
		else
			dp[i] = 0;
	}
	for(i = 0; i < nNum; i++)
	{
		for(j = 0; j < nNum; j++)
			c[i][j] = 0;
	}
	for(i = 0; i < n; i++)
	{
		for(j = i+1; j < n; j++)
			c[ga[i]][ga[j]]=1;
	}
	for(i = 0; i < m; i++)
	{
		for(j = i+1; j < m; j++)
		{
			if(c[gb[i]][gb[j]])
				c[gb[i]][gb[j]]++;
		}
	}
}
void AcPrint(int k)
{
	k = path[k];
	if(path[k] != -1)
		AcPrint(k);
	printf("%d ", t[k]);
}
void Solve()
{
	int i, j, k = -1;
	for(i = 0; i <= nNum; i++)
	{
		path[i] = -1;
		if(dp[i] == 1)
			k = i;
	}
	for(i = 1; i < nNum; i++)
	{
		for(j = 0; j < i; j++)
		{
			if(c[j][i] >= 2 && dp[i] <= dp[j]+1)
			{
				dp[i] = dp[j]+1;
				path[i] = j;
				if(k == -1 || dp[i] >= dp[k])
					k = i;
			}
		}
	}
	if(k == -1)
	{
		printf("0\n");
		return;
	}
	printf("%d\n", dp[k]);
	if(path[k] != -1)
		AcPrint(k);
	printf("%d\n", t[k]);
}
int main()
{
	int tc;
//	scanf("%d", &tc);
//	while(tc--)
	while(scanf("%d", &n) != EOF)
	{
		Input();
		Init();
		Solve();
//		if(tc)
//			printf("\n");
	}
	return 0;
}