#include <iostream>
using namespace std;
char a[12][12];
char b[12][12];
int n;
int f ( int i, int j )
{
	int c=0;
	if ( i-1>=0 && a[i-1][j] == '*')
		c++;
	if ( i+1<n && a[i+1][j]=='*')
		c++;
	if ( j+1<n && a[i][j+1]=='*')
		c++;
	if ( j-1>=0 && a[i][j-1]=='*')
		c++;
	if ( i-1>=0&&j-1>=0&&a[i-1][j-1]=='*')
		c++;
	if ( i-1>=0&&j+1<n&&a[i-1][j+1]=='*')
		c++;
	if ( i+1<n&&j-1>=0&&a[i+1][j-1]=='*')
		c++;
	if (i+1<n&&j+1<n&&a[i+1][j+1]=='*')
		c++;
	return c;
}
int main ()
{
	scanf("%d",&n);
	int i,j;
	for ( i = 0; i < n; i++ )
		scanf("%s",&a[i]);
	for ( i = 0; i < n; i++ )
		scanf("%s",&b[i]);
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < n; j++ )
		{
			if ( b[i][j] == 'x' )
				printf("%d",f(i,j));
			else
				printf(".");
		}
		printf("\n");
	}
	return 0;
}