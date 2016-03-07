#include <iostream.h>
#include <math.h>
void main()
{
	int n;
	int i;
	int j;
	int sum;
	int d;
	while(cin>>n&&n!= 0 )
	{
		sum = 0;
		i = (sqrt(8*n+1)-1)/2;
		d = n - (i*i + i )/2;
		if ( d==0 )
		{
			for ( j = 1; j <= i; j++ )
				sum+=j*j;
			cout<<n<<" "<<sum<<endl;
		}
		else
		{
			for ( j = 1; j <=i; j++ )
				sum+=j*j;
			sum+= (d*(i+1));
			cout<<n<<" "<<sum<<endl;
		}
	}
}