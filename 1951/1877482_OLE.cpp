#include <iostream>
using namespace std;
int main ()
{
	char a[500];
	int t[128];
	char k = 'A';
	int i;
	while ( 1 )
	{
		for ( i = 0; i < 128; i++ )
			t[i] = 0;
		t['A'] = 1;
		t['E'] = 1;
		t['I'] = 1;
		t['O'] = 1;
		t['U'] = 1;
		t[' '] = 1;
		k = 'A';
		cin.getline ( a,500,'\n');
		i = 0;
		while ( a[i] == ' ' )
			i++;
		for ( ; a[i] != NULL; i++ )
		{
			if ( a[i] > 'A' && a[i] <= 'Z' && t[a[i]] == 0 )
			{
				if ( k == ' ' )
					cout<<' ';
				cout<<a[i];
				k = a[i];
				t[a[i]] = 1;
			}
			else if ( a[i] == ' ' )
			{
				k = ' ';
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