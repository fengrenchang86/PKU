
#include <iostream>
using namespace std;
const MAX = 600;
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
	int c;
	//while ( scanf("%s %s",a1,a2) )
		scanf("%s %s",a1,a2);
	{
		int t[MAX][MAX] = {0};
		max = 0;
		for ( i = 0; a1[i] != NULL; i++ )
		{
			for ( j = 0; a2[j] != NULL; j++ )
			{
				if ( a1[i] == a2[j] )
				{
					t[i][j] = 1;
				}
			}
		}
		c = 0;
		s1 = i;
		s2 = j;
		k = 0;
		for ( i = 0; i < s1; i++ )
		{
			for ( j = k; j < s2; j++ )
				if ( t[i][j] == 1 )
				{
					c++;
					k = i+1;
					break;
				}
		}
		max = c;
		c =0;
		k = 0;
		for ( j = 0; j < s2; j++ )
		{
			for ( i = k; i < s1; i++ )
				if ( t[i][j] == 1 )
				{
					c++;
					k = j+1;
					break;
				}
		}
		max = max>c?max:c;
		cout<<max<<endl;
	}
	return 1;
}