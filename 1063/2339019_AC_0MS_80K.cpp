#include <iostream>
using namespace std;
int main ()
{
	int n,i,a,b,c,tcase;
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase--;
		a = b = 0;
		scanf("%d",&n);
		for ( i = 0;i < n; i++ )
		{
			scanf("%d",&c);
			if ( c == 1 )
			{
				if ( i % 2 == 0 )
					a++;
				else
					b++;
			}
		}
		if ( n % 2== 1 )
			printf("YES\n");
		else
		{
			if ( abs(a-b) < 2 )
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}