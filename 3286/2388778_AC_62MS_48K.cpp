#include <iostream>
using namespace std;
int zero ( _int64 n )
{
	int k = 0;
	while ( n != 0 )
	{
		if ( n%10 == 0 )
			k++;
		n/=10;
	}
	return k;
}
_int64 f ( _int64 n )
{
	_int64 sum = 0;
	_int64 i,w,t,num = n;
	w = 1;
	while ( num >= 10 )
	{
		if ( num % 10 == 0 )
			t = n%w;
		else
			t = w-1;
		sum += (n/10/w*w+t-w+1);
		w *= 10;
		num /= 10;
	}
	return sum;
}
int main ()
{
	_int64 a,b,c;
	while ( scanf("%I64d%I64d",&a,&b) )
	{
		if ( a == -1 && b == -1 )
			break;
		c = f(b)-f(a)+zero(a);
		if ( a == 0 )
			c++;
		printf("%I64d\n",c);
	}
	return 0;
}