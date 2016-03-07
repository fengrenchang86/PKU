#include <iostream>
#include <stdlib.h>
using namespace std;


struct node
{
	node *next;
	int v;
}*list[210];
int n;

int cmp(const void*a, const void*b)
{
	return *(int*)a - *(int*)b;
}
void Insert(int x, int y)
{
	node *p = new node;
	p->v = y;
	p->next = list[x];
	list[x] = p;
}

void Input()
{
	int i, j, x, y, r;
	for(i = 0; i < n; i++)
		list[i] = NULL;
	for(i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &r);
		for(j = 0; j < r; j++)
		{
			scanf("%d", &y);
			Insert(x, y);
		}
	}
}

int Dfs(int x)
{
	int nMax = 0;
	int ans = 0, j = 0, k;
	node *p = list[x];
	if(p == NULL)
		return 1;
	int *t = new int[n];
	while(p != NULL)
	{
		k = Dfs(p->v);
		t[j] = k;
		j++;
		if(k > nMax)
			nMax = k;
		p = p->next;
	}
	qsort(t, j, sizeof(t[0]), cmp);
	k = j;
	for(j = 0; j < k; j++)
	{
		if(j+1 > ans)
			ans = j+1;
		if(t[j] > ans)
			ans = t[j];
		if(j != 0 && ans < t[j-1]+1)
			ans = t[j-1]+1;
	}
	delete []t;
	return ans;
}

void Solve()
{
	int k = Dfs(1);
	printf("%d\n", k);
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d", &n);
		Input();
		Solve();
	}
	return 0;
}
