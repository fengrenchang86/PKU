#include <iostream>
#include <fstream>
using namespace std;
int main ()
{
//	freopen("in.txt","r",stdin);
	int v[10101];
	int a[150];
	int b[150];
	int *c;
	int n,k,l;
	int i,j=0;
	int x;
	scanf("%d %d",&n,&k);
	for ( i = 0; i <= k; i++ )
	{
		a[i] = 0;
		b[i] = 0;
	}
	for ( i = 0; i < n; i++ )
	{
		scanf("%d",&x);
		if ( x < 0 )
			x *= -1;
		x %= k;
		if ( x != 0 )
			v[j++] = x;
	}
	if ( j == 0 )
	{
		cout<<"Divisible"<<endl;
		return 0;
	}
	a[v[0]] = 1;  
	for ( i = 1; i < j; i++ )
	{
		for ( l = 0; l < k; l++ )
		{
			if ( a[l] != 0 )
			{
				if ( b[l] == 1 )
					b[l] = 0;
				x = l - v[i];
				if ( x < 0 )
				{
					x += k;
					x %= k;
					b[x] = 2;
				}
				else
				{
					x %= k;
					b[x] = 2;
				}
				x = l + v[i];
				if ( x >= k )
					x %= k;
				b[x] = 2;
			}
		}
		for ( l = 0; l < k; l++ )
		{
			if ( b[l] != 0 )
				a[l] = 1;
			else
				a[l] = 0;
		}
	}
	if ( a[0] == 1 )
		cout<<"Divisible"<<endl;
	else
		cout<<"Not divisible"<<endl;
	return 0;
}