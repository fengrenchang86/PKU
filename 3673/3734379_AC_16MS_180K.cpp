#include <iostream>
using namespace std;
int main ()
{
	char a[1000],b[1000];
	int n = 0;
	int i,j;
	scanf(" %s %s",a,b);
	for ( i = 0; a[i] != 0; i++ )
	{
		for ( j = 0; b[j] != 0; j++ )
			n += (a[i]-'0')*(b[j]-'0');
	}
	printf("%d\n",n);
	return 0;
}