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
	while (cin>>a1>>a2 )
	{
		int t[2][MAX] = {0};
		for ( i = 0; a1[i] != NULL; i++ )
			for ( j = 0; a2[j] != NULL; j++ )
			{
				if ( a1[i] == a2[j] )
					t[(i+1)%2][j+1] = t[i%2][j]+1;
				else
					t[(i+1)%2][j+1] = t[i%2][j+1]>t[(i+1)%2][j]?t[i%2][j+1]:t[(i+1)%2][j];
			}
		cout<<t[i%2][j]<<endl;
	}
	return 1;
}
