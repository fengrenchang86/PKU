#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
/*
int main ()
{
	_int64 h,m,n;
	_int64 i;
	char d[100];
	int c = 0;
	for ( i = 6; c < 10; i++ )
	{
		h = sqrt((i*i+i)/2);
		h = int(h);
		if ( 2*h * h == i*i+i )
		{
		//	_i64toa(h,d);
			_i64toa(h,d,10);
			printf("%s\n",d);
			_i64toa(i,d,10);
			printf("%s\n\n",d);
			c++;
		}
	}
	return 1;
}
*/
int main ()
{
	int a[20] = {6,8,35,49,204,288,1189,1681,6930,9800,40391,57121,235416,332928,
		1372105,1940449,7997214,11309768,46611179,65918161};
	int i;
	for ( i = 0; i < 20; i+=2 )
	{
		cout<<setw(10)<<a[i]<<setw(10)<<a[i+1]<<endl;
	}
	return 1;
}