#include <iostream>
using namespace std;
struct ac
{
	int left,right,high;
	int goleft,goright;
	ac(){goleft=goright=2000000000;}
}a[1002];
int n,x,y,max;
void paixu ( int n )
{
	int i,j;
	ac t;
	for ( i = 0; i < n-1; i++ )
	{
		for ( j = i+1; j < n; j++ )
		{
			if ( a[i].high < a[j].high )
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
			else if ( a[i].high == a[j].high && a[i].left > a[j].left )
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}
int findleft ( int k )
{
	int i;
	for ( i = k+1; i <= n; i++ )
	{
		if ( a[k].high-a[i].high > max )
			return 0;
		if ( a[i].left <= a[k].left && a[k].left <= a[i].right )
			return i;
	}
	return 0;
}
int findright ( int k )
{
	int i;
	for ( i = k+1; i <= n; i++ )
	{
		if ( a[k].high-a[i].high > max )
			return 0;
		if ( a[i].left <= a[k].right && a[k].right <= a[i].right ) 
			return i;
	}
	return 0;
}
int main ()
{
	int tcase;
	int i;
	int j;
	int l,r ;
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase--;
		scanf("%d%d%d%d",&n,&x,&y,&max);
		for ( i = 0; i < n; i++ )
		{
			scanf("%d%d%d",&a[i].left,&a[i].right,&a[i].high);
			a[i].goleft = a[i].goright = 2000000000;
			if ( a[i].left > a[i].right )
			{
				r = a[i].left;
				a[i].left = a[i].right;
				a[i].right = r;
			}
		}
		a[n].left = -300000;
		a[n].right = 300000;
		a[n].high = 0;
		paixu(n);
		for ( i = 0; i <= n; i++ )
		{
			if ( a[i].left <= x && x <= a[i].right && y - a[i].high >= 0 )
				break;
		}
		a[i].goleft = x-a[i].left;
		a[i].goright = a[i].right-x;
		if ( i == n )
			j = 0;
		else
			j = 2000000000;
		while ( i < n )
		{
		//	if ( a[i].goleft <= j )
			{
				l = findleft(i);
				if ( l == n )
				{
					if ( a[i].goleft < j )
						j = a[i].goleft;
				}
				else if ( l != 0 )
				{
					if ( a[l].goleft > a[i].goleft+a[i].left-a[l].left )
						a[l].goleft = a[i].goleft + a[i].left - a[l].left;
					if ( a[l].goright > a[i].goleft + a[l].right-a[i].left )
						a[l].goright = a[i].goleft + a[l].right-a[i].left;
				}
			}
	//		if ( a[i].goright <= j )
			{
				r = findright(i);
				if ( r == n )
				{
					if ( a[i].goright < j )
						j = a[i].goright;
				}
				else if ( r != 0 )
				{
					if ( a[r].goleft > a[i].goright + a[i].right - a[r].left )
						a[r].goleft = a[i].goright + a[i].right - a[r].left;
					if ( a[r].goright > a[i].goright + a[r].right - a[i].right )
						a[r].goright = a[i].goright + a[r].right - a[i].right;
				}
			}
			i++;
		}
		printf("%d\n",j+y);
	}
	return 0;
}