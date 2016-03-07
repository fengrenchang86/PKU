#include <iostream.h>
int power ( int a, int b ) // a^b
{
	int sum = 1;
	for ( int i = 0; i < b; i++ )
		sum *= a;
	return sum;
}

int getsize ( char *a )
{
	int i = 0;
	while ( a[i] != NULL )
		i++;
	return i;
}

void main () 
{
	int n;
	int i;
	int k;
	while ( cin>>n )
	{
		for ( i = 1; i <= 31; i++ )
		{
			k = power ( 2, i );
			if ( k >= n )
				break;
		}
		if ( i%2 == 0 )
			cout<<"Stan wins."<<endl;
		else
			cout<<"Ollie wins."<<endl;
	}
}