#include <iostream>
using namespace std;
int main ()
{
	int gcd(int,int);
	int a[40000];
	int n,l,i,d,year;
	while ( cin>>n>>l )
	{
		year=0;
		for ( i = 0; i < n; i++ )
		{
			scanf("%d",&d);
			d %= l;
			d = l-d;
			a[i] = d-1;
		}
		d = i = 0;
		while ( i < n && a[i]==0 )
			i++;
		if ( i < n )
		{
			d = a[i];
			i++;
		}
		for ( ; i < n; i++ )
		{
			if ( a[i] == 0 )
				continue;
			year = gcd(d,a[i]);
			d = d*a[i]/year;
		}
		cout<<d<<endl;
	}
	return 0;
}
int gcd ( int a, int b )
{
	int r;
	while ( b != 0 )
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}