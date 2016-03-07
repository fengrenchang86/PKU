#include <iostream>
#include <math.h>
using namespace std;
double pi = asin(1)*2;
struct ac
{
	double x,y;
}a[120];
int main ()
{
	int n,i;
	double r;
	double sum = 0.0;
	cin>>n>>r;
	for ( i = 0; i < n; i++ )
		scanf("%lf%lf",&a[i].x,&a[i].y);
	for ( i = 1; i < n; i++ )
	{
		sum += sqrt((a[i].x-a[i-1].x)*(a[i].x-a[i-1].x)+(a[i].y-a[i-1].y)*(a[i].y-a[i-1].y));
	}
	sum += sqrt((a[n-1].x-a[0].x)*(a[n-1].x-a[0].x)+(a[n-1].y-a[0].y)*(a[n-1].y-a[0].y));
	sum += 2.0*pi*r;
	printf("%.2lf\n",sum);
	return 0;
}