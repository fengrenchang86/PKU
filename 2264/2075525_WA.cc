#include <iostream>
using namespace std;
int main ()
{
	char a[120];
	char b[120];
	int la[256],lb[256];
	int i,j;
	while ( scanf("%s%s",a,b)!=EOF )
	{
		for ( i = 0; i < 256; i++ )
			lb[i] = la[i] = 0;
		for ( i = 0; a[i] != NULL; i++ )
			la[a[i]]++;
		for ( i = 0; b[i] != NULL; i++ )
			la[b[i]]--;
		printf("%s",a);
		for ( i = 10; i < 128; i++ )
		{
			if ( la[i] < 0 )
			{
				la[i] *= -1;
				for ( j = 0; j < la[i]; j++ )
					printf("%c",char(i));
			}
/*			else if ( la[i] > 0 )
			{
				for ( j = 0; j < la[i]; j++ )
					printf("%c",char(i));
			}
*/		}
		printf("\n");
	}
	return 0;
}