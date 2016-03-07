#include <iostream>
using namespace std;
int a[40000];
int main ()
{
	memset(a,0,sizeof(a));
	int i,j,k,l;
	int t;
	for ( i = 1; i <= 182; i++ )
	{
		t = i*i;
		a[t] ++;
		for ( j = i; j <= 182; j++ )
		{
			t += j*j;
			if ( t <= 32768 )
				a[t] ++;
			else
			{
				t -= j*j;
				break;
			}
			for ( k = j; k <= 182; k++ )
			{
				t += k*k;
				if ( t <= 32768 )
					a[t]++;
				else
				{
					t -= k*k;
					break;
				}
				for ( l = k; l <= 182; l++ )
				{
					if ( t+l*l <= 32768 )
						a[t+l*l]++;
					else
						break;
				}
				t -= k*k;
			}
			t -= j*j;
		}
	}
	while ( cin>>k && k!= 0 )
			cout<<a[k]<<endl;
	return 0;
}