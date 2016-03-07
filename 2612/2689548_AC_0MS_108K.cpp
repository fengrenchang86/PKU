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
bool touch ()
{
	int i,j;
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < n; j++ )
			if ( a[i][j] == '*' && b[i][j] == 'x' )
				return true;
	}
	return false;
}
void print1 ( )
{
	int i,j;
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
}
void p ()
{
	int i,j;
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < n; j++ )
		{
			if ( a[i][j] == '*' )
				printf("*");
			else if ( b[i][j] == 'x' )
				printf("%d",f(i,j));
			else
				printf(".");
		}
		printf("\n");
	}
}
int main ()
{
	scanf("%d",&n);
	int i;
	for ( i = 0; i < n; i++ )
		scanf("%s",&a[i]);
	for ( i = 0; i < n; i++ )
		scanf("%s",&b[i]);
	if ( touch() == false )
		print1();
	else
		p();
	return 0;
}