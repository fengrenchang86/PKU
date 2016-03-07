#include <iostream>
using namespace std;
int main ()
{
	int n,i,x,y;
	double min,t;
	while ( cin>>n && n != 0)
	{
		min = 200000000000.0;
		for ( i = 0; i < n; i++ )
		{
			scanf("%d%d",&x,&y);
			if ( y < 0 )
				continue;
			t = double(450.0*36.0/double(x))+double(y);
			if ( t < min )
				min = t;
			x = int(min);
			if ( min-x != 0 )
				x++;
		}
		cout<<x<<endl;
	}
	return 0;
}