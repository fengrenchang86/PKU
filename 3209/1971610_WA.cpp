#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	int i;
	unsigned _int64 n,k;
	bool find;
	char ch[30];
	int tcase,it;
	scanf("%d",&tcase);
	for ( it = 0; it < tcase; it++ )
	{
		scanf("%s",ch);
		n = _atoi64(ch);
		if ( ch[0] == '-' && ch[1] != '0' )
		{
			printf("NO\n");
			continue;
		}
		find = false;
		for ( i = 0; ; i++ )
		{
			k = sqrt(abs(n-i*i));
			if ( k < i )
				break;
			if ( k*k + i*i == n )
			{
//				_i64toa(k,ch,10);
//				printf("k=%s,i=%d\n",ch,i);
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