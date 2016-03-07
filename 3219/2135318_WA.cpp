#include <iostream>
using namespace std;
int main ()
{
	int n,k;
	while ( scanf("%d%d",&n,&k) != EOF )
	{
		k = k < n-k ? k:n-k;
		if ( k == 1 && n%2==1 || k == 0 )
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}