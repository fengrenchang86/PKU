#include <iostream>
using namespace std;
__int64 n;
__int64 ans[33333];
int a[33333];
__int64 Calue(__int64 x, __int64 d)
{
	__int64 y = (x - d + 1) * x * d + (2 * d * d * d - 3 * d * d + d) / 6;
	return y;
}
__int64 Judge(int d)
{
	__int64 nBegin, nEnd, nMid, x, y;
	nBegin = 1;
	nEnd = 10000000;
	while (nBegin < nEnd)
	{
		nMid = (nBegin + nEnd) / 2;
		x = (nMid + d - 1);
		y = Calue(x, d);
		if (y == n)
		{
			return nMid;
		}
		else if (y > n)
		{
			nEnd = nMid;
		}
		else
			nBegin = nMid + 1;
	}
	x = (nBegin + d - 1);
	y = Calue(x, d);
	if (y == n)
	{
		return nBegin;
	}
	return -1;
}
int Solve()
{
	int i, j, l = 0;
	__int64 k;
	for (i = 1; ; i++)
	{
		if ((__int64)i * (__int64)(2 * i + 1) * (__int64)(i + 1) / 6 > n)
		{
			break;
		}
		k = Judge(i);
		if (k != -1)
		{
			a[l] = i;
			ans[l] = k;
			l++;
		}
	}
//	return l;
	printf("%d\n", l);
	for (i = l - 1; i >= 0; i--)
	{
		printf("%d", a[i]);
		for (j = 0; j < a[i]; j++)
		{
			printf(" %I64d", (__int64)ans[i] + (__int64)j);
		}
		printf("\n");
	}
	return l;
}
int main()
{

/*
		int j;
		int i, t;
		__int64 k = 757148;
		__int64 sum = 0;
		char ch[100];
		for (j = 1; j < 2; j++)
		{
			sum = 0;
			k = (rand() * rand())%100000 + 1;
			t = rand() * rand() % 5000 + 2;
			k = 2;
			t = 5201;
			for (i = 0; i < t; i++)
			{
				sum += (k + i) * (k + i);
			}
			n = sum;
			if (n > 100000000000000 || n < 0)
			{
				j--;
				continue;
			}
			printf("ans: %d from %I64d   n = %I64d\n", t, k, n);
			int v = Solve();
	//		printf("*************\n");
	//		cin.getline(ch, 100);
			if (v == 0)
			{			
				printf("ans: %d from %I64d   n = %I64d\n", t, k, n);
				cin.getline(ch, 100);
			}
		}
		n = sum;
		printf("INput:\n");*/
	
	while(scanf("%I64d", &n)!=EOF)
	{
		Solve();
	}
	return 0;
}