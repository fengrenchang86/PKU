#include <iostream>
using namespace std;
struct TREE
{
	int nBegin, nEnd;
	int n;
	int *pData;
}tree[300000];
int a[120000];
int nMax, nMin;
int m, q;
void Input()
{
	nMin = 2000000000;
	nMax = -2000000000;
	int i;
	for (i = 0; i < m; i++)
	{
		scanf("%d", &a[i]);
//		a[i] = rand() % 300;
//		printf("%d ", a[i]);
		if (a[i] > nMax)
		{
			nMax = a[i];
		}
		if (a[i] < nMin)
		{
			nMin = a[i];
		}
	}
}
void WfSoft(int i, int x, int y)
{
	tree[i].nBegin = x;
	tree[i].nEnd = y;
	tree[i].n = y - x + 1;
	tree[i].pData = new int[y-x+1];
	if (x == y)
	{
		tree[i].pData[0] = a[x];
		return;
	}
	int nMid = (x + y) / 2;
	WfSoft(i * 2, x, nMid);
	WfSoft(i * 2 + 1, nMid + 1, y);
	int j, k;
	j = k = 0;
	while (j < tree[i*2].n || k < tree[i*2+1].n)
	{
		if (k >= tree[i*2+1].n || 
			j < tree[i*2].n && tree[i*2].pData[j] < tree[i*2+1].pData[k])
		{
			tree[i].pData[j+k] = tree[i*2].pData[j];
			j++;
		}
		else if(j >= tree[i*2].n || 
			k < tree[i*2+1].n && tree[i*2].pData[j] >= tree[i*2+1].pData[k])
		{
			tree[i].pData[j+k] = tree[i*2+1].pData[k];
			k++;
		}
		else
			break;
	}
}
int Erfen(int n, int val, int *pData)
{
	if (n == 1)
	{
		if (pData[0] < val)
		{
			return 1;
		}
		else
			return 0;
	}
	if (pData[0] >= val)
	{
		return 0;
	}
	else if (pData[n-1] < val)
	{
		return n;
	}
	int nBegin = 0;
	int nEnd = n - 1;
	int nMid;
	while (nBegin < nEnd)
	{
		nMid = (nBegin + nEnd) / 2;
		if (pData[nMid] >= val)
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
int FindAns(int i, int x, int y, int val)
{
	if (x == tree[i].nBegin && y == tree[i].nEnd)
	{
		return Erfen(tree[i].n, val, tree[i].pData);
	}
	int nMid = (tree[i].nBegin + tree[i].nEnd) / 2;
	if (y <= nMid)
	{
		return FindAns(i * 2, x, y, val);
	}
	else if (x > nMid)
	{
		return FindAns(i * 2 + 1, x, y, val);
	}
	else
	{
		return FindAns(i * 2, x, nMid, val) + FindAns(i * 2 + 1, nMid + 1, y, val);
	}
}
void Solve(int x, int y, int z)
{
	int nBegin, nEnd, nMid;
	nBegin = nMin;
	nEnd = nMax;
	z--;
	int k;
	while (nBegin < nEnd)
	{
		nMid = (nBegin + nEnd) / 2;
		k = FindAns(1, x, y, nMid);
		if (k > z)
		{
			nEnd = nMid;
		}
		else if (nBegin == nMid)
		{
			nBegin = nMid + 1;
			break;
		}
		else
		{
			nBegin = nMid;
		}
	}
	k = FindAns(1, x, y, nBegin);
	if (k == z)
	{
		printf("%d\n", nBegin);
	}
	else if (k > z)
	{
		printf("%d\n", nBegin - 1);
	}
	else
	{
		printf("%d\n", nBegin + 1);
	}
}
int main()
{
	scanf("%d %d", &m, &q);
	Input();
	WfSoft(1, 0, m-1);
	int i, x, y, z;
	for (i = 0; i < q; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		x--;
		y--;
		Solve(x, y, z);
	}
	return 0;
}