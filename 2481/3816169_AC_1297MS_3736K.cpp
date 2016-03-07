#include<iostream>
#include <stdlib.h>

using namespace std;

struct ac
{
	int x, y, id;
	int ans;
}a[500100];
int c[500100];
int n, m;
int cmp(const void*a, const void*b)
{
	struct ac *c = (ac*)a;
	struct ac *d = (ac*)b;
	if(c->x != d->x)
		return c->x - d->x;
	else
		return d->y - c->y;
}
int comp(const void*a, const void*b)
{
	struct ac *c = (ac*)a;
	struct ac *d = (ac*)b;
	return c->id - d->id;
}
int LowBit( int x )
{
	return x & (x^(x-1));
}
void insert( int pos, int num )
{
	while( pos <= m )
	{
		c[pos] += num;
		pos += LowBit(pos);
	}
}
int Answer(int end)
{
	int sum = 0;
	while(end > 0)
	{
		sum += c[end];
		end -= LowBit(end);
	}
	return sum;
}
void input()
{
	int i;
	m = -1;
	a[0].x = -1;
	a[0].y = 2000000;
	a[0].id = 0;
	memset(c, 0, sizeof(c));
	for(i = 1; i <= n; i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].id = i;
		if(a[i].y > m)
			m = a[i].y;
	}
	qsort(a, n+1, sizeof(a[0]), cmp);
}

void solve()
{
	int i;
	for(i = 1; i <= n; i++)
	{
		if(a[i].x == a[i-1].x && a[i].y == a[i-1].y)
			a[i].ans = a[i-1].ans;
		else
			a[i].ans = i-1-Answer(a[i].y-1);
		insert(a[i].y,1);
	}
	qsort(a, n+1, sizeof(a[0]), comp);
	for( i = 1; i <= n; i++)
		printf("%d ",a[i].ans);
	printf("\n");
}
int main ()
{
	while(scanf("%d",&n)!=EOF && n)
	{
		input();
		solve();
	}
	return 0;
}