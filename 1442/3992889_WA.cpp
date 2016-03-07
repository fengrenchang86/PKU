#include<iostream>
#include<stdlib.h>
using namespace std;
#define N 31000
int input[N];
int a[20*N], data[N];
int query[N];
int n, m;
int cmp(const void*a, const void*b)
{
	return *(int*)a - *(int*)b;
}
int GetId(int key)
{
	int begin = 0, end = n-1, mid = (begin+end) / 2;
	while(begin < end)
	{
		mid = (begin+end) / 2;
		if(data[mid] >= key)
			end = mid;
		else
			begin = mid+1;
	}
	return begin;
}
void MissHH()
{
	int i;

	for(i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
		input[i] = data[i];
	}
	qsort(data, n, sizeof(data[0]), cmp);
	memset(a, 0, sizeof(a));

	for(i = 0; i < m; i++)
		scanf("%d", &query[i]);
}
void insert(int i, int begin, int end, int x)
{
	a[i]++;
	if(begin == end)
		return;
	int mid = (begin + end) / 2;
	if(mid >= x)
		insert(i*2, begin, mid, x);
	else
		insert(i*2 + 1, mid+1, end, x);
}
int GetResult(int i, int begin, int end, int x)
{
	if(begin == end)
		return begin;
	if(a[i*2] >= x)
		return GetResult(i*2, begin, (begin + end) / 2, x);
	else
		return GetResult(i*2+1, (begin + end) / 2 + 1, end, x - a[i*2]);
}
void LoveHH()
{
	int pos = 0, x;
	int i, j = 0;
	int k = 1;
	for(i = 0; i < n && j < m; )
	{
		if(pos != query[j])
		{
			x = GetId(input[i]);
			insert(1, 0, n-1, x);
			pos++;
			i++;
		}
		else
		{
			x = GetResult(1, 0, n-1, k);
			printf("%d\n", data[x]);
			j++;
			k++;
		}
	}
}

int main ()
{
	while(scanf("%d %d", &n, &m) != EOF)
	{
		MissHH();
		LoveHH();
	}
	return 0;
}