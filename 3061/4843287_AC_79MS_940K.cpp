#include <iostream>
using namespace std;
__int64 sum[100100];
int n, m;

void Input()
{
	scanf("%d %d", &n, &m);
	sum[0] = 0;
	int i, x;
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		sum[i] = sum[i-1] + x;
	}
}

bool Check(int nMid)
{
	int i;
	for(i = 1; i + nMid <= n; i++)
	{
		if(sum[i+nMid] - sum[i] >= m)
			return true;
	}
	return false;
}

void Solve()
{
	if(sum[n] < m)
	{
		printf("0\n");
		return;
	}
	int nBegin, nEnd, nMid;
	nBegin = 0;
	nEnd = n;
	while(nBegin < nEnd)
	{
		nMid = (nBegin + nEnd) / 2;
		if(Check(nMid))
		{
			nEnd = nMid;
		}
		else
		{
			nBegin = nMid + 1;
		}
	}
	printf("%d\n", nBegin);
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		Input();
		Solve();
	}
	return 0;
}