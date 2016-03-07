#include <iostream.h>
void main ()
{
	int n;
	int i;
	int d;
	int d2;
	bool isd;
	int a[4];
	int ans;
	int j;
	cin>>n;
	for (j = 0 ; j< n ;j++)
	{
		cin>>a[0]>>a[1]>>a[2]>>a[3];
		d = a[1] - a[0];
		d2 = a[2] - a[1];
		if ( d == d2 )
		{
			d = a[3] - a[2];
			if ( d == d2 )
				isd =true;
			else 
				isd = false;
		}
		else
			isd = false;
		if ( isd == true )
		{
			ans = a[3] + d;
			for ( i = 0; i< 4;i++ )
				cout<<a[i]<<" ";
			cout<<ans<<endl;
		}
		else
		{
			for ( i = 0; i < 4; i++ )
				cout<<a[i]<<" ";
			cout<<a[3]*a[3]/a[2]<<endl;
		}
	}

}