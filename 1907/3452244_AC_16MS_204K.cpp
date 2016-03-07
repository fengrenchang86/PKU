#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	char name[100];
	int x,y;
	int cost;
}v[120];
int cmp ( const void*a, const void*b )
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	if ( c->cost != d->cost )
		return c->cost - d->cost;
	else
		return strcmp(c->name,d->name);
}
int main ()
{
	int a,b;
	int tc,x,y,n,i,j,k,it=1;
	char ch[1000];
	scanf("%d",&tc);
	while ( tc-- )
	{
		scanf("%d%d%d",&a,&b,&n);
		for ( i = 0; i < n; i++ )
		{
			scanf("%s",&ch);
			for ( j = 0; ch[j] != ':'; j++ )
			{
				v[i].name[j] = ch[j];
			}
			v[i].name[j] = 0;
			k = 0;
			while ( ch[j] < '0' || ch[j] > '9' )
				j++;
			while ( ch[j] >= '0' && ch[j] <= '9' )
			{
				k *= 10;
				k += (ch[j]-'0');
				j++;
			}
			v[i].x = k;
			k = 0;
			while ( ch[j] < '0' || ch[j] > '9' )
				j++;
			while ( ch[j] >= '0' && ch[j] <= '9' )
			{
				k *= 10;
				k += (ch[j]-'0');
				j++;
			}
			x = a;
			y = b;
			v[i].y = k;
			v[i].cost = (x-y)*v[i].x;
			k = 0;
			while ( x / 2 >= y && x!=1 )
			{
				x /= 2;
				k += v[i].y;
				if ( k+(x-y)*v[i].x < v[i].cost )
					v[i].cost = k+(x-y)*v[i].x;
			}
		}
		qsort(v,n,sizeof(v[0]),cmp);
		printf("Case %d\n",it++);
		for ( i = 0; i < n; i++ )
		{
			printf("%s %d\n",v[i].name,v[i].cost);
		}
	}
	return 0;
}