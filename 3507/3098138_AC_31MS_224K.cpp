#include <iostream>
using namespace std;
int main ()
{
	int a[10];
	int i,min,max,sum;
	while ( cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5])
	{
		sum = 0;
		min = 20000000;
		max = -1;
		for ( i = 0; i < 6; i++ )
		{
			if ( a[i] < min )
				min = a[i];
			if ( a[i] > max )
				max = a[i];
			sum += a[i];
		}
		if ( sum == 0 )
			break;
		sum -= min;
		sum -= max;
		if ( sum % 4 == 0 )
			cout<<sum/4<<endl;
		else
			cout<<double(double(sum)/4)<<endl;
	}
	return 0;
}