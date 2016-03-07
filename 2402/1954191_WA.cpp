#include <iostream.h>
int save[500];
int f ( int n, int i )
{
	if ( n == 0 )
		i--;
	int a;
	int k;
	int j;
	int b[20];
	int sum = 1;
	for( a = 1; a < (i+1)/2; a++ )
		sum *= 10;
	sum += n;
	if ( n == 0 )
		sum *= 10;
	sum--;
	k = sum;
	a = 0;
	while ( k != 0)
	{
		b[a++] = k - k/10*10;
		k /= 10;
	}
	k = a-1;
	j = 0;
	while ( k >=0 )
		save[j++] = b[k--];
	if ( i%2!=0 )
		sum = 1;
	else
		sum = 0;
	while ( sum < a )
		save[j++] = b[sum++];
	return j;
}

void main ()
{
	int a[19] = {0,9,18,108,198,1098,1998,10998,19998,109998,199998,1099998,1999998,10999998,
		19999998,109999998,199999998,1099999998,1999999998};
	int i;
	int n;
	int sum;
	cin>>n;
//	while ( cin>>n && n != 0 )
	while ( n-->500 )
	{
		i = 0;
		while ( n >= a[i] )
			i++;
		sum = n-a[i-1];
		sum = f ( sum, i );
		for ( i = 0; i < sum; i++ )
			cout<<save[i];
		cout<<endl;
	}
}