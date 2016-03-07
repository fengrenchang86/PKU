#include <iostream>
#include <stdlib.h>
using namespace std;

int a[5];
int s[1100100];
int n, m;
struct ac
{
	int val;
	int num;
}t[100100];
int cmp(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	return c->val - d->val;
}
int Find(int start, int end, int data)
{
	int mid = (start + end) / 2;
	while(start < end)
	{
		mid = (start + end) / 2;
		if(t[mid].val == data)
			return t[mid].num;
		if(t[mid].val > data)
			end = mid;
		else
			start = mid+1;
	}
	if(t[start].val == data)
		return t[start].val;
	else
		return 0;
}
void Init()
{
	int i, j, k, ii, jj;
	n = m = 0;
	for(i = -50; i <= 50; i++)
	{
		if(i == 0)
			continue;
		ii = i*i*i;
		for(j = -50; j <= 50; j++)
		{
			if(j == 0)
				continue;
			jj = j*j*j;
			t[n].num = 0;
			t[n++].val = a[3]*ii + a[4]*jj;
			for(k = -50; k <= 50; k++)
			{
				if(k == 0)
					continue;
				s[m++] = a[0]*ii + a[1]*jj + a[2]*k*k*k;
			}
		}
	}
	k = 0;
	j = 1;
	qsort(t, n, sizeof(t[0]), cmp);
	for(i = 1; i < n; i++)
	{
		if(t[i].val == t[i-1].val)
			j++;
		else
		{
			t[k].num = j;
			k = i;
			j = 1;
		}
	}
	t[k].num = j;
	j = 1;
	for(i = 1; i < n; i++)
	{
		if(t[i].num != 0)
			t[j++] = t[i];
	}
	n = j;
}
void Solve()
{
	int i, k;
	__int64 j = 0;
	for(i = 0; i < m; i++)
	{
		k = Find(0, n-1, -s[i]);
		j += k;
	}
	printf("%I64d\n", j);
}
int main()
{
	while(scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]) != EOF)
	{
		Init();
		Solve();
	}
	return 0;
}