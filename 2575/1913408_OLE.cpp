#include <iostream>
using namespace std;
int main ()
{
	int n;
	int num;
	int pre;
	int i;
	bool exit;
	int a[100];
	while ( scanf("%d",&n) )
	{
		exit = 0;
		for ( i = 0; i < n+1; i++ )
			a[i] = 0;
		scanf("%d",&num);
		pre = num;
		for ( i = 1; i < n; i++ )
		{
			scanf("%d",&num );
			if ( num-pre > 0 )
			{
				if ( num - pre >= n )
				{
					exit = 1;
					printf("Not jolly\n");
					break;
				}
				a[num-pre]++;
			}
			else
			{
				if ( pre - num >= n )
				{
					exit = 1;
					printf ("Not jolly\n");
					break;
				}
				a[pre-num]++;
			}
		}
		if ( exit == 0 )
			printf("Jolly\n");
	}
	return 1;
}