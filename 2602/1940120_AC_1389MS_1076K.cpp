#include <iostream>
using namespace std;
const int max = 1000;
int main ()
{
	int n;
	
	int a,b;
	int i,j;
	scanf("%d",&n);
	char *c = new char[n+1];
	c[0] = '0';
	for ( i = 1; i <= n; i++ )
	{
		scanf("%d %d",&a,&b);
		c[i] = a+b+'0';
	}
	c[i] = NULL;
	i--;
	while ( i >= 0 )
	{
		if ( c[i] >'9' )
		{
			c[i] -= 10;
			c[i-1]++;
		}
		i--;
	}
	i = 1;
	if ( c[0] != '0' )
		printf("%c",c[i]);
	while ( c[i] != NULL )
	{
		printf("%c",c[i]);
		i++;
	}
	printf("\n");
	return 1;
}