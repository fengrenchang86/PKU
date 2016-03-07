#include <iostream.h>
#include <iomanip.h>
void main ()
{
	int x1;
	int x2;
	int x3;
	int x4;
	int y1;
	int y2;
	int y3;
	int y4;
	double k1;
	double k2;
	double x;
	double y;
	int i;
	int n;
		
	cout<<"INTERSECTING LINES OUTPUT"<<endl;
	cin>>n;
	for ( i = 0; i < n; i++ )
	{
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
		if ( y2==y1 && y3==y4)
		{
			if ( y1 == y3 )
				cout<<"LINE"<<endl;
			else
				cout<<"NONE"<<endl;
		}
		else if ( x1==x2 || x3==x4 )
		{
			if ( x1 == x2 && x3 == x4 )
			{
				if ( x1 == x3 )
					cout<<"LINE"<<endl;
				else
					cout<<"NONE"<<endl;
			}
			else
			{
				if ( x1 == x2 )
				{
					k2 = (y4-y3)/(x4-x3);
					x = 1.0*x1;
					y = 1.0*k2 * x1 - 1.0*k2*x3 + 1.0*y3;
					cout<<"POINT "<<setiosflags(ios::fixed)<<setprecision(2)<<x<<" "<<y<<endl;
				}
				else
				{
					k1 = (y2-y1)/(x2-x1);
					x = 1.0*x3;
					y = 1.0*k1*x3-1.0*k1*x1 + 1.0*y1;
					cout<<"POINT "<<setiosflags(ios::fixed)<<setprecision(2)<<x<<" "<<y<<endl;
				}
			}
		}
		else if ( (y2-y1)*(x4-x3) == (y4-y3)*(x2-x1) )
		{
			if ( (y3-y1)*(x2-x1) == (x3-x1)*(y2-y1) )
				cout<<"LINE"<<endl;
			else
				cout<<"NONE"<<endl;
		}
		else
		{
			k1 = 1.0*(y2-y1)/(x2-x1);
			k2 = 1.0*(y4-y3)/(x4-x3);
			x = 1.0*(y3-y1+k1*x1-k2*x3)/(k1-k2);
			y = 1.0*y1 + 1.0*k1*x - 1.0*k1*x1;
			cout<<"POINT "<<setiosflags(ios::fixed)<<setprecision(2)<<x<<" "<<y<<endl;
		}
	}
cout<<"END OF OUTPUT"<<endl;
}