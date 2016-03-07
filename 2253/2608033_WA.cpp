#include <iostream>
#include <math.h>
using namespace std;
struct wf
{
	double x,y;
	double len;
	bool visit;
}w[210];
double lenth ( int i, int j )
{
	return sqrt((w[i].x-w[j].x)*(w[i].x-w[j].x)+(w[i].y-w[j].y)*(w[i].y-w[j].y));
}
int main ()
{
	int i,j,k,n,it=1;;
	double min,ans;
	while ( scanf("%d",&n) && n!=0 )
	{
		ans = 2000000000.0;
		for ( i = 0; i < n; i++ )
		{
			scanf("%lf %lf",&w[i].x,&w[i].y);
			w[i].x = double(w[i].x);
			w[i].y = double(w[i].y);
			w[i].len = 2000000000.0;
			w[i].visit = false;
		}
		w[0].visit = true;
		for ( i = 1; i < n; i++ )
			w[i].len = lenth(i,0);
		for ( i = 0; i < n-1; i++ )
		{
			min = 2000000000.0;
			for ( j = 1; j < n; j++ )
			{
				if ( w[j].len < min && w[j].visit == false )
				{
					k = j;
					min = w[j].len;
				}
			}
			if ( min < ans )
				ans = min;
			w[k].visit = true;
			if ( k == 1 )
				break;
			for ( j = 1; j < n; j++ )
			{
				min = lenth(j,k);
				if ( w[j].visit == false && w[j].len > w[k].len+min )
					w[j].len = w[k].len+min;
			}
		}
		printf("Scenario #%d\n",it);
		it++;
		printf("Frog Distance = %.3lf\n\n",ans);
	}
	return 0;
}