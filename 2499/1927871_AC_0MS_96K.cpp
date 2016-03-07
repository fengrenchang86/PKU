#include <iostream>
using namespace std;
int main ()
{
	int n;
	int x,y;
	int left,right;
	int k;
	scanf("%d",&n);
	for ( k = 0; k < n; k++ )
	{
		left = right = 0;
		scanf("%d %d",&x,&y);
		while ( !(x==1&&y==1) )
		{
			if ( x > y )
			{
				if ( x % y == 0 )
				{
					left += (x-1);
					break;
				}
				left+=x/y;
				x = x%y;
			}
			else
			{
				if ( y % x == 0 )
				{
					right += ( y-1);
					break;
				}
				right+=y/x;
				y = y%x;
			}
		}
		printf("Scenario #%d:\n%d %d\n\n",k+1,left,right);
	}
	return 1;
}