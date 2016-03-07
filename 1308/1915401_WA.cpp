#include <iostream>
using namespace std;
int main ()
{
	short a[10000];
	bool yes;
	int x,y;
	int i;
	int j = 1;
	bool exit = false;
	while ( 1 )
	{
		for ( i = 0; i < 10000; i++ )
			a[i] = 0;
		yes = true;
		while ( scanf("%d %d",&x,&y) && !(x==0&&y==0) && !(x==-1&&y==-1) )
		{
			if ( a[y] == 1 )
				yes = false;
			else
				a[y] = 1;
		}
		if ( x == 0 && y== 0 )
		{
			if ( yes == true )
				printf("Case %d is a tree.\n",j);
			else
				printf("Case %d is not a tree.\n",j);
		}
		if ( x==-1 && y== -1 )
			break;
		j++;
	}
	return 1;
}
