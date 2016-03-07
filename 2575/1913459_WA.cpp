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
	while ( scanf("%d",&n)!=EOF )
	{
		exit = 0;
		for ( i = 0; i < n+1; i++ )
			a[i] = 0;
		scanf("%d",&num);
		for ( i = 1; i < n; i++ )
		{
			pre = num;
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
				if ( a[num-pre] > 1 )
				{
					exit = 1;
					printf("Not jolly\n");
					break;
				}
			}
			else if ( pre - num > 0 )
			{
				if ( pre - num >= n )
				{
					exit = 1;
					printf ("Not jolly\n");
					break;
				}
				a[pre-num]++;
				if ( a[pre-num] > 1 )
				{
					exit = 1;
					printf("Not jolly\n");
					break;
				}
			}
			else
			{
				exit = 1;
				printf("Not jolly\n");
				break;
			}
		}
		if ( exit == 0 )
			printf("Jolly\n");
	}
	return 1;
}