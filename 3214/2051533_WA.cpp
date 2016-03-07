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
		if ( t[i] <= t[i-1] )
		{
			if ( i%2==0 )
				t[i] += t[i-1];
			else
				t[i] ++;
			c++;
		}
	}
	for ( i = n-1 ; i >= 1; i-- )
	{
		a = v[i-1];
		b = v[i]-1;
		if ( t[a] < t[a*2+1] )
		{
			t[a] = 1+t[a*2+1];
			c++;
		}
		a++;
		for ( j = a; j <= b; j++ )
		{
			m = p =0;
			if ( t[j] < t[j-1] )
			{
				if ( a%2==0 )
					m = t[j] + t[j-1];
				else
					m = t[j]+1;
			}
			if ( t[j] < t[j*2+1] )
			{
				p= 1+t[j*2+1];
			}
			if ( m != 0 || p!=0 )
				c++;
			t[j] = 	m>p?m:p;
		}
	}
//	for ( i = 1; i <= v[n]-1;i++ )
//		cout<<t[i]<<" ";
//	cout<<endl;
	cout<<c<<endl;
	return 1;
}