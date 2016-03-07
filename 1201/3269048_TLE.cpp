#include <iostream>
using namespace std;
struct ac
{
	int x,y,z;
}a[51000];
int d[51000];
int main ()
{
	int n,i;
	int x,y;
	bool flag;
	while ( scanf("%d",&n) != EOF )
	{
		flag= true;
		x = 20000000;
		y = -2000000;
		for ( i = 0; i < n; i++)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			a[i].y++;
			if ( a[i].x < x )
				x = a[i].x;
			if ( a[i].y > y )
				y = a[i].y;
		}
		for ( i = 0; i <= y; i++ )
			d[i] = -200000000;
		while ( flag )
		{
			flag =false;
			for ( i = 0; i < n; i++ )
			{
				if ( d[a[i].x] > d[a[i].y]-a[i].z )
				{
					d[a[i].x] = d[a[i].y]-a[i].z;
					flag = true;
				}
			}
			for ( i = y; i >= x; i-- )
			{
				if ( d[i] > d[i-1]+1 )
				{
					d[i] = d[i-1]+1;
					flag = true;
				}
			}
			for ( i = y; i >= x; i-- )
			{
				if ( d[i-1] > d[i] )
				{
					d[i-1] = d[i];
					flag = true;
				}
			}
		}
		cout<<d[y]-d[x-1]<<endl;
	}
	return 0;
}