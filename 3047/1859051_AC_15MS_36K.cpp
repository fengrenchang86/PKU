#include <iostream.h>
int isleap ( int y )
{
	if ( y%4 == 0 && y%100 != 0 ||y%400 == 0 )
		return 1;
	else 
		return 0;
}

void main ()
{
	int list[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int year;
	int month;
	int day;
	int c;
	int i;
//	while ( 1 )
	{
		cin>>year>>month>>day;
		c = 0;
		for ( i = 1800; i < year; i+=4 )
			c += isleap(i);
		c +=  ( year - 1800 )*365;
		for ( i = 0; i < month-1; i++ )
			c += list[i];
		if (( isleap(year) == 1 ) && month >2 )
			c++;
		c += day;
		c = c + 2;
		c = c%7;
		switch(c)
		{
		case 0:
			cout<<"sunday"<<endl;
			break;
		case 1:
			cout<<"monday"<<endl;
			break;
		case 2:
			cout<<"tuesday"<<endl;
			break;
		case 3:
			cout<<"wednesday"<<endl;
			break;
		case 4:
			cout<<"thursday"<<endl;
			break;
		case 5:
			cout<<"friday"<<endl;
			break;
		case 6:
			cout<<"saturday"<<endl;
			break;
	}
	}
}