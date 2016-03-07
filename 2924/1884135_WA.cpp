#include <iostream>
#include <iomanip>
using namespace std;
int main ()
{
//	long double m,n;
	_int64 m,n,sum;
	char k1[20];
	char k2[20];
	int data;
	int i;
	int j;
	int n1;
	int n2;
//	long double sum;
	scanf("%d", &data);
	for ( i = 0; i < data; i++ )
	{
//		cin>>n>>m;
		scanf("%s %s",k1,k2);
		n = _atoi64(k1);
		m = _atoi64(k2);
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