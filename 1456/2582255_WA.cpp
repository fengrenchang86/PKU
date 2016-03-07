#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int time,value;
}a[12000];
int cmp ( const void*a, const void*b )
{
	struct ac* c = (ac*)a;
	struct ac* d = (ac*)b;
	if ( c->time != d->time )
		return c->time-d->time;
	else
		return d->value-c->value;
}
int main ()
{
	int i,j,n,sum;
	while ( cin>>n )
	{
		for ( i = 0; i < n; i++ )
			scanf("%d%d",&a[i].value,&a[i].time);
		qsort(a,n,sizeof(a[0]),cmp);
		sum = 0;
		j = 1;
		for ( i = 0; i < n; i++ )
		{
			if ( a[i].time >= j )
			{
				sum += a[i].value;
				j++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}