#include <iostream>
#include <stdio.h>
using namespace std;
int main ()
{
	char a[500],b;
	int i;
	int c;
	int d;
	while((b=getchar())!=EOF)
	{
		c = 0;
//		cin.getline ( a,1000,'\n');
	/*	for ( i = 0; a[i] != NULL; i++ )
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
		printf("\n");
		cin.ignore();*/
		if ( b == '/"' && c%2==0 )
		{
			cout<<"``";
			c++;
		}
		else if ( b == '/"' && c%2==1 )
		{
			cout<<"\'\'";
			c++;
		}
		else
			cout<<b;
	}
	return 1;
}