#include <iostream.h>
#include <iomanip.h>
#include <math.h>
void main ( )
{
	int m;
	int n;
	double A[500][3];
	double B[50][4];
	int i = 0; 
	int j = 0;
	double d = 0.0;
	double D = 0.0;
	while (1)
	{
	cin>>m;
	if ( m ==0 )
		break;
	for ( i = 0; i < m; i++ )
	{
		cin>>A[i][0]>>A[i][1]>>A[i][2];
	}
	cin>>n;
	for ( i = 0; i < n; i++ )
	{
		cin>>B[i][0]>>B[i][1]>>B[i][2]>>B[i][3];
	}
	int *see = new int[m];
	for ( i = 0; i < m; i++ )
		see[i] = 0;
	for ( i = 0; i < m; i++ )
	{
		if ( see[i] == 1 )
			continue;
		for ( j = 0; j < n; j++ )
		{
			D = ( A[i][0] * B[j][0] + A[i][1] * B[j][1] + A[i][2] * B[j][2] );
			if ( D < 0.0 )
				D *= -1.0;
			d = D / sqrt ( B[j][0] * B[j][0] + B[j][1] * B[j][1] + B[j][2] * B[j][2] );
			d = d / sqrt ( A[i][0] * A[i][0] + A[i][1] * A[i][1] + A[i][2] * A[i][2] );
			d = acos (d);
			D = cos(B[j][3]);
			cout<<"d= "<<d<<endl;
			cout<<"D= "<<D<<endl;
			if ( B[j][3] - d > 0.00000001 )
			{
				see[i] = 1;
				break;
			}
		}
	}
	j = 0;
	for ( i = 0; i < m; i++ )
	{
		j += see[i];
	}
	delete[m] see;
	cout<<j<<endl;
	}
}