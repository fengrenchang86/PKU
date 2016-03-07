#include <iostream>
using namespace std;
int f ( short a[], short b[],short l[], int y, int h )
{
	int i;
	for ( i= 1; i <= y; i++ )
	{
		if ( a[i] != b[i] )
			return 0;
	}
	l[h] = 1;
	return 1;
}

int main ()
{
	short l[101] = { 0 };
	short a[101][101] = { 0 };
	int p,t;
	int x,y;
	scanf("%d %d",&p,&t);
	while ( scanf("%d %d",&x,&y) !=EOF )
	{
		a[x][y] = 1;
	}
	int i,j;
	int c = p;
	for ( i = 1; i <= p-1; i++ )
	{
		for ( j = i+1; j <= p; j++ )
		{
			if ( l[j] == 0 )
				c-=f(a[i],a[j],l,t,j);
		}
	}
	printf("%d\n",c);	
	return 1;
}