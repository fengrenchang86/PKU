#include<iostream>
#include<stdlib.h>
using namespace std;
struct ac
{
	int i,j;
	int x,y;
}t[80000];
int cmp(const void*a, const void*b)
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	return c->x*d->y - c->y*d->x;
}
int main ()
{
	int x, y;
	int i, j, k = 0;
	while(scanf("%d%d", &x, &y) != EOF)
	{
		for(i = 1; i <= 32767; i++)
		{
			if(i % x == 0 )
				continue;
			j = i*y/x;
			t[k].x = abs(x*j-y*i);
			t[k].y = y*j;
			t[k].i = i;
			t[k].j = j;
			if(j <= 32767)
				k++;
			j++;
			t[k].x = abs(x*j-y*i);
			t[k].y = y*j;
			t[k].i = i;
			t[k].j = j;
			if(j <= 32767)
				k++;
		}
		qsort(t, k, sizeof(t[0]), cmp);
		for(i = 0; i < k; i++)
		{
			if(t[i].i*y != t[i].y * x)
				break;
		}
		cout<<t[i].i << " " << t[i].j << endl;
	}
	return 0;
}