#include <iostream.h>
void main ()
{
	char in[200] ;
	char out[200];
	int i;
	int j = 0;
	bool isj = true;
	bool isc = true;
	bool exit = false;
	cin>>in;
	if ( in[0] < 'a' || in[0] > 'z' )
		isj = false;
	for ( i = 0; in[i] != NULL; i++ )
	{
		if ( in[i] == '_' )
		{
			isj = false;
		}
		if ( in[i] >= 'A' && in[i] <= 'Z' )
		{
			isc = false;
		}
	}
	for ( i = 0; in[i] != NULL; i++ )
	{
		if ( in[i] >= 'a' && in[i] <= 'z' )
		{
			out[j] = in[i];
//			i++;
			j++;
			continue;
		}
		if ( in[i] == '_' )
		{
			i++;
			isj = false;
			if ( isc == false )
			{
				exit = true;
				break;
			}
			if ( in[i] < 'a' || in[i] > 'z' )
			{
				exit = true;
				break;
			}
			else
			{
				out[j] = in[i] + 'A' - 'a';
//				i++;
				j++;
			}
		}
		else if ( in[i] >= 'A' && in[i] <= 'Z' )
		{
			isc = false;
			if ( isj == false )
			{
				exit = true;
				break;
			}
			out[j++] = '_';
			out[j] = in[i] - 'A' + 'a';
//			i++;
			j++;
		}
		else
			out[j++] = in[i];
	}
	if ( exit == true )
		cout<<"Error!"<<endl;
	else
	{
		for ( i = 0; i < j; i++ )
			cout<<out[i];
		cout<<endl;
	}
}