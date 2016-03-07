#include<iostream>
using namespace std;
int main ()
{
	char ch[1000];
	cin>>ch;
	int i;
	for ( i = 2; ch[i] != NULL;)
	{
		printf("%c",ch[i]);
		i++;
		if ( ch[i] >= 'A' && ch[i] <= 'Z' )
		{
			cout<<ch[i];
			i++;
		}
		while ( ch[i] >= '0' && ch[i] <= '9' || ch[i] == '=')
		{
			printf("%c",ch[i]);
			i++;
		}
		printf("\n");
	}
	return 0;
}