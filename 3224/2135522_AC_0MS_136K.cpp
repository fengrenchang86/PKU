#include <iostream>
using namespace std;
int main ()
{
	int n;
	int a[120];
	int t;
	int i,j;;
	cin>>n;
	for ( i = 1; i <= n; i++ )
	{
		a[i]=0;
		for ( j = 1; j <= n; j++ )
		{
			scanf("%d",&t);
			if ( t == 3 )
				a[i] ++;
		}
	}
	t = 1;
	for ( i = 1; i <= n; i++ )
	{
		if ( a[i] > a[t] )
			t = i;
	}
	cout<<t<<endl;
	return 0;
}