#include <iostream>
using namespace std; 
int main ()
{
	int a[20];
	int b[2] = {9,2};
	a[0] = 9;
	int i;
	for ( i = 1; i <= 10; i++ )
		a[i] = a[i-1]*b[i%2];
	int d;
	while ( cin>> d )
	{
		for ( i = 0; i <= 10; i++ )
			if ( a[i] >= d )
				break;
		if ( i > 10 )
			printf("Stan wins.\n");
		else
		{
			if ( i % 2== 0 )
				printf("Stan wins.\n");
			else
				printf("Ollie wins.\n");
		}
	}
	return 0;
}