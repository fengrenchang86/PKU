#include <iostream>
using namespace std;

int com ( char *a, char *b )
{
	int i;
	for ( i = 0; a[i]!= NULL && b[i] != NULL; i++ )
	{
		if ( a[i] != b[i] )
			return 1;
	}
	return 0;
}
int main ()
{
	char put[20][20];
	int n = 0;
	int c=1;
	int i,j;
	bool im = true;
	while ( scanf("%s",put[n]) != EOF )
	{
		if ( put[n][0] == '9' )
		{
			for ( i = 0; i <= n; i++ )
			{
				for ( j = 0; j <= n; j++ )
				{
					if ( i != j )
					if ( com(put[i],put[j]) == 0 )
					{
						im = false;
						break;
					}
				}
				if ( im == false )
					break;
			}
			if ( im == false )
			{
				printf("Set %d is not immediately decodable\n",c);
			}
			else
			{
				printf("Set %d is immediately decodable\n",c);
			}
			im = true;
			c++;
			n = 0;
		}
		else
		{
			n++;
		}
	}
	return 1;
}