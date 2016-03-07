#include <iostream>
using namespace std;
int main ()
{
	char a[500];
	int i;
	int c;
	while ( 1 )
	{
		c = 0;
		cin.getline(a,600,'\n');
		for ( i = 0; a[i] != NULL; i++ )
		{
			if ( a[i] == '/"' && c%2==0 )
			{
				cout<<"``";
				i++;
				c++;
			}
			else if ( a[i] == '/"' && c%2 == 1 )
			{
				cout<<"/'/'";
				i++;
				c++;
			}
			else 
				cout<<a[i];
		}
	}
	return 1;
}