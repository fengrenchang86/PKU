#include <iostream>
using namespace std;
int main ()
{
	int n,k,i;
	int begin,end,mid;
	int a[100100];
	_int64 sum = 0;
	double t;
	scanf("%d%d",&n,&k);
	for ( i = 0; i < n; i++ )
	{
		scanf("%lf",&t);
		a[i] = int(t*10000);
		sum += a[i];
	}
	begin = 0;
	int c;
	end = sum/k;
	while( end-begin > 0 )
	{
		mid = (end+begin)/2;
		c = 0;
		for ( i = 0; i < n; i++ )
			c += a[i]/mid;
		if ( c < k )
			end = mid;
		else
			begin = mid+1;
	}
	if ( begin == end )
	{
		t = double(begin-50)/10000;
		printf("%.2lf\n",t);
	}
	else
	{
		t = (begin+end)/2;
		t -= 50.0;
		t /= 10000.0;
		printf("%.2lf\n",t);
	}
	return 0;
}