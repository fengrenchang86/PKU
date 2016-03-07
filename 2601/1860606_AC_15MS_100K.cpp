#include <iostream.h>
#include <iomanip.h>
void main ()
{
	int n;
	double begin;
	double end;
	double sum;
	double ans;
	int i;
	cin>>n>>begin>>end;
	double *c = new double[n];
	double *sumc = new double[n];
	sum = 0.0;
	for ( i = 0; i < n; i++ )
		sumc[i] = 0.0;
	for ( i = 0 ; i < n ;i++ )
	{
		cin>>c[i];
		if ( i == 0 )
			sumc[i] = c[i];
		else
			sumc[i] = sumc[i-1]+c[i];
		sum += sumc[i];
	}
	ans = ( n*begin + end - 2*sum ) / (n+1);
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<ans<<endl;
}