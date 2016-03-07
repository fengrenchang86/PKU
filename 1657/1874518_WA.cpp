#include <iostream>
using namespace std;
int main ()
{
	int tcase;
	cin>>tcase;
	char a[10],b[10];
	int i;
	int j;
	int n1;
	int n2;
	int k[4];
	for ( i = 0; i < tcase; i++ )
	{
		cin>>a>>b;
		n1 = a[0] - b[0];
		n2 = a[1] - b[1];
		if ( n1 < 0 )
			n1 *= -1;
		if ( n2 < 0 )
			n2 *= -1;
		k[0] = n1>n2?n1:n2;
		if ( n1 == n2 || n1==0 || n2== 0 )
			k[1] = 1;
		else 
			k[1] = 2;
		if ( n1 == 0 || n2 == 0 )
			k[2] = 1;
		else
			k[2] = 2;
		if ( n1 == n2 )
			k[3] = 1;
		else if ( (n1+n2)%2 != 0 )
			k[3] = -1;
		else 
			k[3] = 2;
		if ( a[0] == b[0] && a[1] == b[1] )
		{
			for ( j = 0; j < 3; j++ )
				k[j] = 0;
		}
		for ( j = 0; j < 3; j++ )
			cout<<k[j]<<" ";
		if ( k[3] == -1 )
			cout<<"Inf"<<endl;
		else
			cout<<k[3]<<endl;
	}
	return 1;
}