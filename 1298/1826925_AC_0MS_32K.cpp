#include <iostream.h>

class chang
{
public:
	char list[26];
	char in[100];
	char out[100];
	int input ( );
	int	compare ( char *, char * );
	void go ( );
	chang( );
};

chang::chang ( )
{
	int i = 0;
	for ( i = 0; i < 5; i++ )
		list[i] = 'V' + i;
	for ( i = 5; i < 26; i++ )
		list[i] = 'A' + i - 5;
}
int chang::compare ( char *a1, char *a2 )
{
	int i = 0;
	for ( i = 0; a1[i] != NULL; i++ )
	{
		if ( a1[i] != a2[i] )
			return 0;
	}
	return 1;
}

int chang::input ( )
{
	cin.getline ( in, 100, '\n' );
	return 1;
}

void chang::go ( )
{
	int n;
	bool exit = false;
	while ( exit == false )
	{
	chang::input ( );
	n = compare ( in, "ENDOFINPUT" );
	if ( n == 1 )
		break;
	n = compare ( in, "START" );
	while ( n == 0 )
	{
		chang::input ( );
		n = compare ( in, "ENDOFINPUT" );
		if ( n == 1 )
		{
			exit = true;
			break;
		}
		n = compare ( in, "START" );
	}
	if ( exit == true )
		break;
	chang::input ( );
	for ( n = 0; in[n] != NULL; n++ )
	{
		if ( in[n] >= 'A' && in[n] <= 'Z' )
		{
			out[n] = list[in[n] - 'A'];
			cout<<out[n];
		}
		else
		{
			out[n] = in[n];
			cout<<out[n];
		}
	}
	cout<<endl;
	chang::input ( );
	n = compare ( in, "END" );
	while ( n == 0 )
	{
		chang::input ( );
		n = compare ( in, "END" );
	}
	}

}

void main ( )
{
	chang a;
	a.go ( );

}