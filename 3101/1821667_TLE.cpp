#include <iostream.h>
void main ( )
{
	
	int n;
	cin>>n;
	int *t = new int[n];
	int i;
	int max = 0;
	for ( i = 0; i < n; i++ )
	{
		cin>>t[i];
		if ( t[i] > max )
			max = t[i];
	}
	int count = max;
	while ( 1 )
	{
		for ( i = 0; i < n; i++ )
		{
			if ( count % t[i] != 0 )
				break;
		}
		if ( i == n && count % t[i-1] == 0 )
			break;
		else
		{
			count++;
		}
	}
	if ( count % 2 == 0 )
		cout<<count/2<<" "<<1<<endl;
	else
		cout<<count<<" "<<2<<endl;

}