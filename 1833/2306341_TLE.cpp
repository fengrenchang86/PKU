#include <iostream>
#include <fstream>
using namespace std;
int main ()
{
//	fstream cin("in.txt");
	int tcase;
	int n,k;
	int i,j,c,t;
	int v[1030];
	int a[1030];
	cin>>tcase;
	while ( tcase )
	{
		tcase--;
		cin>>n>>k;
		for ( i = 1; i <= n; i++ )
			cin>>v[i];
		for ( i = 0; i < k; i++ )
		{
			for ( j = n; j >= 2; j-- )
			{
				a[j] = v[j];
				if ( v[j-1] < v[j] )
					break;
			}
			if ( j == 1 )
			{
				for ( i = 1; i <= n; i++ )
					v[i] = i;
			}
			else
			{
				c = j;
				a[0] = v[j-1];
				while ( v[j] > a[0] && j <= n)
					j++;
				j--;
				t = a[j];
				a[j] = v[c-1];
				v[c-1] = t;
				j = n;
				while ( c <= n )
				{
					v[c] = a[j];
					c++;
					j--;
				}
			}
		}
		for ( i = 1; i < n; i++ )
			cout<<v[i]<<" ";
		cout<<v[n]<<endl;
	}
	return 0;
}