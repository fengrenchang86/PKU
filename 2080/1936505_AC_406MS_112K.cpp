
#include <iostream>
using namespace std;
int l ( int year )
{
	if ( year % 4 == 0 && year % 100 != 0 || year % 400 == 0 )
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
			d -= 365;
			if ( l(year)==1 )
				d--;
			year++;
		}
		if ( d != 0 )
		{
		d+= 365;
		year--;
		if ( l(year)==1 )
			d++;
		}
		leap = l(year);
		if ( d != 0 )
		{
			i = 0;
			while ( d > 0 )
			{
				if ( i%12==1 )
					d-=leap;
				d-=m[i++%12];
				month++;
			}
			if ( d != 0 )
			{
				d+=m[(i+11)%12];
				month--;
				if ( (i+11)%12 == 1 )
					d+= leap;
			}
				day += d;
		}
		w%=7;
	//	if ( month == 13 )
	//	{
	//		month = 1;
	//		year++;
	//	}
		cout<<year<<"-";
		if ( month < 10 )
			cout<<0;
		cout<<month<<"-";
		if ( day < 10 )
			cout<<0;
		cout<<day<<' ';
//		printf("%d-%d-%d ",year,month,day);
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