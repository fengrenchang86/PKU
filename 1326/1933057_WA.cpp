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
	sum = 0.0;
	num = 0.0;
	while ( 1 )
	{
		sum = 0.0;
//		cin.ignore();
		cin.getline ( place,100,'\n');
		if ( place[0] == '#' )
			return 1;
		else if ( place[0] == '0' )
		{
			printf("%d\n",num);
			num = 0.0;
		}
		else
		{
			for ( i = 0; place[i] <= '0' || place[i] >= '9'; )
				i++;
			while ( place[i] >= '0' && place[i] <= '9' )
			{
				sum *= 10;
				sum += (place[i]-'0');
				i++;
			}
			i++;
			if ( place[i] == 'F' )
				sum *= 2;
			else if ( place[i] == 'B' )
			{
				if ( sum*5%10 >= 5 )
					sum = sum + sum/2+1;
				else
					sum += sum/2;
			}
			else
			{
				if ( sum < 500 )
					sum = 500;
			}
		num += sum;
		}
	}
	return 1;
}