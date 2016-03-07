#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	int i;
	_int64 n,k;
	bool find;
	char ch[30];
	int tcase,it;
	scanf("%d",&tcase);
	for ( it = 0; it < tcase; it++ )
	{
		scanf("%s",ch);
		n = _atoi64(ch);
		if ( n < 0 )
		{
			printf("NO\n");
			continue;
		}
		find = false;
		for ( i = 0; i < 30000; i++ )
		{
			k = sqrt(n-i*i);
			if ( k*k + i*i == n )
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