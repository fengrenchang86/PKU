#include <iostream.h>
int power ( int a, int b )
{	
	int i;
	int sum = 1;
	for ( i = 0; i < b; i++)
		sum *= a;
	return sum;
}
void main ()
{
	int n;
	int i;
	int j;
	int k;
	bool exit = false;
	while ( cin>>n && n != 0 )
	{
		exit =false;
		for ( i = 2; exit == false ;i++ )
		{
			for ( j = 1; exit == false ; j++ )
			{
				k = power ( i, j );
				if ( k > n )
					break;
				if ( k == n )
					exit = true;
			}
		}
		cout<<j-1 <<endl;
					
	}
}