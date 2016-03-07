#include <iostream>
using namespace std;
int main ()
{
	short a[320][320];
	int i,j,x,y;
	int course,student;
	int tcase,it;
	scanf("%d",&tcase);
	for ( it = 0; it < tcase; it++ )
	{
		scanf("%d %d",&course,&student);
		for ( i = 0; i <= 310; i++ )
		{
			for ( j = 0; j <= 310; j++ )
				a[i][j] = 0;
		}
		for ( i = 1; i <= course;i++ )
		{
			scanf("%d",&x);
			for ( j = 1; j<=x; j++ )
			{
				scanf("%d",&y);
				a[x][y] = 1;
			}
		}
		y = 1;
		x = 0;
		for ( i = 1; i <= course; i++ )
		{
			x = 0;
			for ( j = 1; j <= student; j++ )
			{
				if ( a[i][j] == 1 )
				{
					x = 1;
					break;
				}
			}
			if ( x != 1 )
			{
				y = 0;
				break;
			}
		}
		if ( y == 0 )
		{
			printf("NO\n");
			continue;
		}
		y = 1;
		x = 0;
		for ( j = 1; j <= student; j++ )
		{
			x = 0;
			for ( i = 1; i <= course; i++ )
			{
				if ( a[j][i] == 1 )
				{
					x = 1;
					break;
				}
			}
			if ( x != 1 )
			{
				y = 0;
				break;
			}
		}
		if ( y == 0 )
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 1;
}