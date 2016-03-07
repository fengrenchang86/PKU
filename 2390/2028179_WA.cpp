#include <iostream>
using namespace std;
void main ()
{
	int r;
	_int64 m;
	int y;
	int i;
	scanf("%d%I64d%d",&r,&m,&y);
	for ( i = 0; i < y; i++ )
	{
		m = m * ( 100 + r ) / 100;
	}
	printf("%I64d\n",m);
}