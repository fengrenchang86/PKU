#include <iostream.h>
#include <math.h>
#include <iomanip.h>
double a[101];
void sort ( int na )
{
	int i;
	int j;
	double t;
	for ( i = 0; i < na-1; i++ )
	{
		for ( j = i+1; j < na; j++)
		{
			if ( a[i] < a[j] )
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}
void main () 
{
	int n;
	int i;
	cin>>n;
	for ( i = 0; i < n; i++ )
		cin>>a[i];
	for ( i = 1; i < n; i++ )
	{
		sort ( n );
		a[0] = 2*sqrt(a[0]*a[1]);
		a[1] = -1;
	}
	cout<<setiosflags(ios::fixed)<<setprecision(3)<<a[0]<<endl;
}

