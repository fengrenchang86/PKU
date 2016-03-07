
#include <iostream>
using namespace std;
int leap ( int year )
{
	if ( year % 4 == 0 || year % 100 != 0 && year % 400 == 0 )
		return 1;
	else
		return 0;
}
int main ()
{
	int year,month,day;
	int i;
	int d;
	int n;
	int leap;
	int w;
	int y[4] = { 366,365,365,365 };
	int m[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};
	while ( scanf("%d",&n) && n != -1 )
	{
		w = n;
	//	n--;
		year = 2000;
		month = 1;
		day = 1;
		d = n;
		i = 0;
		while ( d > 0 )
		{
			d -= ( y[i%4] );
			year++;
			i++;
		}
		if ( d != 0 )
		{
		d+= y[(i+3)%4];
		year--;
		}
		if( year%4==0 && year%100!=0 || year%100==0 )
			leap = 1;
		else
			leap = 0;
		if ( d != 0 )
		{
			i = 0;
			while ( d > 0 )
			{
				d-=m[i++%12];
				month++;
			}
			d+=m[(i+11)%12];
			month--;
			if ( month > 2 )
				d -= leap;
			day += d;
		}
		w%=7;
		printf("%d-%d-%d ",year,month,day);
		switch(w)
		{
		case 1: printf("Sunday\n");break;
		case 2: printf("Monday\n");break;
		case 3: printf("Tuesday\n");break;
		case 4: printf("Wednesday\n");break;
		case 5: printf("Thursday\n");break;
		case 6: printf("Friday\n");break;
		case 0: printf("Saturday\n");break;
		}
	}
	return 1;
}