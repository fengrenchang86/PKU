#include <iostream>
#include <math.h>
using namespace std;

int f ( int a, int b, int x1, int y1, int x2, int y2 )
{
	double k = (1.0*y2-1.0*y1)/(1.0*x2-1.0*x1);
	if ( b-y1 == k*(a-x1) )
		return 1;
	else
		return 0;
}

int main ()
{
	int n;
	int a[220][2];
	int i,j,k;
	cin>>n;
	for ( i =0; i < n; i++ )
		cin>>a[i][0]>>a[i][1];
	int max = 0;
	int sum;
	for ( i = 0; i < n-1; i++ )
	{
		for ( j = i+1; j < n; j++ )
		{
			sum = 0;
			if ( a[i][0] != a[j][0] )
			{
				for ( k = 0; k < n; k++ )
					sum += f(a[k][0],a[k][1],a[i][0],a[i][1],a[j][0],a[j][1]);
			}
			else
			{
				for ( k = 0; k < n; k++ )
				{
					if ( a[k][0] == a[i][0] )
						sum++;
				}
			}
			if ( sum > max )
				max = sum;
		}
	}
	cout<<max<<endl;
	return 0;
}