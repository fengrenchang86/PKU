#include <iostream>
using namespace std;
int main ()
{
	double a,b,c;
	int count;
	while ( scanf("%lf %lf %lf",&a,&b,&c) && !(a==0&&b==0&&c==0) )
	{
		count = 0;
		if ( a <= 4.5 && b >= 150 && c >= 200 )
		{
			printf("Wide Receiver");
			count++;
		}
		if ( a <= 6.0 && b >= 300 && c >= 500 )
		{
			if ( count == 0 )
				printf("Lineman");
			else
				printf(" Lineman");
			count++;
		}
		if ( a <= 5.0 && b >= 200 && c >= 300 )
		{
			if ( count == 0 )
				printf("Quarterback");
			else
				printf(" Quarterback");
			count++;
		}
		if ( count == 0 )
			printf("No positions\n");
		else
			printf("\n");
	}
	return 1;
}