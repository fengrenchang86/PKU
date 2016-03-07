#include <iostream>
using namespace std;
int main ()
{
	int a[10][10];
	int i,j,k;
	for ( i = 0; i <= 9; i++ )
	{
		a[i][0] = 1;
		a[i][1] = 1;
		a[i][2] = 1;
		a[i][3] = 1;
		a[i][4] = 0;
		a[i][5] = 1;
		a[i][6] = 1;
	}
	a[1][0] = a[4][0] = 0;
	a[1][1] = a[2][1] = a[3][1] = a[7][1] = 0;
	a[5][2] = a[6][2] = 0;
	a[1][3] = a[7][3] = a[0][3] = 0;
	a[2][4] = a[6][4] = a[8][4] = a[0][4] = 1;
	a[2][5] = 0;
	a[1][6] = a[4][6] = a[7][6] = 0;
	int n;
	char s[10];
	while ( scanf("%d %s",&n,&s) !=EOF )
	{
		if ( n==0 )
			break;
		for ( j = 0; s[j] != NULL; j++ )
		{
			printf(" ");
			if ( a[s[j]-'0'][0] == 0 )
			{
				for ( i = 0; i < n; i++ )
					printf(" ");
			}
			else
			{
				for ( i = 0; i < n; i++ )
					printf("-");
			}
			printf(" ");
	//		if ( s[j+1] != NULL )
				printf(" ");
		}
		printf("\n");
		for ( i = 0; i < n; i++ )
		{
			for ( j = 0; s[j] != NULL; j++ )
			{
				if ( a[s[j]-'0'][1] == 1 )
					printf("|");
				else
					printf(" ");
				for ( k = 0; k < n; k++ )
					printf(" ");
				if ( a[s[j]-'0'][2] == 1 )
					printf("|");
				else
					printf(" ");
	//			if ( s[j+1] != NULL )
					printf(" ");
			}
			printf("\n");
		}
		for ( j = 0; s[j] != NULL; j++ )
		{
			printf(" ");
			if ( a[s[j]-'0'][3] == 1 )
			{
				for ( i = 0; i < n; i++ )
					printf("-");
			}
			else
			{
				for ( i = 0; i < n; i++ )
					printf(" ");
			}
			printf(" ");
	//		if ( s[j+1] != NULL )
				printf(" ");
		}
		printf("\n");
		for (i = 0; i < n; i++ )
		{
			for (  j = 0; s[j] != NULL; j++ )
			{
				if ( a[s[j]-'0'][4] == 1 )
					printf("|");
				else
					printf(" ");
				for ( k = 0; k < n; k++ )
					printf(" ");
				if ( a[s[j]-'0'][5] == 1 )
					printf("|");
				else
					printf(" ");
		//		if ( s[j+1] != NULL )
					printf(" ");
			}
			printf("\n");
		}
		for ( j = 0; s[j] != NULL; j++ )
		{
			printf(" ");
			if ( a[s[j]-'0'][6] == 1 )
			{
				for ( i = 0; i < n; i++ )
					printf("-");
			}
			else
			{
				for ( i = 0; i < n; i++ )
					printf(" ");
			}
			printf(" ");
		//	if ( s[j+1] != NULL )
				printf(" ");
		}
		printf("\n\n");
	}
	return 0;
}