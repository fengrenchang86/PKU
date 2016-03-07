#include <iostream.h>
#include <math.h>
#include <iomanip.h>
const double PI = 3.1415926;
void main()
{
	double data[100][2];
	int n;
	int r;
	int i;
	double l1;
	double l2;
	double k;
	double l = 0.0;
	double rope = 0.0;
	cin>>n>>r;
	for ( i = 0; i < n; i++ )
		cin>>data[i][0]>>data[i][1];
	for ( i = 0; i < n; i++ )
	{		
		l1 = sqrt ( (data[(i+1)%n][0]-data[i%n][0])*(data[(i+1)%n][0]-data[i%n][0]) +  
			 (data[(i+1)%n][1]-data[i][1]) * (data[(i+1)%n][1]-data[i][1]) );
		l2 = sqrt ( (data[(i+2)%n][0]-data[i+1][0])*(data[(i+2)%n][0]-data[(i+1)%n][0]) +  
			 (data[(i+2)%n][1]-data[i%n][1]) * (data[(i+2)%n][1]-data[i%n][1]) );
		l += l1;
		k = (data[i%n][0] - data[(i+1)%n][0])*(data[(i+2)%n][0]-data[(i+1)%n][0] +
			 data[i%n][1] - data[(i+1)%n][1])*(data[(i+2)%n][1]-data[(i+1)%n][1]);
		k = k / (l1*l2);
		k = acos(k);
		k = r*k;
		rope += k;
	}
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<rope+l<<endl;
}