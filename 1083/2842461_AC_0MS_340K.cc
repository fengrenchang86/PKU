#include <iostream>
using namespace std;
int main ()
{
	int a[410];
	int tcase,n,i,j,k,end,time,x,y;
	scanf("%d",&tcase);
	while ( tcase-- )
	{
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for ( i = 0; i < n; i++ )
		{
			scanf("%d%d",&x,&y);
			if ( x > y )
			{
				k = x;
				x = y;
				y = k;
			}
			for ( j = (x+1)/2; j <= (y+1)/2; j++ )
				a[j]+=10;
		}
		j = 0;
		for ( i = 0; i <= 200; i++ )
		{
			if ( a[i] > j )
				j = a[i];
		}
		cout<<j<<endl;
	}
	return 0;
}
