#include <iostream>
using namespace std;
int f[50001];
int t[500000];
int n, k;
void BeginInit()
{
	memset(t, 0, sizeof(t));
}
void Before()
{
	int i;
	for(i = 1; i <= n; i++)
		f[i] = (__int64)i*(__int64)(i-1)/2;
}
int Find(int data)
{
	int start = 1, end = n, mid;
	while(start < end)
	{
		mid = (start + end) / 2;
		if(data == f[mid])
			return mid;
		else if(data < f[mid])
			end = mid;
		else
			start = mid + 1;
	}
	return start - 1;
}
void Init(int i, int start, int end)
{
	t[i] = (end-start+1);
	if(start == end)
		return;
	Init(i*2, start, (start+end)/2);
	Init(i*2+1, (start+end)/2+1, end);
}
int GetACM(int i, int start, int end, int x, int y)
{
	if(start == x && end == y)
		return t[i];
	int nMid = (start + end ) / 2;
	if(y <= nMid)
	{
		return GetACM(i*2, start, nMid, x, y);
	}
	else if(x > nMid)
	{
		return GetACM(i*2 + 1, nMid + 1, end, x, y);
	}
	else
	{
		return GetACM(i*2, start, nMid, x, nMid) + GetACM(i*2+1, nMid+1, end, nMid+1, y);
	}
}
int GetNumber(int i, int start, int end, int nID)
{
	t[i]--;
	if(start == end)
		return start;
	int mid = (start + end) / 2;
	if(t[i*2] >= nID)
		return GetNumber(i*2, start, mid, nID);
	else
		return GetNumber(i*2+1, mid+1, end, nID-t[i*2]);
}
void Solve()
{
	int i, j, x;
	BeginInit();
	Init(1, 1, n);
	for(i = 1; i <= n; i++)
	{
		
		if(k == f[n-i+1])
		{
			while(i <= n)
			{
				j = GetNumber(1, 1, n, n-i+1);
				printf("%d ", j);
				i++;
			}
			break;
		}
		else if(k <= f[n-i])
		{
			j = GetNumber(1, 1, n, 1);
			printf("%d ", j);
			continue;
		}
		x = Find(k);
		x = k - f[x] + 1;
		j = GetNumber(1, 1, n, x);
		printf("%d ", j);
		k -= (x-1);
	}
	printf("\n");
}
int main()
{
	n = 50000;
	Before();
	while(scanf("%d %d", &n, &k) != EOF)
	{
		if(n == -1 && k == -1)
			break;
		Solve();
	}
	return 0;
}