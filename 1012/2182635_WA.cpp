#include <iostream>
using namespace std;
int main ()
{
	int a[] = {0,2,7,5,30,169,441,1872,7632,1740,93313,455901,1358657,2504881,13482720};
	int n;
	while ( scanf("%d",&n) && n!=0 )
	{
		printf("%d\n",a[n]);
	}
	return 0;
}