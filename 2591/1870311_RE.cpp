#include <iostream>
using namespace std;

int main ()
{
	bool a[10000001];
	int i;
	for ( i = 0; i < 10000001; i++ )
		a[i] = 0;
	a[1] = 0;
	int j;
	int n;
	for ( i = 1; i < 10000001/3; i++ )
	{
		if ( a[i] == 1 )
		{
			a[2*i+1] = 1;
			a[3*i+1] = 1;
		}
	}
	while ( cin>>n )
	{
		j = 0;
		for ( i = 1; j < n; i++ )
			if ( a[i] == 1 )
				j++;
		cout<<i-1<<endl;
	}
	return 1;
}