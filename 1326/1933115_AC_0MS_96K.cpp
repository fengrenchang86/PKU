#include <iostream>
using namespace std;
int main ()
{
	char place[100];
	int num;
	int sum;
//	int temp;
//	char ca[10];
	int i;
	bool exit = false;
	sum = 0;
	num = 0;
	while ( scanf("%s",place) && place[0] != '#' ) 
	{
		if ( place[0] == '0' )
		{
			printf("%d\n",sum);
			sum = 0;
			num = 0;
			continue;
		}
		scanf("%s %d %s",place,&num,place);
		if ( place[0] == 'F' )
			sum += num * 2;
		else if ( place[0] == 'B' )
			sum += (num+(num+1)/2);
		else
		{
			if ( num < 500 )
				num = 500;
			sum += num;
		}
	}
	return 1;
}