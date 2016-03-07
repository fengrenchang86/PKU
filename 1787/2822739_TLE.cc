#include <iostream>
using namespace std;
int a,b,c,d;
int main ()
{
	bool go(int,int,int,int,int);
	int p,c1,c2,c3,c4;
	bool yes;
	while ( cin>>p>>c1>>c2>>c3>>c4 )
	{
		if (p+c1+c2+c3+c4==0 )
			break;
		yes = go(p,c1,c2,c3,c4);
		if ( yes == false )
		{
			printf("Charlie cannot buy coffee.\n");
			continue;
		}
		while ( c3-c >= 3 )
		{
			if ( b >= 1 && d >= 1 )
			{
				c=3;
				b++;
				d++;
			}
			else
				break;
		}
		printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n",a,b,c,d);
	}
	return 0;
}
bool go ( int p, int c1, int c2, int c3, int c4 )
{
	int i1,i2,i3,i4,t;
	if ( p > c1+c2*5+c3*10+c4*25 )
		return false;
	if ( c1 >= p )
	{
		a = p;
		b = c = d = 0;
		return true;
	}
	for ( i1 = c1; i1 >= 0; i1-- )
	{
		if ( (p-i1)% 5 != 0 )
			continue;
		if ( p-i1 > c2*5+c3*10+c4*25 )
			break;
		for ( i2 = c2; i2 >= 0; i2-- )
		{
			if ( p-i1-i2*5 < 0 )
				continue;
			else if ( p-i1-i2*5 == 0 )
			{
				a = i1;
				b = i2;
				c = d = 0;
				return true;
			}
			if ( p-i1-5*i2 > c3*10+c4*25 )
				break;
			for ( i3 = c3; i3 >= 0; i3-- )
			{
				t = p-i1-i2*5-i3*10;
				if ( t < 0 )
					continue;
				else if ( t == 0 )
				{
					a = i1;
					b = i2;
					c = i3;
					d = 0;
					return true;
				}
				if ( t%25 != 0 )
					continue;
				if ( t > 25*c4 )
					break;
				for ( i4 = c4; i4 >= 0; i4-- )
				{
					if ( t-i4*25 < 0 )
						continue ;
					else if ( t-i4*25==0 )
					{
						a = i1;
						b = i2;
						c = i3;
						d = i4;
						return true;
					}
					else
						break;
				}
			}
		}
	}
	return false;
}