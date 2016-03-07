#include <iostream>
#include <math.h>
using namespace std;
int v[25];
int f ( int x )
{
	int i = 0;
	while ( x > v[i] )
		i++;
	if ( x == v[i] )
		return 1;
	else
		return 0;
}

int main ()
{
	int n,m,p;
	int a,b;
	cin>>n;
	int c = 0;
	int *t = new int[pow(2,n)+1];
	int i,j;
	v[0] = 1;
	for ( i = 1; i < 22; i++ )
		v[i] = v[i-1]*2;
	for ( i = 1; i <= v[n]-1; i++ )
		scanf("%d",&t[i]);
	a = v[n-1]+1;
	b = v[n]-1;
	for ( i = a; i <= b; i++ )
	{
		if ( t[a] < t[a-1] )
		{
			if ( a%2==0 )
				t[a] += t[a-1];
			else
				t[a] ++;
			c++;
		}
	}
	for ( i = n-1 ; i >= 1; i-- )
	{
		a = v[i-1]-1;
		b = v[i]-1;
		if ( t[a] < t[a*2+1] )
		{
			t[a] = t[a*2]+t[a*2+1];
			c++;
		}
		for ( j = a; j <= b; j++ )
		{
			m = p =0;
			if ( t[a] < t[a-1] )
			{
				if ( a%2==0 )
					m = t[a] + t[a-1];
				else
					m = t[a]+1;
			}
			if ( t[a] < t[a*2+1] )
			{
				p= t[a*2]+t[a*2+1];
			}
			if ( m != 0 && p!=0 )
				c++;
			t[a] = 	m>p?m:p;
		}
	}
	cout<<c<<endl;
	return 1;
}