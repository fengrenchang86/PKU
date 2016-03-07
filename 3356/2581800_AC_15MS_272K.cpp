#include <iostream>
using namespace std;
int max ( int a, int y )
{
	return a>y?a:y;
}
int main ()
{
	int len1,len2;
	char a[10000],b[10000];
	int i,j,c[2][10001];
	while ( cin>>len1>>a>>len2>>b)
	{
		for ( i = 0; i <= 10000; i++ )
			c[0][i] = 0;
		c[1][0] = 0;
		for ( i = 0; i < len1; i++ )
		{
			for ( j = 0; j < len2; j++ )
			{
				if ( a[i] == b[j] )
					c[(i+1)%2][j+1] = c[i%2][j]+1;
				else
					c[(i+1)%2][j+1] = max(c[(i+1)%2][j],c[i%2][j+1]);
			}
		}
		if ( len1-c[len1%2][len2]>len2-c[len1%2][len2] )
			cout<<len1-c[len1%2][len2]<<endl;
		else
			cout<<len2-c[len1%2][len2]<<endl;

	}
	return 0;
}

