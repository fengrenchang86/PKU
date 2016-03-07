#include <iostream>
using namespace std;
int main ()
{
	int size;
	int i;
	int j;
	int k;
	int max;
	int c;
	while( scanf("%d",&size)!=EOF )
	{
		max = 0;
		char *a = new char[size+1];
		char **t;
		t = new char*[size];
		for ( i = 0; i < size + 1; i++ )
			t[i] = new char[size];
		scanf ( "%s", a );
		for ( i = 0; i < size; i++ )
		{
			for ( j = size-1; j>=0; j-- )
			{
				if ( a[i] == a[j] )
					t[i][j] = '1';
			}
		}
		c = 0;
		for ( k = 0; k < size; k++ )
		{
			for ( i = k, j = size-1; i < size; i++,j-- )
			{
				if ( t[i][j] == '1' )
					c++;
			}
			if ( c > max )
				max = c;
			c = 0;
		}
		printf("%d\n",size-max);
	}
	return 1;
}