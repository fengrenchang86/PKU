#include <iostream>
using namespace std;
int main ()
{
	int n,k,i;
	_int64 begin,end,mid;
	_int64 a[100100];
	_int64 sum = 0;
	double t;
	scanf("%d%d",&n,&k);
	for ( i = 0; i < n; i++ )
	{
		scanf("%lf",&t);
		a[i] = int(t*1000);
		sum += a[i];
	}
	begin = 0;
	_int64 c;
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
	begin = begin/10*10;
	t = double(begin)/1000;
	printf("%.2lf\n",t);
	return 0;
}