#include<iostream>
#include<stdlib.h>
using namespace std;
struct huihui
{
	int x,y;
	bool use;
}a[12000];
int n,m;
int cmp(const void*a, const void*b)
{
	struct huihui *c = (huihui*)a;
	struct huihui *d = (huihui*)b;
	if(c->x != d->x)
		return c->x - d->x;
	else
		return c->y - d->y;
}
void input()
{
	int i;
	scanf("%d %d",&n, &m);
	for(i = 0; i < n; i++)
	{
		scanf("%d%d",&a[i].x, &a[i].y);
		a[i].use = true;
	}
	qsort(a, n, sizeof(a[0]), cmp);
}
void LoveHH()
{
	int i, j, k, rest = 0, end = -1;
	for(i = 1; i < n; i++)
	{
		if(a[i-1].y >= a[i].x)
		{
			a[i].x = a[i-1].x;
			a[i-1].use = false;
		}
	}
	j = 0;
	for(i = 0; i < n; i++)
	{
		if(a[i].use)
			a[j++] = a[i];
	}
	n = j;
	k = 0;
	for(i = 0; i < n; i++)
	{
		if(a[i].x <= end)
			a[i].x = end+1;
		if(a[i].x >= a[i].y)
			continue;
		k += (a[i].y - a[i].x) / m;	
		rest = m - (a[i].y - a[i].x) % m;
		rest %= m;
		if(rest != 0)
			k++;
		end = a[i].y + rest - 1;
	}
	cout<<k<<endl;
}
int main ()
{
	input();
	LoveHH();
	return 0;
}