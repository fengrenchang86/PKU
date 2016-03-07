#include <iostream>
using namespace std;
int main ()
{
	short b[120];
	int n,q,m,data;
	int i,j;
	while ( scanf("%d%d",&n,&q) && !(n==0&&q==0) )
	{
		for ( i = 0; i < 120; i++ )
			b[i] = 0;
		for ( i = 0; i < n; i++ )
		{
			scanf("%d",&m);
			for ( j = 0; j < m; j++ )
			{
				scanf("%d",&data);
				b[data]++;
			}
		}
		for ( j = n; j >= q; j-- )
		{
			for ( i = 0; i < 100; i++ )
			{
				if ( b[i] == j )
					break;
			}
			if ( b[i] == j )
				break;
		}
		if ( i >= 100 )
			cout<<0<<endl;
		else
			cout<<i<<endl;
	}
	return 0;
}