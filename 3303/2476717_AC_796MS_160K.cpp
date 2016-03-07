#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int begin,end;
	int go[9];
}t[20];
int v[10];
bool flag;
int cmp(const void*a, const void*b)
{
	struct ac *c = (ac*)a;
	struct ac *d = (ac*)b;
	if ( c->begin != d->begin )
		return c->begin - d->begin;
	else
		return c->end-d->end;
}
void dfs ( int c, int lay )
{
	if ( c == lay )
	{
		flag = true;
		return;
	}
	int i,a;
	for ( i = 1; i <= 8; i++ )
	{
		if ( t[c].go[i] == 1 && v[i] < t[c].begin)
		{
			a = v[i];
			v[i] = t[c].end;
			dfs ( c+1 ,lay);
			if ( flag == true )
				return;
			v[i] = a;
		}
	}
}
int main ()
{
	int tcase,r,x;
	int i,j,d;
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase--;
		memset(v,0,sizeof(v));
		flag = false;
		scanf("%d",&r);
		for ( i = 0; i <r; i++ )
		{
			scanf("%d%d",&t[i].begin,&t[i].end);
			for ( j = 1; j <= 8; j++ )
				t[i].go[j] = 0;
			scanf("%d",&d);
			for ( j = 0; j < d; j++ )
			{
				scanf("%d",&x);
				t[i].go[x] = 1;
			}
		}
		qsort(t,r,sizeof(t[0]),cmp);
		dfs(0,r);
		if ( flag == true )
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}