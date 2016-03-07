#include <iostream.h>
#include <math.h>

int prime[1500];
int a[1500];

void makeprime()
{
	prime[0] = 2;
	prime[1] = 3;
	int i;
	int j;
	int c = 2;
	for ( i = 3; c < 1500; i++ )
	{
		for ( j = 2; j <= sqrt(i)+1; j++ )
		{
			if ( i%j == 0 )
				break;
		}
		if ( i%j != 0 )
			prime[c++] = i;
	}
}
void main ()
{
	int n = 0;
	makeprime();
	int i = 4;
	int j = 3;
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	int c = 3;
	int flag = 0;
	while ( cin>>n && n != 0 )
	{
		while ( c < n )
		{
			flag = 0;
			for ( j = 3; i >= prime[j]; j++ )
			{
				if ( i%prime[j] == 0 )
				{
					flag = 1;
					break;
				}
			}
			if ( flag == 0 )
				a[c++] = i;
			i++;
		}
			cout<<a[n-1]<<endl;
	}
}