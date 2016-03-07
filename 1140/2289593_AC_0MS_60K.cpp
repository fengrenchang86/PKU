#include <iostream>
using namespace std;
int main ()
{
	short v[1002];
	int a,b,c;
	short i;
	short t;
	short count;
	while ( scanf("%d%d",&a,&b) && !(a==0&&b==0) )
	{
		t = 2;
		for ( i = 0; i < 1002; i++ )
			v[i] = 0;
		count = 1;
		printf(".");
		v[a] = 1;
		a*=10;
		printf("%d",a/b);
		c = a%b;
		while ( c!=0 )
		{
			count++;
			if ( v[c] == 0 )
				v[c] = count;
			else
				break;
			a = c*10;
			c = a%b;
			if ( t == 50 )
			{
				printf("\n");
				t = 0;
			}
			printf("%d",a/b);
			t++;
		}
		printf("\n");
		if ( c != 0 )
			printf("The last %d digits repeat forever.\n",count-v[c]);
		else
			printf("This expansion terminates.\n");
	}
	return 0;
}