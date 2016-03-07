#include <iostream>
using namespace std;
int main ()
{
	int tcase,it;
	scanf("%d",&tcase);
	int n,i;
	int k;
	int m;
	for ( it = 0; it  < tcase; it++ )
	{
		scanf("%d",&n);
		m = n%18;
		k = n/18;
		if ( m == 0 )
			k--;
		if ( k != 0 )
			printf("%d",k);
		if ( m < 6 )
			printf("%d666",m);
		else if ( m < 9 )
			printf("666%d",m-5);
		else
			printf("%d666",m-8);
		printf("\n");
	}
	return 1;

}