#include <iostream>
using namespace std;
#define N 50010
int a[N], rec[N], stack[N];
int tree[N*3];
int n;

void Input()
{
	memset(tree, 0, sizeof(tree));
	int i, nTop = 0;
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(i = n-1; i >= 0; i--)
	{
		rec[i] = -1;
		while(nTop > 0)
		{
			if(a[stack[nTop-1]] <= a[i])
			{
				rec[i] = stack[nTop-1];
				stack[nTop++] = i;
				break;
			}
			nTop--;
		}
		if(nTop == 0)
			stack[nTop++] = i;
		if(rec[i] == -1)
			rec[i] = n;
	}
}
void Init(int i, int start, int end)
{
	if(start == end)
	{
		tree[i] = start;
		return;
	}
	int mid = (start + end) / 2;
	Init(i*2, start, mid);
	Init(i*2+1, mid+1, end);
	tree[i] = a[tree[i*2]] > a[tree[i*2+1]] ? tree[i*2] : tree[i*2+1];
}
int GetAnswer(int i, int start, int end, int x, int y)
{
	if(start == x && end == y)
		return tree[i];
	int mid = (start + end) / 2;
	int tx, ty;
	if(y <= mid)
		return GetAnswer(i*2, start, mid, x, y);
	else if(x > mid)
		return GetAnswer(i*2+1, mid+1, end, x, y);
	else
	{
		tx = GetAnswer(i*2, start, mid, x, mid);
		ty = GetAnswer(i*2+1, mid+1, end, mid+1, y);
		if(a[tx] > a[ty])
			return tx;
		else
			return ty;
	}
}
void Solve()
{
	int i, j, k = 0;
	Init(1, 0, n-1);
	for(i = 0; i < n-1; i++)
	{
		if(rec[i]-1 >= i)
		{
			j = GetAnswer(1, 0, n-1, i, rec[i]-1);
			if(j - i > k)
				k = j-i;
		}
	}
	if(k == 0)
		printf("-1\n");
	else
		printf("%d\n", k);
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		Input();
		Solve();
	}
	return 0;
}