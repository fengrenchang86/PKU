#include <iostream>
using namespace std;
void main ()
{
	int c = 0;
	int count = 0;
	int i;
	int n;
	int k;
	int j;
	scanf("%d %d",&n,&k);
	int h;
	char *a = new char[k+1];
	for ( i = 0; i <= k; i++ )
		a[i] = -1;
	for ( i = 0; i < n; i++ )
	{
		scanf("%d",&h);
		if ( a[h] != count )
		{
			a[h] = count;
			c++;
		}
		if ( c == k )
		{
			count++;
			c = 0;
			for ( j = 0; j <= k; j++ )
				a[j] = -1;
		}
	}
		count++;
	cout<<count<<endl;
}