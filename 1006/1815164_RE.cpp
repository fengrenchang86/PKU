#include <iostream.h>
void main ( )
{
	int a[100][4];
	int day;
	bool b1 = false;
	bool b2 = false;
	bool b3 = false;
	int count = 0;
	do
	{
		count++;
		cin>>a[count][0]>>a[count][1]>>a[count][2]>>a[count][3];
		if ( a[count][0] ==-1 && a[count][1] ==-1 && a[count][2] ==-1 && a[count][3] ==-1 )
			break;
	}while ( 1 );
	int i = 1;
	while ( i < count ) 
	{
	for ( day = 1; day <= 21252; day++ )
	{
		b1 = false;
		b2 = false;
		b3 = false;
		if ( ( a[i][0] + day ) % 23 == 0 )
			b1 = true;
		if ( ( a[i][1] + day ) % 28 == 0 )
			b2 = true;
		if ( ( a[i][2] + day ) % 33 == 0 )
			b3 = true;
		if ( b1 == true && b2 == true && b3 == true )
			break;
	}

	day = 21252 - day - a[i][3];
	if ( day <= 0 )
		day += 21252;
	cout<<"Case "<<i++<<": the next triple peak occurs in "<<day<<" days."<<endl;
	}
}