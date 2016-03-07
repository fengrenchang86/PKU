#include <iostream>
#include <math.h>
_int64 f(_int64 n )
{
	_int64 i,low,high,mid;
	low = 1;
	high = n;
	while ( low < high )
	{
		mid = low + high;
		mid /= 2;
		if ( mid * mid < n )
			low = mid+1;
		else
			high = mid-1;
	}
	if ( low == high )
		return mid;
	else
		return -1;
}
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
			k = f(n-i*i);
			if ( k == -1 )
			{
				continue;
			}
			else
//			if ( k < i )
//				break;
//			if ( k*k + i*i == n )
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