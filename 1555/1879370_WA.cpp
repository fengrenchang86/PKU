#include <iostream>
using namespace std;
int main ()
{
	int a[9];
	int i;
//	while ( 1 )
	{
		for ( i = 0; i < 9; i++ )
			cin>>a[i];
		i = 0;
		while( a[i] == 0 )
			i++;
		if ( i == 7 )
		{
			if ( a[i] == 1 )
				cout<<'x';
			else if ( a[i] == -1 )
				cout<<"-x";
			else
				cout<<a[i]<<'x';
		}
		else if ( i == 8 )
			cout<<a[i];
		else if ( i == 9 )
			cout<<0;
		else
		{
			if ( a[i] == 1 )
				cout<<"x^"<<8-i;
			else if ( a[i] == -1 )
				cout<<"-x^"<<8-i;
			else if ( a[i] > 0 )
				cout<<a[i]<<"x^"<<8-i;
			else
				cout<<a[i]<<"x^"<<8-i;
		}
		i++;
		for ( ; i < 7; i++ )
		{
			if ( a[i] == 0 )
				continue;
			if ( a[i] == 1 )
				cout<<" + "<<"x^"<<8-i;
			else if ( a[i] == -1 )
				cout<<" - "<<"x^"<<8-i;
			else if ( a[i] > 0 )
				cout<<" + "<<a[i]<<"x^"<<8-i;
			else
				cout<<" - "<<-1*a[i]<<"x^"<<8-i;
		}
		if ( i > 8 )
		{
			cout<<endl;
			return 1;
//			continue;
		}
		if ( i == 7 )
		{
			if ( a[i] == 0 )
				;
			else if ( a[i] == 1 )
				cout<<" + x";
			else if ( a[i] == -1 )
				cout<<" - x";
			else if ( a[i] > 0 )
				cout<<" + "<<a[i]<<'x';
			else
				cout<<" - "<<-1*a[i]<<'x';
			i++;
		}
		if ( i == 8 )
		{
			if ( a[i] == 0 );
			else if ( a[i] == 1 )
				cout<<" + 1";
			else if ( a[i] == -1 )
				cout<<" - 1";
			else if ( a[i] > 0 )
				cout<<" + "<<a[i];
			else
				cout<<" - "<<-1*a[i];
		}
		cout<<endl;

	}

	return 1;
}