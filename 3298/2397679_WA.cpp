#include <iostream>
using namespace std;
int main ()
{
	int tcase;
	int n,i,d,pre,maxlen,currentlen,dir;
	cin>>tcase;
	while ( tcase )
	{
		scanf("%d",&n);
		pre = -10000;
		maxlen = 1;
		currentlen = 1;
		dir = 0;
		for ( i = 0; i < n; i++ )
		{
			scanf("%d",&d);
			if ( dir == 0 && d < pre )
			{
				currentlen++;
				dir = 1;
			}
			else if ( dir == 1 && d > pre )
			{
				currentlen++;
				dir = 0;
			}
			else
			{
				if ( currentlen > maxlen )
					maxlen = currentlen;
				currentlen = 1;
				dir = 0;
			}
			pre = d;
		}
		if ( currentlen > maxlen )
			maxlen = currentlen;
		cout<<maxlen<<endl;
		tcase--;
	}
	return 0;
}