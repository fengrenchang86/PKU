#include <iostream>
using namespace std;
int main ()
{
	unsigned int a,i=1;
	_int64 min=999999;;
	cin>>a;
	for ( i = 1; i <= a; i++ )
	{
		if ( (a*a+1)%i==0 )
		{
			if ( i+2*a+(a*a+1)/i < min )
				min = i+2*a+(a*a+1)/i;
		}
	}
	printf("%I64d\n",min);
	return 0;
}