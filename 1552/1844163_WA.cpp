#include <iostream.h>
void main ()
{
	int a[16];
	int i;
	int j;
	int n;
	int c;
	bool exit;
	while ( exit == false )
	{
		c = 0;
		exit = false;
		for ( i = 0; ; i++ )
		{
			cin>>a[i];
			if ( a[i] == 0 )
				break;
			if ( a[i] == -1 )
			{
				exit =true;
				break;
			}
		}
		if ( exit == true )
			break;
		n = i;
		for ( i = 0; i < n; i++ )
		{
			for ( j = 0; j < n; j++ )
			{
				if ( a[i] / 2 == a[j] && a[i]%2 ==0 )
					c++;
			}
		}
		cout<<c<<endl;
	}
	
}