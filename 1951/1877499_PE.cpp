#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main ()
{
	char a[100];
	int t[128];
	int k = 'A';
	int i;
	{
		for ( i = 0; i < 128; i++ )
			t[i] = 1;
		for ( i = 'B'; i <= 'Z'; i++ )
			t[i] = 0;
		t['A'] = 1;
		t['E'] = 1;
		t['I'] = 1;
		t['O'] = 1;
		t['U'] = 1;
		cin.getline ( a, 71 );
		i = 0;
		while ( a[i] == ' ' )
			i++;
		for ( ; a[i] != NULL; i++ )
		{
			if ( t[a[i]] == 0 )
			{
				if ( k == 32 )
					cout<<' ';
				cout<<a[i];
				k = a[i];
				t[k] = 1;
			}
			else if ( a[i] == ' ' )
			{
				k = 32;
			}
			else if ( a[i] == '.' || a[i] == ',' || a[i] == '?' )
			{
					k = a[i];
					cout<<a[i];
			}
		}
		cout<<endl;
	}
	return 21;
}