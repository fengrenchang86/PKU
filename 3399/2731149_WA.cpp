#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
int cmp1 ( const void*a, const void*b )
{
	return *(int*)a-*(int*)b;
}
int cmp2 ( const void*a, const void*b )
{
	return *(int*)b-*(int*)a;
}
int a[200],b[200];
int main ()
{
//	fstream cin("in.txt");
	int t,n,k,i=0,j=0,x=0,y,z;
	int b1,b2;
//	while ( cin>>n>>k )
	{
		cin>>n>>k;
		void output(int,int,int,int);
		x = y = z = 0;
		for ( t =0;t<n;t++ )
		{
			cin>>j;
			if ( j > 0 )
				a[x++] = j;
			else if ( j < 0 )
				b[y++] = j;
			else
				z++;
		}
		if ( x+y < k || x+y ==k && y%2==1)//the answer is zero
			output(x,y,z,k);
		else if ( z == 0 && y==n&&k%2==1 || n==k )
			output(x,y,z,k);
		else if ( x == 0 && k%2==1 )
			output(x,y,z,k);
		else
		{
			i = 0;
			qsort(a,x,sizeof(a[0]),cmp2);
			qsort(b,y,sizeof(b[0]),cmp1);
			b1 = b2 = 0;
			while ( i < k-1 )
			{
				if ( b1+2>x && b2+2<=y )
				{
					i+=2;
					b2+=2;
				}
				else if ( b1+2<=x && b2+2 > x )
				{
					i+=2;
					b1+=2;
				}
				else
				{
					if ( a[b1]*a[b1+1] > b[b2]*b[b2+1] )
						b1+=2;
					else
						b2+=2;
					i+=2;
				}
			}
			if ( i == k-1 )
			{
				if ( b1 < x )
					b1++;
				else
				{
					b1--;
					b2+=2;
				}
			}
			x = b1;
			y = b2;
			if ( y != 0 )
				qsort(b,y,sizeof(b[0]),cmp2);
			if ( x != 0 )
			{
				cout<<a[0];
				k--;
				for ( i = 1; i < x && k > 0; i++ )
				{
					cout<<" "<<a[i];
					k--;
				}
				for ( i = 0; i < y && k > 0; i++ )
				{
					cout<<" "<<b[i];
					k--;
				}
				cout<<endl;
			}
			else
			{
				cout<<b[0];
				k--;
				for ( i = 1; i < y && k > 0; i++ )
				{
					cout<<" "<<b[i];
					k--;
				}
				cout<<endl;
			}
		}
	}
	return 0;
}
void output ( int x, int y, int z, int k )
{
	int i;
	if ( x != 0 )
		qsort(a,x,sizeof(a[0]),cmp2);
	if ( y != 0 )
		qsort(b,y,sizeof(b[0]),cmp2);
	if ( x != 0 )
	{
		cout<<a[0];
		k--;
		for ( i = 1; i < x&& k > 0; i++ )
		{
			cout<<" "<<a[i];
			k--;
		}
		while ( z > 0 && k > 0 )
		{
			cout<<" 0";
			k--;
			z--;
		}
		for ( i = 0; i < y && k > 0; i++ )
		{
			cout<<" "<<b[i];
			k--;
		}
		cout<<endl;
	}
	else if ( z != 0 )
	{
		cout<<0;
		k--;
		z--;
		while ( k > 0 && z > 0 )
		{
			cout<<" 0";
			k--;
			z--;
		}
		for ( i = 0; i < y && k > 0; i++ )
		{
			cout<<" "<<b[i];
			k--;
		}
		cout<<endl;
	}
	else
	{
		cout<<b[0];
		k--;
		for ( i = 1; i < y && k > 0; i++ )
		{
			cout<<" "<<b[i];
			k--;
		}
		cout<<endl;
	}
}