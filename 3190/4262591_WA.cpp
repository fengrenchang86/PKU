#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;

struct ac
{
	int x, y, id;
}a[50100];
int b[50100];

struct hh
{
	int endTime, stallID;
	bool operator()(hh &m1, hh &m2)
	{
		return m1.endTime > m2.endTime;
	}
};
priority_queue<hh, vector<hh>, hh >que;

int n;
int cmp(const void*a, const void*b)
{
	struct ac *c = (ac*)a;
	struct ac *d = (ac*)b;
	if(c->x != d->x)
		return c->x - d->x;
	else
		return c->y - d->y;
}

void Input()
{
	int i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d %d", &a[i].x, &a[i].y);
		a[i].id = i;
	}
	qsort(a, n, sizeof(a[0]), cmp);
}
void Solve()
{
	int i, j = 1;
	hh q, nTop;
	for(i = 0; i < n; i++)
	{
		if(que.empty())
		{
			q.stallID = j;
			q.endTime = a[i].y;
			b[i] = j++;
			que.push(q);
		}
		else
		{
			nTop = que.top();
			que.pop();
			if(a[i].x > nTop.endTime)
			{
				q.endTime = a[i].y;
				q.stallID = nTop.stallID;
				b[i] = nTop.stallID;
				que.push(q);
			}
			else
			{
				q.endTime = a[i].y;
				q.stallID = j;
				b[i] = j++;
				que.push(q);
				que.push(nTop);
			}
		}
	}
	printf("%d\n", j-1);
	for(i = 0; i < n; i++)
		printf("%d\n", b[i]);
}
int main()
{
	Input();
	Solve();
	return 0;
}