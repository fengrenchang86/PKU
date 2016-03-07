#include <iostream>
#include <math.h>
using namespace std;
struct wf
{
	double x,y;
}w[210];
double lenth ( int i, int j )
{
	return sqrt((w[i].x-w[j].x)*(w[i].x-w[j].x)+(w[i].y-w[j].y)*(w[i].y-w[j].y));
}
double MIN ( double x, double y )
{
	return x<y?x:y;
}
double MAX ( double x, double y )
{
	return x>y?x:y;
}
int main ()
{
	int i,j,k,n,it=1;
	double *a = new double[210];
	double *b = new double[210];
	double min,ans;
	while ( scanf("%d",&n) && n!=0 )
	{
		ans = 0.0;
		for ( i = 0; i < n; i++ )
		{
			scanf("%lf %lf",&w[i].x,&w[i].y);
	//		w[i].x = rand()%1000;
	//		w[i].y = rand()%1000;
			w[i].x = double(w[i].x);
			w[i].y = double(w[i].y);
		}
		a[0] = 0.0;
		for ( i = 1; i < n; i++ )
			a[i] = lenth(0,i);
		for ( i = 1; i < n; i++ )
		{
			for ( j = 0; j < n; j++ )
				b[j] = a[j];
			for ( j = 0; j < n; j++ )
			{
				if ( b[j] >= b[1] )
					continue;
				for ( k = 0; k < n; k++ )
				{
					ans = MAX(b[j],lenth(j,k));
					if ( a[k] > ans )
						a[k] = ans;
				}
			}
		}
		printf("Scenario #%d\n",it);
		it++;
		printf("Frog Distance = %.3lf\n\n",a[1]);
	}
	return 0;
}