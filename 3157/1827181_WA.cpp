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
	
	for ( i = 0; in[i] != NULL;  )
	{
		if ( in[i] >= 'a' && in[i] <= 'z' )
		{
			out[j] = in[i];
			i++;
			j++;
			continue;
		}
		if ( in[i] == '_' )
		{
			i++;
			isj = false;
			if ( in[i] >= 'A' && in[i] <= 'Z' )
			{
				exit = true;
				break;
			}
			else
			{
				out[j] = in[i] + 'A' - 'a';
				i++;
				j++;
			}
		}
		else if ( in[i] >= 'A' && in[i] <= 'Z' )
		{
			isc = false;
			out[j++] = '_';
			out[j] = in[i] - 'A' + 'a';
			i++;
			j++;
		}
	}
	if ( exit == true || isj == false && isc == false )
		cout<<"Error!"<<endl;
	else
	{
		for ( i = 0; i < j; i++ )
			cout<<out[i];
		cout<<endl;
	}
}