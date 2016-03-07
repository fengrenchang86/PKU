#include <iostream.h>
void main ()
{
	int n;
	int i;
	int sum;
	while ( 1 )
	{
		sum = 0;
		cin>>n;
		if ( n == -1 )
			break;
		int *speed = new int[n];
		int *hour = new int[n];
		for ( i = 0; i < n; i++ )
			cin>>speed[i]>>hour[i];
		sum = speed[0] * hour[0];
		for ( i = 1 ; i < n; i++ )
			sum = sum + speed[i] * ( hour[i] - hour[i-1] );
		cout<<sum<<" miles"<<endl;
	}
}