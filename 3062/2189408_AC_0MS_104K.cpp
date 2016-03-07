#include <iostream>
using namespace std;
int main ()
{
	char s[1000];
	while ( cin.getline(s,1000,'\n') )
		printf("%s\n",s);
	return 0;
}