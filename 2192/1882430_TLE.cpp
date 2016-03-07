
#include <iostream>
using namespace std;


int main ()
{
	char a1[600];
	char a2[600];
	int i;
	int j;
	while (scanf("%s %s",a1,a2) )
	{
		int t[600][600] = {0};
		for ( i = 0; a1[i] != NULL; i++ )
			for ( j = 0; a2[j] != NULL; j++ )
			{
				if ( a1[i] == a2[j] )
					t[i+1][j+1] = t[i][j]+1;
				else
					t[i+1][j+1] = t[i][j+1]>t[i+1][j]?t[i][j+1]:t[i+1][j];
			}
		printf("%d",t[i][j]);		
	}
	return 1;
}

