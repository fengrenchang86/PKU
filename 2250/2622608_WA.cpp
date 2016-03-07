#include <iostream>
#include <string>
using namespace std;
int c[110][110];
struct ac
{
	int x,y;
}path[110][110];
char a[110][32],b[110][32];
void print ( int x, int y )
{
	if ( c[x][y] == 0 )
	{
		if ( strcmp(a[x],b[y]) == 0 )
			printf("%s",a[x]);
		return;
	}
	print(path[x][y].x,path[x][y].y);
	if ( strcmp(a[x],b[y]) == 0 )
		printf(" %s",a[x]);
}
int main ()
{
	int len1=0,len2=0;
	int i,j;
	while ( scanf("%s",&a[len1]) != EOF )
	{
		len1++;
		while ( scanf("%s",&a[len1]) && a[len1][0] != '#' )
			len1++;
		len1--;
		while ( scanf("%s",&b[len2]) && b[len2][0] != '#' )
			len2++;
		len2--;
		for ( i = 0; i < len1; i++ )
		{
			c[i][0] = 0;
			path[i][0].x = i-1;
			path[i][0].y = 0;
		}
		for ( j = 0; j < len2; j++ )
		{
			path[0][j].x = 0;
			path[0][j].y = j-1;
			c[0][j] = 0;
		}
		path[0][0].x = 0;
		path[0][0].y = 0;
		for ( i = 0; i < len1; i++ )
		{
			for ( j = 0; j < len2; j++ )
			{
				if ( strcmp(a[i],b[j]) == 0 )
				{
					c[i+1][j+1] = c[i][j]+1;
					path[i+1][j+1].x = i;
					path[i+1][j+1].y = j;
				}
				else if ( c[i+1][j] > c[i][j+1] )
				{
					c[i+1][j+1] = c[i+1][j];
					path[i+1][j+1].x = i+1;
					path[i+1][j+1].y = j;
				}
				else
				{
					c[i+1][j+1] = c[i][j+1];
					path[i+1][j+1].x = i;
					path[i+1][j+1].y = j+1;
				}
			}
		}
		print(len1,len2);
		printf("\n");
//		cout<<c[len1][len2]<<endl;
	}
	return 0;
}