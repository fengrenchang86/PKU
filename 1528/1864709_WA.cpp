#include <iostream.h>
#include <iomanip.h>
void main ()
{
	int n;
	int i;
	int sum;
	cout<<"PERFECTION OUTPUT"<<endl;
	while ( cin>>n && n!=0 )
	{
		sum = 0;
		cout<<setw(5)<<n<<" ";
		for ( i = 2; i*i <= n; i++ )
		{
			if ( n%i == 0 )
			{
				sum += i;
				sum += (n/i);
				if ( i == n/i )
				{
					sum -= i;
					break;
				}
			}
		}
		sum ++;
		if ( sum == n )
			cout<<"PERFECT"<<endl;
		else if ( sum > n )
			cout<<"ABUNDANT"<<endl;
		else 
			cout<<"DEFICIENT"<<endl;
	}
	cout<<"END OF OUTPUT"<<endl;
}