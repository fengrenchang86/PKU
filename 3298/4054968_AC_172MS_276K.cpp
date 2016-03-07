#include <iostream>
using namespace std;
int main ()
{
	int tcase;
	scanf("%d",&tcase);
	int i,n,d,len,pre;
	while ( tcase )
	{
		scanf("%d",&n);
		len = 0;
		pre = -1;
		for ( i = 0; i < n; i++ )
		{
			scanf("%d",&d);
			if ( d < pre && len%2 == 0 )
				len++;
			else if ( d > pre && len%2 == 1 )
				len++;
			pre = d;
		}
		if ( d < pre && len%2==1 )
			len++;
		else if ( d > pre && len % 2 == 0 )
			len++;
		cout<<len+1<<endl;
		tcase--;
	}
	return 0;
}
