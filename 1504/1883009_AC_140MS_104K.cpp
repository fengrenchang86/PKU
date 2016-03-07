#include <iostream>
using namespace std;
int main ()
{
	int data;
	int h;
	int n1;
	int n2;
	int k;
	int i;
	int sum;
	int num1;
	int num2;
	cin>>data;
	for ( h = 0; h < data; h++ )
	{
		cin>>n1>>n2;
		k = n1;
		num1 = 0;
		while ( k != 0 )
		{
			num1*=10;
			num1+=k%10;
			k/=10;
		}
		k = n2;
		num2 = 0;
		while ( k != 0 )
		{
			num2 *= 10;
			num2+=k%10;
			k/=10;
		}
		sum = num1+num2;
		k = sum;
		while ( k%10==0)
			k/=10;
		if ( k == 0 )
			cout<<0;
		while ( k > 0 )
		{
			cout<<k%10;
			k/=10;
		}
		cout<<endl;
	}
	return 1;
}