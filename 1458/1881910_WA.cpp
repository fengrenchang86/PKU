
#include <iostream>
using namespace std;
const MAX = 600;
int maxd ( int a, int b, int c )
{
	int m = a>b?a:b;
	return (m>c?m:c);
}
int main ()
{
	char a1[MAX];
	char a2[MAX];
	int i;
	int j;
	int k =0;
	int s1;
	int s2;
	
	int max;
//	while ( scanf("%s %s",a1,a2) )
		cin>>a1>>a2;
	{
		int t[MAX][MAX] = {0};
		max = 0;
		for ( j = 0; a2[j] != NULL; j++ )
			if ( a1[0] == a2[j] )
				break;
			else
				t[0][j] = 0;
		while ( a2[j] != NULL )
			t[0][j++] = 1;
		for ( i = 0; a1[i] != NULL; i++ )
			if ( a2[0] != a1[i] )
				t[i][0] = 0;
			else
				break;
		while ( a1[i] != NULL )
			t[i++][0] = 1;
		for ( i = 1; a1[i] != NULL; i++ )
		{
			for ( j = 1; a2[j] != NULL; j++ )
			{
				if ( a1[i] == a2[j] )
				{
					t[i][j] = maxd( t[i-1][j-1]+1,t[i][j-1],t[i-1][j] );
				}
				else
					t[i][j] = maxd ( t[i-1][j-1],t[i][j-1],t[i-1][j] );
			}
		}
		max = 0;
		s1 = i;
		s2 = j;
		for ( j = 0; j < s2; j++ )
		{
			if ( max < t[s1-1][j] )
				max = t[s1-1][j];
		}
		cout<<max<<endl;
	}
	return 1;
}