#include <iostream>
using namespace std;
int main ()
{
	char a[200];
	char b[200];
	int i;
	int j;
	while ( scanf("%s %s",a,b)!=EOF )
	{
	j = 0;
	for ( i = 0; b[i] != NULL; i++ )
	{
		if ( b[i] == a[j] )
			j++;
	}
	if ( j == strlen(a) )
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	}
	return 1;
}