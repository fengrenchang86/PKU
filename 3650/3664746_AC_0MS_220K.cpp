#include <iostream>
using namespace std;
char ch[10000];
int main ()
{
	int i;
	while ( gets(ch))
	{
		if ( ch[0] == '#' )
			break;
		for ( i = 0; ch[i] != 0; i++ )
		{
			if ( ch[i] == ' ' )
				cout<<"%20";
			else if ( ch[i] == '!' )
				cout<<"%21";
			else if ( ch[i] == '$' )
				cout<<"%24";
			else if ( ch[i] == '%' )
				cout<<"%25";
			else if ( ch[i] == '(' )
				cout<<"%28";
			else if ( ch[i] == ')' )
				cout<<"%29";
			else if ( ch[i] == '*' )
				cout<<"%2a";
			else
				printf("%c",ch[i]);
		}
		printf("\n");
	}
	return 0;
}