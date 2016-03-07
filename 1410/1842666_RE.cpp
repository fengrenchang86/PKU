#include <iostream.h>
void main ()
{
	double x1;
	double y1;
	double x2;
	double y2;
	int bx;
	int by;
	int ex;
	int ey;
	int pbx;
	int pby;
	int pex;
	int pey;
	double x[2];
	double y[2];
	int n;
	int i;
	double k;
	while ( cin>>n && n != 0 )
	{
	
	for ( i = 0; i < n; i++ )
	{
		cin>>pbx>>pby>>pex>>pey>>bx>>by>>ex>>ey;
		x1 = bx;
		y1 = by;
		x2 = ex;
		y2 = ey;
		k = (pey-pby)/(pex-pbx);
		y[0] = k*x1 - pbx*k + pby;
		y[1] = k*x2 - pbx*k + pby;
		x[0] = (y1-pby)/k + pbx;
		x[1] = (y2-pby)/k + pbx;
		if ( y[0] >= y1 && y[0] <= y2 && y[1] >= y1 && y[1] <= y2
			&& x[0] >= x1 && x[0] <= x2 && x[1] >= x1 && x[1] <= x2 )
			cout<<'T'<<endl;
		else 
			cout<<'F'<<endl;
	}
	}
}