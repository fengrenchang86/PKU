#include <iostream>
using namespace std;
void main ()
{
	int r;
	double m;
	int y;
	int i;
	cin>>r>>m>>y;
	for ( i = 0; i < y; i++ )
	{
		m = m * ( 100 + r ) / 100;
	}
	cout<<int(m)<<endl;
//	printf("%.0lf\n",m);
}
