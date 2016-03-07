#include <iostream>
using namespace std;
int main ()
{
	char a[300];
	int tcase;
	int i,num;
	int miner;//+or-
	int left,leftx,right,rightx;
	cin>>tcase;
	while ( tcase )
	{
		tcase--;
		cin>>a;
		left = leftx = right = rightx = 0;
		num = 0;
		if ( a[0] == '-' )
		{
			miner = -1;
			i = 1;
		}
		else
		{
			miner = 1;
			i = 0;
		}
		for ( ; a[i] != '='; i++ )
		{
			if ( a[i] >= '0' && a[i] <= '9' )
			{
				num *= 10;
				num += (a[i]-'0');
			}
			else if ( a[i] == 'x' )
			{
				if ( num == 0 )
					num = 1;
				num *= miner;
				leftx += num;
				num = 0;
			}
			else if ( a[i] == '+' )
			{
				num *= miner;
				left += num;
				miner = 1;
				num = 0;
			}
			else if ( a[i] == '-' )
			{
				num *= miner;
				left += num;
				miner = -1;
				num = 0;
			}
			else
			{
				num *= miner;
				left += num;
			}
		}
		num *= miner;
		left += num;
		num = 0;
		i++;
		if ( a[i] == '-' )
		{
			miner = -1;
			i++;
		}
		else
			miner = 1;
		while ( a[i] != NULL )
		{
			if ( a[i] >= '0' && a[i] <= '9' )
			{
				num *= 10;
				num += (a[i]-'0');
			}
			else if ( a[i] == 'x' )
			{
				if ( num == 0 )
					num = 1;
				num *= miner;
				rightx += num;
				num = 0;
			}
			else if ( a[i] == '+' )
			{
				num *= miner;
				right += num;
				miner = 1;
				num = 0;
			}
			else if ( a[i] == '-' )
			{
				num *= miner;
				right += num;
				miner = -1;
				num = 0;
			}
			else
			{
				num *= miner;
				right += num;
			}
			i++;
		}
		num *= miner;
		right += num;
		leftx -= rightx;
		right -= left;
		if ( leftx != 0 )
		{
			if ( right/leftx > 0 )
				printf("%d\n",right/leftx);
			else
				printf("%d\n",right/leftx-1);
		}
			
		else
		{
			if ( right == 0 )
				printf("IDENTITY\n");
			else
				printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}