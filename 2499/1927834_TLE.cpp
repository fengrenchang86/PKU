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
				left++;
				x = x - y;
			}
			else
			{
				right++;
				y = y - x;
			}
		}
		printf("Scenario #%d:\n%d %d\n\n",k+1,left,right);
	}
	return 1;
}