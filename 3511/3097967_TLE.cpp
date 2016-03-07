#include <iostream>
using namespace std;
int a[800000];
int make ()
{
	int i,j,k=2;
	a[0] = 2;
	a[1] = 3;
	for ( i = 3; i <= 1000000; i+=2 )
	{
		for ( j = 3; j*j <= i; j+= 2 )
		{
			if ( i % j == 0 )
				break;
		}
		if ( i % j != 0 )
			a[k++] = i;
	}
	return k;
}
int main ()
{
	int k = make();
	int i,j,l,u,x,y;
	while ( cin>>l>>u )
	{
		if ( l == -1 && u == -1 )
			break;
		if ( l < 0 )
			l = 0;
		i = 0;
		x = y = 0;
		while ( a[i] < l && i < k )
			i++;
		while ( a[i] <= u && i < k )
		{
			x++;
			if ( (a[i]-1)%4==0 )
				y++;
			i++;
		}
		printf("%d %d %d %d\n",l,u,x,y);
	}
	return 0;
}