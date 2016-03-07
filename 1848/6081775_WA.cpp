#include <iostream>
using namespace std;
struct ac
{
	int v;
	ac *next;
}*pList[200];
int n;
int a[200];
void Insert(int x, int y)
{
	ac *p = new ac;
	p->v = y;
	p->next = pList[x];
	pList[x] = p;
}
void Input()
{	
	int i;
	int ans = 0;
	for (i = 0; i <= n; i++)
	{
		pList[i] = NULL;
		a[i] = 0;
	}
	int x, y;
	for (i = 1; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		Insert(x, y);
		Insert(y, x);
		a[x]++;
		a[y]++;
	}
	for (i = 1; i <= n; i++)
	{
		if (a[i] == 1)
		{
			ans++;
		}
	}
	ans = (ans+1)/2;
	printf("%d\n", ans);
}
int main()
{
	while(scanf("%d", &n) != EOF)
	{
		Input();
	}
	return 0;
}