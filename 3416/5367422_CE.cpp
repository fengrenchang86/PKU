#include <iostream>
#include <stdlib.h>
using namespace std;

struct ac
{
	int x, y;
	int ntype;
}p[600010];
int t[2000040];
int n, m, k;
int acmax;
struct wf
{
	int small, big;
}q[500010];
int cmp(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	if(c->x != d->x)
		return c->x - d->x;
	else
		return c->y - d->y;
}
int cmp2(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	if(c->x != d->x)
		return d->x - c->x;
	else
		return d->y - c->y;
}
void Input()
{
	int i;
	scanf("%d %d", &n, &m);
	acmax = 0;
	for(i = 0; i < n; i++)
	{
		scanf("%d %d", &p[i].x, &p[i].y);
		p[i].ntype = -1;
	}
	for(i = 0; i < m; i++)
	{
		scanf("%d %d", &p[i+n].x, &p[i+n].y);
		p[i+n].ntype = i;
