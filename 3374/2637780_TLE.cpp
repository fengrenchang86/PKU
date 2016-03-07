#include <iostream>
using namespace std;
struct ac
{
	int up,down;
}a[6600000],b[6600000];
void SmallHeapInsert (int& CurrentSize, ac x )
{
	int i = CurrentSize;
	while ( i > 1 )
	{
		if ( a[i/2].up*x.down > x.up*a[i/2].down )
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
void SmallDel (int& CurrentSize )
{
	CurrentSize--;
	ac item = a[CurrentSize];
	int i = 2;
	while ( i <= CurrentSize )
	{
		if ( i < CurrentSize && a[i].up*a[i+1].down > a[i+1].up*a[i].down )
			i++;
		if ( item.up*a[i].down <= a[i].up*item.down )
			break;
		a[i/2] = a[i];
		i *= 2;
	}
	a[i/2] = item;
}
int gcd(int m,int n)
{
	int p;
	while(n)
	{
		p=m%n;
		m=n;
		n=p;
	}
	return m;
}
int main ()
{
	int n,c,i,j,CurrentSize = 1;
	int t;
	scanf("%d%d",&n,&c);
	a[0].up = 0;
	a[0].down = 1;
	SmallHeapInsert(CurrentSize,a[0]);
	a[0].up = 1;
	a[0].down = 1;
	SmallHeapInsert(CurrentSize,a[0]);
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j < i; j++ )
		{
			a[0].up = j;
			a[0].down = i;
			if ( gcd(i,j) == 1 )
				SmallHeapInsert(CurrentSize,a[0]);
		}
	}
	j = 1;
	b[j] = a[1];
	SmallDel(CurrentSize);
	i = CurrentSize;
	while ( i > 0 )
	{
		if ( a[1].up*b[j].down == a[1].down*b[j].up )
			SmallDel(CurrentSize);
		else
		{
			b[j+1] = a[1];
			SmallDel(CurrentSize);
			j++;
		}
		i--;
	}
	t = j;
	for ( i = 0; i < c; i++ )
	{
 		scanf("%d",&j);
		if ( j > t )
		{
			cout<<"No Solution"<<endl;
			continue;
		}
		printf("%d/%d\n",b[j].up,b[j].down);
	}
	return 0;
}