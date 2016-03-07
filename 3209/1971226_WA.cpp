#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	_int64 a[30000];
	int i;
	_int64 n,k;
	bool find;
	char ch[30];
	for ( i = 0; i < 30000; i++ )
		a[i] = i*i;
	int tcase,it;
	scanf("%d",&tcase);
	for ( it = 0; it < tcase; it++ )
	{
		scanf("%s",ch);
		n = _atoi64(ch);
		find = false;
		for ( i = 0; i < 30000; i++ )
		{
			k = sqrt(n-a[i]);
			if ( k*k + a[i] == n )
			{
				find = true;
				break;
			}
		}
		if ( find == true )
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 1;
}