#include <iostream>
using namespace std;
int main ()
{
	int n,l,i,d,year;
	while ( cin>>n>>l )
	{
		year=0;
		for ( i = 0; i < n; i++ )
		{
			scanf("%d",&d);
			d %= l;
			if ( d == 0 )
				continue;
			d = l-d;
			if (d > year )
				year = d;
		}
		cout<<year<<endl;
	}
	return 0;
}
