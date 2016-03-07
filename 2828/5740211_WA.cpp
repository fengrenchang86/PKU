// pku5.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
using namespace std;
int tree[500000];
int arrval[500000];
int n;
int pos[210000];
int val[210000];
void Init(int i, int nBegin, int nEnd)
{
	if (nBegin == nEnd)
	{
		tree[i] = 1;
		return;
	}
	int nMid = (nBegin + nEnd) / 2;
	Init(i * 2, nBegin, nMid);
	Init(i * 2 + 1, nMid+1, nEnd);
	tree[i] = tree[i*2] + tree[i*2+1];
}
void Insert(int i, int nBegin, int nEnd, int nPos, int nVal)
{
	tree[i]--;
	if (nBegin == nEnd)
	{
		arrval[i] = nVal;
		return;
	}
	int nMid = (nBegin + nEnd) / 2;
	if (tree[i*2] >= nPos)
	{
		Insert(i * 2, nBegin, nMid, nPos, nVal);
	}
	else
	{
		Insert(i * 2 + 1, nMid + 1, nEnd, nPos - tree[i*2], nVal);
	}
}
void Show(int i, int nBegin ,int nEnd)
{
	if (nBegin == nEnd)
	{
		printf("%d ", arrval[i]);
	}
	else
	{
		int nMid = (nBegin + nEnd) / 2;
		Show(i * 2, nBegin, nMid);
		Show(i * 2 + 1, nMid + 1, nEnd);
	}
}
void Input()
{
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &pos[i], &val[i]);
		pos[i] ++;
	}
	Init(1, 1, n);
}
void Solve()
{
	int i;
	for (i = n - 1; i >= 0; i--)
	{
		Insert(1, 1, n, pos[i], val[i]);
	}
	Show(1, 1, n);
	printf("\n");
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			break;
		}
		Input();
		Solve();
	}
	return 0;
}