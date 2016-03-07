#include <iostream>
#include <stdlib.h>
using namespace std;
struct TREE
{
	int nBegin, nEnd;
	int nMax, nMin;
}tree[410110];
int a[100100];
int b[100100];
int n, m, t;
int cmp(const void*a, const void*b)
{
	return *(int*)a - *(int*)b;
}
void Input()
{
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	qsort(b, n, sizeof(b[0]), cmp);
	t = 1;
	for(i = 1; i < n; i++)
	{
		if(b[i] != b[i-1])
		{
			b[t++] = b[i];
		}
	}
}
void InitTree(int i, int x, int y)
{
	tree[i].nBegin = x;
	tree[i].nEnd = y;
	if(x == y)
	{
		tree[i].nMin = a[x];
		tree[i].nMax = a[x];
		return;
	}
	int mid = (x + y) / 2;
	InitTree(i * 2, x , mid);
	InitTree(i * 2 + 1, mid + 1, y);
	tree[i].nMin = tree[i*2].nMin < tree[i*2+1].nMin ? tree[i*2].nMin : tree[i*2+1].nMin;
	tree[i].nMax = tree[i*2].nMax > tree[i*2+1].nMax ? tree[i*2].nMax : tree[i*2+1].nMax;
}
void Find(int i, int x, int y, int key, int *p)
{
	if(tree[i].nMin > key)
	{
		p[2] += (y-x+1);
		return;
	}
	else if(tree[i].nMin == key)
	{
		p[2] += (y-x);
		p[1]++;
		return;
	}
	else if(tree[i].nMax < key)
	{
		p[0] += (y-x+1);
		return;
	}
	else if(tree[i].nMax == key)
	{
		p[0] += (y-x);
		p[1]++;
		return;
	}
	int nMid = (tree[i].nBegin + tree[i].nEnd)/2;
	if(y <= nMid)
		Find(i*2, x, y, key, p);
	else if(x > nMid)
		Find(i*2+1, x, y, key, p);
	else
	{
		Find(i*2, x, nMid, key, p);
		Find(i*2+1, nMid + 1, y, key, p);
	}
}
void Solve()
{
	InitTree(1, 0, n-1);
	int i;
	int x, y, z;
	int nBegin, nEnd, nMid;
	int *p = new int[3];
	for(i = 0; i < m; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		if(n == 1)
		{
			printf("%d\n", a[0]);
			return;
		}
		x--;
		y--;
		nBegin = 0;
		nEnd = t - 1;
		
		while(nBegin < nEnd)
		{
			nMid = (nBegin + nEnd) / 2;
			p[0] = p[1] = p[2] = 0;
			Find(1, x, y, b[nMid], p);
			if(p[0] == z-1 && p[1] == 1)
			{
				break;
			}
			else if(p[0] < z-1 || p[0] == z-1 && p[1] == 0)
			{
				nBegin = nMid + 1;
			}
			else
			{
				nEnd = nMid;
			}
			nMid = (nBegin + nEnd) / 2;
		}
		printf("%d\n", b[nMid]);
	}
}
int main()
{
	while(scanf("%d %d", &n, &m)!=EOF)
	{
		Input();
		Solve();
	}
	return 0;
}