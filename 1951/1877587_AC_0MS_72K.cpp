#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main ()
{
	char a[80];
	int t[26];
	int k = 'A';
	int c = 0;
	int i;
	{
		for ( i = 0; i <= 30; i++ )
			t[i] = 0;
		t['A'-'A'] = 1;
		t['E'-'A'] = 1;
		t['I'-'A'] = 1;
		t['O'-'A'] = 1;
		t['U'-'A'] = 1;
		cin.getline ( a, 71 );
		i = 0;
		while ( a[i] == ' ' )
			i++;
		for ( ; a[i] != NULL; i++ )
		{
			if ( t[a[i]-'A'] == 0 )
			{
				if ( c!=0 && k == 32 )
					cout<<' ';
				cout<<a[i];
				c++;
				k = a[i];
				t[k-'A'] = 1;
			}
			else if ( a[i] == ' ' )
			{
				k = 32;
			}
			else if ( a[i] == '.' || a[i] == ',' || a[i] == '?' )
			{
					k = a[i];
					cout<<a[i];
					c++;
			}
		}
		cout<<endl;
	}
	return 21;
}