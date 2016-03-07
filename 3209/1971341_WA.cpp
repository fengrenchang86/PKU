#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	int i;
	double n,k;
	unsigned int m;
	bool find;
	char ch[30];
	int tcase,it;
	scanf("%d",&tcase);
	for ( it = 0; it < tcase; it++ )
	{
		cin>>n;
		if ( n < 0 )
		{
			printf("NO\n");
			continue;
		}
		find = false;
		for ( i = 0; i < 30000; i++ )
		{
			k = sqrt(n-i*i);
			if ( k < i )
				break;
			m = int(k);
			if ( m*m + i*i == n )
			{
				find = true;
				break;
			}
			if ( k < i )
				break;
		}
		if ( find == true )
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 1;
}