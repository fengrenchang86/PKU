#include <iostream.h>
#include <math.h>
#include <iomanip.h>
void main ()
{
	int n;
	cin>>n;
	int *s = new int[n];
	int i;
	int j;
	int k;
	for ( i = 0; i < n; i++ )
		cin>>s[i];
	for ( i = 0; i < n - 1; i++ )
	{
		for ( j = i+1; j < n; j++ )
		{
			if ( s[i] < s[j] )
			{
				k = s[i];
				s[i] = s[j];
				s[j] = k;
			}
		}
	}
	double sum = s[0];
	for ( i = 1; i < n; i++ )
	{
		sum = 2 * sqrt(s[i] * sum);
	}
	sum *= 10000;
	k =sum - sum / 10 * 10;
	if ( k >= 5 )
		i = 1;
	else 
		i = 0;
	j = sum / 10 + i;
	cout<<j/1000<<'.';
	j = j - j/1000*1000;
	cout<<setw(3)<<setfill('0')<<j<<endl;
}