#include <iostream>
using namespace std;
int main ()
{
	int n,s,i,j,k;
	int price[10100],num;
	__int64 sum = 0,min;
	scanf("%d%d",&n,&s);
	scanf("%d %d",&price[0],&num);
	sum += price[0]*num;
	for ( i = 1; i < n; i++ )
	{
		scanf("%d%d",&price[i],&num);
		min = 2000000000000000;
		for ( j = 0;; j++ )
		{
			if ( i-j<0 )
				break;
			if ( price[i-j]+s*j < min )
			{
				min = price[i-j]+s*j;
				k = j;
			}
		}
		sum += num*min;
	}
	printf("%I64d\n",sum);
	return 0;
}