#include <iostream>
using namespace std;

int main ()
{
	char a[10000001];
	int i;
	for ( i = 0; i < 10000001; i++ )
		a[i] = 48;
	a[1] = 49;
	int j;
	int n;
	for ( i = 1; i < 10000001/3; i++ )
	{
		if ( a[i] == 49 )
		{
			a[2*i+1] = 49;
			a[3*i+1] = 49;
		}
	}
	while ( cin>>n )
	{
		j = 0;
		for ( i = 1; j < n; i++ )
			if ( a[i] == 49 )
				j++;
		cout<<i-1<<endl;
	}
	return 1;
}