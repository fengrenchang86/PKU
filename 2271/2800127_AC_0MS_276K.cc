#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main ()
{
	bool next = false;
//	fstream cin("in.txt");
	char ch[100];
	int len=0,n,i,j=0;
	while ( cin>>ch )
	{
		n = strlen(ch);
		if ( strcmp(ch,"<br>")==0 )
		{
			cout<<endl;
			len = 0;
			next = false;
		}
		else if ( strcmp(ch,"<hr>")==0 )
		{
			if ( next == true )
				printf("\n");
			for ( i = 0; i < 80; i++ )
				printf("-");
			printf("\n");
			next =false;
			len = 0;
		}
		else if ( len != 0 && n+len+1 < 80 )
		{
			printf(" %s",ch);
			len += n+1;
			next = true;
		}
		else if ( len == 0 && n+len < 80 )
		{
			printf("%s",ch);
			len += n;
			next = true;
		}
		else
		{
			printf("\n");
			printf("%s",ch);
			len = n;
			next = true;
		}
	}
	printf("\n");
	return 0;
}