#include<iostream>
#include<stdlib.h>
#include <queue>
using namespace std;
struct ac
{
	int pos, fuel;
}a[12000];
int n, p, l;

queue<int>que;

int comp(const void*a, const void*b)
{
	struct ac* c = (ac*)a;
	struct ac* d = (ac*)b;
	return c->pos - d->pos;
}
void MissHH()
{
	scanf("%d",&n);
	int i;
	for(i = 1; i <= n; i++)
		scanf("%d %d", &a[i].pos, &a[i].fuel);
	scanf("%d %d", &p, &l);
	for(i = 1; i <= n; i++)
		a[i].pos = p - a[i].pos;
	a[0].pos = 0;
	a[0].fuel = p;
	qsort(a, n+1, sizeof(a[0]), comp);
}
void LoveHH()
{
	int i, nNum = 0;
	int nCurrentPos = 0, nFuel = 0;
	nFuel = l;
	for(i = 1; i <= n; i++)
	{
		que.push(a[i].fuel);
		while(nCurrentPos + nFuel < a[i].pos)
		{
			if(que.empty())
			{
				printf("-1\n");
				return;
			}
			nNum++;
			nFuel += que.front();
			que.pop();
		}
		nFuel -= (a[i].pos-nCurrentPos);
		nCurrentPos = a[i].pos;
	}
	printf("%d\n", nNum);
}

int main ()
{
	MissHH();
	LoveHH();
	return 0;
}