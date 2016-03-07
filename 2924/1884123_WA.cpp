#include <iostream>
#include <iomanip>
using namespace std;
int main ()
{
	long double m,n;
	int data;
	int i;
	int j;
	int n1;
	int n2;
	unsigned long double sum;
	scanf("%d", &data);
	for ( i = 0; i < data; i++ )
	{
		cin>>n>>m;
		sum = (m+n)*(m-n+1)/2;
		j = 0;
		n1 = sum/1000000000;
		n2 = sum - n1*1000000000;
		cout<<"Scenario #"<<i+1<<":"<<endl;
		if ( n1 != 0 )
			cout<<n1;
		cout<<n2<<endl<<endl;
	}
	return 1;
}