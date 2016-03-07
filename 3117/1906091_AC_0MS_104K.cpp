#include <iostream>
using namespace std;
int main ()
{
	char name[20];
	int t,n;
	int i;
	int sum;
	while ( scanf("%d %d",&t,&n) && t!= 0 )
	{
		sum = 0;
		int *a = new int[t+1];
		for ( i = 0; i < t; i++ )
		{
			scanf("%s %d",name,&a[i]);
			sum += a[i];
		}
		sum = 3*n-sum;
		printf("%d\n",sum);
	}
	return 1;
}