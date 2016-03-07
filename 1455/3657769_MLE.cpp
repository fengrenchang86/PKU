#include <iostream>
using namespace std;
int f ( int k )
{
	if ( k == 2 )
		return 1;
	else if ( k == 3 )
		return 3;
	else
		return f(k/2)+f(k-k/2);
}
int main ()
{
	int n,k;
	scanf("%d",&n);
	while ( n-- )
	{
		scanf("%d",&k);
		printf("%d\n",f(k));
	}
	return 0;
}