#include <iostream>
using namespace std;
int a,b,c,d,num;
int main ()
{
	bool go(int,int,int,int,int);
	int p,c1,c2,c3,c4,i,sum;
	int i1,i2,i3;
	while ( cin>>p>>c1>>c2>>c3>>c4 )
	{
		num = 0;
		for ( i = (p-c1-c2*5-c3*10)/25; i <= c4; i++ )
		{
			sum = p-i*25;
			i1 = i2 = i3 = 0;
			while ( sum > 0 && i3 < c3 )
			{
				sum-=10;
				i3++;
			}
			while ( sum > 0 && i2 < c2 )
			{
				sum -= 5;
				i2++;
			}
			if ( sum <= c1 )
			{
				i1 = sum;
				while ( i3 > 0 )
				{
					if ( c2-i2 >= 2 )
					{
						i3--;
						i2+=2;
					}
					else if ( c2-i2 >= 1 && c1-i1 >= 5 )
					{
						i3--;
						i2++;
						i1+=5;
					}
					else
						break;
				}
				while ( i2 > 0 )
				{
					if ( c1-i1 >= 5 )
					{
						i2--;
						i1+=5;
					}
					else
						break;
				}
				if ( i1+i2+i3+i > num )
				{
					num = i1+i2+i3+i;
					a = i1;
					b = i2;
					c = i3;
					d = i;
				}
			}
		}
		if ( num != 0 )
			printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n",a,b,c,d);
		else
			printf("Charlie cannot buy coffee.\n");
	}
	return 0;
}
