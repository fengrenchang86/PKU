#include <iostream.h>
void main ( )
{
	int *a = new int[100];
	int ip;
	int ie;
	int ii;
	int id;
	int day;
	bool b1 = false;
	bool b2 = false;
	bool b3 = false;
	int count = 1;
	bool flag = true;
	while ( flag == true )
	{
	cin>>ip>>ie>>ii>>id;
	if ( ip ==-1 && ie ==-1 && ii ==-1 && id ==-1 )
	{
		flag = false;
		continue;
	}
	for ( day = 1; day <= 21252; day++ )
	{
		b1 = false;
		b2 = false;
		b3 = false;
		if ( ( ip + day ) % 23 == 0 )
			b1 = true;
		else continue;
		if ( ( ie + day ) % 28 == 0 )
			b2 = true;
		else continue;
		if ( ( ii + day ) % 33 == 0 )
			b3 = true;
		else continue;
		if ( b1 == true && b2 == true && b3 == true )
			break;
	}
	day = 21252 - day - id;
		if ( day <= 0 )
		day += 21252;
		a[count++] = day;
//		cout<<"Case "<<count-1<<": the next triple peak occurs in "<<a[count-1]<<" days."<<endl;
	}
	int i = count;
	count = 1;
	while ( count < i )
	{
		cout<<"Case "<<count<<": the next triple peak occurs in "<<a[count]<<" days."<<endl;
		count++;
	}
}