#include <iostream>
using namespace std;
int main ()
{
	int n;
	int num;
	int pre;
	int i;
	bool exit;
	bool f;
	int a[3010];
	while ( scanf("%d",&n)!=EOF )
	{
		f =1;
		exit = 0;
		for ( i = 0; i < n+1; i++ )
			a[i] = 0;
		scanf("%d",&num);
	//	if ( num == 0 )
		for ( i = 1; i < n; i++ )
		{
			pre = num;
			scanf("%d",&num );
			if ( num-pre > 0 )
			{
				if ( num - pre >= n )
				{
					exit = 1;
				//	printf("Not jolly\n");
					f = 0;
					break;
				}
				a[num-pre]++;
				if ( a[num-pre] > 1 )
				{
					exit = 1;
//					printf("Not jolly\n");
					f = 0;
					break;
				}
			}
			else if ( pre - num > 0 )
			{
				if ( pre - num >= n )
				{
					exit = 1;
				//	printf ("Not jolly\n");
					f = 0;
					break;
				}
				a[pre-num]++;
				if ( a[pre-num] > 1 )
				{
					exit = 1;
				//	printf("Not jolly\n");
					f = 0;
					break;
				}
			}
			else
			{
				exit = 1;
				//printf("Not jolly\n");
				f = 0;
				break;
			}
		}
		if ( i == 1 || f == 0)
			printf("Not jolly\n");
		else if ( exit == 0 )
			printf("Jolly\n");
	}
	return 1;
}