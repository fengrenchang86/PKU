#include <iostream.h>
void main ()
{
	int f ( int );
	int n;
	int i;
	int sum;
	while(cin>>n)
	{
	i = n;
	sum = 1;
	while ( i > 1 )
	{
		sum *= i;
		sum = f ( sum );
		i--;
	}
	cout<<sum - sum/10*10<<endl;
	}
}

int f ( int s )
{
	int a = s;
	while ( a == a/10*10)
		a = a/10;
	return a%10000;
}