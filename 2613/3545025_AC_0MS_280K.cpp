#include <iostream>
using namespace std;
int main ()
{
	int a,b,c,d,i,j;
	double ans;
	while ( cin>>a>>b>>c>>d )
	{
		if ( a-b < b )
			b=a-b;
		if ( c-d < d )
			d=c-d;
		i = a-b+1;
		j = c-d+1;
		ans = 1.0;
		while ( i <= a || j <= c || b > 1 || d > 1 )
		{
			if ( i <= a && ans * double(i) < 21474836480000000.0 )
			{
				ans *= double(i);
				i++;
			}
			else if ( d > 1 && ans*double(d) < 21474836480000000.0 )
			{
				ans *= double(d);
				d--;
			}
			else if ( b > 1 )
			{
				ans /= double(b);
				b--;
			}
			else if ( j <= c )
			{
				ans /= double(j);
				j++;
			}
		}
		printf("%.5lf\n",ans);
	}
	return 0;
}