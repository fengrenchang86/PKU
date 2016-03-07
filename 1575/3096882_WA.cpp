#include <iostream>
#include <string>
using namespace std;
int main ()
{
	char t[100];
	int i,a,b,c,x,y,z;
	while ( cin>>t )
	{
		if ( strcmp(t,"end")==0 )
			break;
		x = y = z = a = b = 0;
		c = 1;
		if ( t[0] == 'a' || t[0] == 'e' || t[0] == 'i' || t[0] == 'o' || t[0] == 'u' )
		{
			a = 1;
			c = 0;
		}
		else
			b = 1;
		for ( i = 1; t[i] != NULL; i++ )
		{
			if ( t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u' )
			{
				c = 0;
				a++;
				if ( a > 2 )
					x = 1;
				b = 0;
				if ( t[i] == t[i-1] )
					z = 1;
			}
			else
			{
				b++;
				a = 0;
				if ( b > 2 )
					y = 1;
			}
		}
		if ( x+y+z+c == 0 )
			printf("<%s> is acceptable.\n",t);
		else
			printf("<%s>  is not acceptable.\n",t);
	}
	return 0;
}