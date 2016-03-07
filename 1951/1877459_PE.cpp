#include <iostream>
using namespace std;
int main ()
{
	char a[200];
	int t[128];
	char k;
	int i;
	for ( i = 0; i < 128; i++ )
		t[i] = 0;
	t['A'] = 1;
	t['E'] = 1;
	t['I'] = 1;
	t['O'] = 1;
	t['U'] = 1;
	t[' '] = 1;
	cin.getline ( a,200,'\n');
	i = 0;
	while ( a[i] == ' ' )
		i++;
	for ( ; a[i] != NULL; i++ )
	{
		if ( a[i] >= 'A' && a[i] <= 'Z' && t[a[i]] == 0 )
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
			if ( t[a[i]] == 0 )
			{
		//		t[a[i]] = 1;
				k = 0;
				cout<<a[i];
			}
		}
	}
	cout<<endl;
	return 21;
}