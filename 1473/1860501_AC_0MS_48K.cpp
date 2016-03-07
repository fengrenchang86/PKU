#include <iostream.h>
#include <iomanip.h>
#include <math.h>
void main ()
{
	char input[250];
	double x;
	double y;
	double s;
	int n;
	int i;
	int c = 1;
	while ( cin.getline(input,210,'\n') && input[0] != 'E' )
	{
		cout<<"Map #"<<c<<endl;
		c++;
		n = 0;
		x = 0.0;
		y = 0.0;
		for ( i = 0; input[i] != '.'; i++ )
		{
			n = 0;
			while ( ( input[i] < '0' || input[i] > '9' ) && input[i] != '.' )
				i++;
			if ( input[i] == '.' )
				break;
			while ( input[i] >= '0' && input[i] <= '9' )
			{
				n *= 10;
				n += ( input[i] - '0' );
				i++;
			}
			if ( input[i] == 'N' )
			{
				if ( input[i+1] == 'W' )
				{
					x -= n/sqrt(2);
					y += n/sqrt(2);
				}
				else if ( input[i+1] == 'E' )
				{
					x += n/sqrt(2);
					y += n/sqrt(2);
				}
				else
					y += n;
			}
			else if ( input[i] == 'S' )
			{
				if ( input[i+1] == 'W' )
				{
					x -= n/sqrt(2);
					y -= n/sqrt(2);
				}
				else if ( input[i+1] == 'E' )
				{
					x += n/sqrt(2);
					y -= n/sqrt(2);
				}
				else
					y -= n;
			}
			else if ( input[i] == 'W' )
				x -= n;
			else
				x += n;
		}
		s = sqrt(x*x+y*y);
		i = s*10000;
//		if ( i - i/10*10 >= 5 )
//			s += 0.001;
		cout<<"The treasure is located at (";
		cout<<setiosflags(ios::fixed)<<setprecision(3)<<x<<","<<y<<")."<<endl;
		cout<<"The distance to the treasure is "<<s<<'.'<<endl;
		cout<<endl;
	}
}