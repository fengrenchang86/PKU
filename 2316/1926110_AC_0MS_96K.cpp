#include <iostream>
using namespace std;
int main ()
{
	char a[20];
	int b[20] = { 0 };
	int i;
	int j;
	while ( scanf("%s",a) !=EOF)
	{	
		for ( i = 0; a[i] != NULL; i++ )
		{
			b[i] += (a[i]-'0');
			b[i] %= 10;
		}
	}
	for ( j = 0; j < i; j++ )
		printf("%d",b[j]);
	printf("\n");
	return 1;
}
