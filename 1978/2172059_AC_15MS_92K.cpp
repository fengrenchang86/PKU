#include <iostream>
using namespace std;
int main ()
{
	int *a = new int[60];
	int *temp = new int[60];
	int *g;
	int i,j,k;
	int n,r,p,c;
	int count;
	while ( cin>>n>>r && !(n==0&&r==0))
	{
		for ( i = 0; i <= n; i++ )
			a[i] = i;
		for ( j = 0; j < r; j++ )
		{
			cin>>p>>c;
			count = 0;
			i = n;
			while ( count < c )
			{
				temp[i] = a[n+1-p-count];
				i--;
				count++;
			}
			k = n;
			while ( k > n+1-p )
			{
				temp[i] = a[k];
				i--;
				k--;
			}
			k = n+1-p-c;
			while ( k > 0 )
			{
				temp[i] = a[k];
				i--;
				k--;
			}
			g = temp;
			temp = a;
			a = g;
		}
		cout<<a[n]<<endl;
	}
	return 0;
}