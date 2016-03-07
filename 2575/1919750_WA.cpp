#include <iostream>
using namespace std;
int main ()
{
	int n;
	int num;
	int pre;
	int i;
	bool f;
	short int a[3100];
	while ( scanf("%d",&n)!=EOF )
	{
		f =1;
		for ( i = 0; i < n+1; i++ )
			a[i] = 0;
		scanf("%d",&num);
	//	if ( num == 0 )
		for ( i = 1; i < n; i++ )
		{
			pre = num;
			scanf("%d",&num );
			if ( pre-num > 0 )
				a[pre-num]++;
			else
				a[num-pre]++;
		}
		f = 1;
		if ( a[0] == 1 )
			f = 0;
		else
		{
			for ( i = 1; i < n; i++ )
				if ( a[i] != 1 )
				{
					f = 0;
					break;
				}
		}
		if ( n == 1 )
			printf("Not jolly\n");
		else if ( f == 0)
			printf("Not jolly\n");
		else if ( f == 1 )
			printf("Jolly\n");
	}
	return 1;
}