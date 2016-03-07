#include <iostream>
using namespace std;
int main ()
{
	char a[120];
	char b[120];
	short c[120][120] = { 0 };
	scanf("%s %s",a,b);
	int i,j;
	int len1 = strlen(a);
	int len2 = strlen(b);
	int max = 0;
	for( i = 0; i < len1; i++ )
	{
		for ( j = 0; j < len2; j++ )
		{
			if ( a[i]-'0'+b[j]-'0' <= 3 )
				c[i+1][j+1] = c[i][j] + 1;
			else
				c[i+1][j+1] = 0;
			if ( c[i+1][j+1] == len1 )
			{
				printf("%d\n",len2);
				return 1;
			}
			if ( c[i+1][j+1] == len2 )
			{
				printf("%d\n",len1);
				return 1;
			}
		}
	}
	for ( i = 1; i <= len1; i++ )
	{
		if ( c[i][len2] == i && c[i][len2]>max )
			max = c[i][len2];
	}
	for ( j = 1; j <= len2; j++ )
	{
		if( c[len1][j] == j && c[len1][j] > max )
			max = c[len1][j];
	}
	printf("%d\n",len1+len2-max);
	return 1;
}