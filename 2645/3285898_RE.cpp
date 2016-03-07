#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	__int64 x,y,t;
	__int64 p,q;
	double k;
	bool flag;
	__int64 i,j;
	int sum,ansx,ansy;
	while ( scanf("%I64d%I64d",&p,&q)!=EOF )
	{
		if ( p == 0 && q == 0 )
			break;
		flag = false;
		sum = 10000000;
		for ( x = 2; x <= 50000; x++ )
		{
			j = (p-q)*x*x-(p-q)*x;
			i = 2*p*x-p;
			if ( i*i-4*p*j < 0 )
				continue;
			k = sqrt(double(i*i-4*p*j));
			t = int(k);
			if ( t*t != i*i-4*p*j )
				continue;
			if ( t-i >= 0 && (t-i)%(2*p) == 0 )
			{
				y = (t-i)/2/p;
				if ( flag == false )
				{
					flag = true;
					ansx = x;
					ansy = y;
				}
				else if ( x+y < ansx+ansy )
				{
					ansx = x;
					ansy = y;
				}
			}
			if ( -t-i >= 0 && (-t-i)%(2*p) == 0 )
			{
				y = (-t-i)/2/p;
				if ( flag == false )
				{
					flag = true;
					ansx = x;
					ansy = y;
				}
				else if ( x+y < ansx+ansy )
				{
					ansx = x;
					ansy = y;
				}
			}
		}
		if ( flag == false )
			cout<<"impossible"<<endl;
		else
			printf("%d %d\n",ansx,ansy);
	}
	return 0;
}