#include <iostream>
using namespace std;
const int max = 1000;
int main ()
{
	int n;
	char c[max];
	int a,b;
	int i,j;
	c[0] = '0';
	scanf("%d",&n);
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