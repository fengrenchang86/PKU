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
	for(i = 0; i <= n; i++)
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
	
	k = 0;
	while(p != NULL)
	{
		k++;
		p = p->next;
	}
	p = list[x];
	int *t = new int[k];
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
		if(t[j] < j+1)
			t[j] = j+1;
		if(j != 0 && t[j] < t[j-1]+1)
		{
			t[j] = t[j-1]+1;
		}
	}
	ans = t[j-1];
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
	int i;
	for(i = 0; i < 210; i++)
		list[i] = NULL;
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d", &n);
		Input();
		Solve();
	}
	return 0;
}
