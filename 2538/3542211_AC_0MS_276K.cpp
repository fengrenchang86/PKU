#include <iostream>
using namespace std;
char pre[30]={'a','V','X','S','W','D','F','G','U','H','J','K','N','B','I','O','Q','E','A','R','Y','C','Q','Z','T','Z'};
int main ()
{
	char ch[1000];
	int i;
	while ( cin.getline(ch,1000,'\n') )
	{
		for ( i = 0; ch[i] != 0; i++ )
		{
			if ( ch[i] >= '2' && ch[i] <= '9' )
				cout<<char(ch[i]-1);
			else if ( ch[i] == '1' )
				cout<<'`';
			else if ( ch[i] == '0' )
				cout<<'9';
			else if ( ch[i] == '-' )
				cout<<0;
			else if ( ch[i] == '=' )
				cout<<'-';
			else if ( ch[i] > 'A' && ch[i] <= 'Z' )
				cout<<pre[ch[i]-'A'];
			else if ( ch[i] == ' ' )
				cout<<' ';
			else if ( ch[i] == '.' )
				cout<<',';
			else if ( ch[i] == ',' )
				cout<<'M';
			else if ( ch[i] == ']' )
				cout<<'[';
			else if ( ch[i] == '[' )
				cout<<'P';
			else if ( ch[i] == ';' )
				cout<<'L';
			else if ( ch[i] == '\'' )
				cout<<";";
			else if ( ch[i] == '\\' )
				cout<<']';
			else if ( ch[i] == '/' )
				cout<<'.';
		}
		cout<<endl;
	}
	return 0;
}