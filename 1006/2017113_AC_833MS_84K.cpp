#include <iostream>
using namespace std;
void main ( )
{
	int ip;
	int ie;
	int ii;
	int id;
	int day;
	int count = 1;
	bool flag = true;
	while ( scanf("%d %d %d %d",&ip,&ie,&ii,&id)!= EOF )
	{
	if ( ip ==-1 && ie ==-1 && ii ==-1 && id ==-1 )
	{
		break;
	}
	ip %= 23;
	ie %= 28;
	ii %= 33;
	for ( day = 1; day <= 21252; day++ )
	{
		if ( ( ip + day ) % 23 == 0 )
		{
			if ( ( ie + day ) % 28 == 0 )
			{
				if ( ( ii + day ) % 33 == 0 )
					break;
			}
		}
	}
	day = 21252 - day - id;
		if ( day <= 0 )
		day += 21252;
		printf("Case %d: the next triple peak occurs in %d days.\n",count++,day);
	}
}
