#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int profit,time;
}a[12000],b[12000];
int main ()
{
	int cmp ( const void*,const void*);
	void BigHeapInsert(int&,ac );
	void BigDel(int&);
	int i,j,n,sum,end,CurrentSize;
	ac p;
	while ( cin>>n )
	{
		for ( i = 0; i < n; i++ )
			scanf("%d%d",&b[i].profit,&b[i].time);
		qsort(b,n,sizeof(b[0]),cmp);
		end = b[n-1].time;
		CurrentSize = 1;
		sum = 0;
		j = 0;
		for ( i = 1; i <= end; i++ )
		{
			if ( b[j].time > i )
				continue;
			CurrentSize = 1;
			while ( b[j].time == i )
			{
				p = b[j];
				BigHeapInsert(CurrentSize,p);
				j++;
			}
			sum += a[1].profit;
		}
		cout<<sum<<endl;
	}
	return 0;
}
int cmp ( const void*a, const void*b )
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	return c->time-d->time;
}
void BigHeapInsert ( int& CurrentSize, ac x )
{
	int i = CurrentSize;
	while ( i > 1 )
	{
		if ( a[i/2].profit < x.profit )
		{
			a[i] = a[i/2];
			i /= 2;
		}
		else
			break;
	}
	a[i] = x;
	CurrentSize++;
}
void BigDel ( int& CurrentSize )
{
	CurrentSize--;
	ac item = a[CurrentSize];
	int i = 2;
	while ( i <= CurrentSize )
	{
		if ( i < CurrentSize && a[i].profit < a[i+1].profit )
			i++;
		if ( item.profit >= a[i].profit )
			break;
		a[i/2] = a[i];
		i *= 2;
	}
	a[i/2] = item;
}