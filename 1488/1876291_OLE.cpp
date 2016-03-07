#include <iostream>
#include <stdio.h>
using namespace std;
int main ()
{
	char a[500];
	int i;
	int c;
	while ( 1 )
	{
		c = 0;
		cin.getline ( a,1000,'\n');
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
				printf("%c",a[i]);
		}
		cout<<endl;
	}
	return 1;
}