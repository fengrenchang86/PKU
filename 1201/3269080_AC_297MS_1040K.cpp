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
	int x,y,t;
	bool flag;
	while ( scanf("%d",&n) != EOF )
	{
		flag= true;
		x = 200000000;
		y = 0;
		for ( i = 0; i < n; i++)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			a[i].y++;
			if ( a[i].x < x )
				x = a[i].x;
			if ( a[i].y > y )
				y = a[i].y;
		}
		for ( i = x-1; i <= y; i++ )
			d[i] = 0;
		while ( flag )
		{
			flag =false;
			for ( i = 0; i < n; i++ )
			{
				t = d[a[i].y]-a[i].z;
				if ( d[a[i].x] > t )
				{
					d[a[i].x] = t;
					flag = true;
				}
			}
			for ( i = 1; i <= y; i++ )
			{
				if ( d[i] > d[i-1]+1 )
				{
					d[i] = d[i-1]+1;
					flag = true;
				}
			}
			for ( i = 1; i <= y; i++ )
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