#include <iostream>
using namespace std;
int main ()
{
	int v[1002];
	int a,b,c;
	int i;
	int t;
	int count;
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
			printf("%d",a/b);
			t++;
			if ( t == 50 )
			{
				t = 0;
				printf("\n");
			}
		}
		printf("\n");
		if ( c != 0 )
			printf("The last %d digits repeat forever.\n",count-v[c]);
		else
			printf("This expansion terminates.\n");
	}
	return 0;
}