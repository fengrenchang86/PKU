#include <iostream>
using namespace std;
int main ()
{
	int n;
	int i;
	int num;
	cin>>n;
	for ( i = 0; i < n ;i++ )
	{
		cin>>num;
		cout<<i+1<<" ";
		cout<<num/25<<" QUARTER(S), ";
		num = num%25;
		cout<<num/10<<" DIME(S), ";
		num = num%10;
		cout<<num/5<<" NICKEL(S), ";
		num = num%5;
		cout<<num<<" PENNY(S)"<<endl;
	}
	return 1;
}