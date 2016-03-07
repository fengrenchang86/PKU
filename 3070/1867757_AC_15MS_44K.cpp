#include <iostream.h>
int exp[32];
int arr[2][2] = {1,0,0,1 };
int zero[2][2] = {1,1,1,0};
void save (int k[][2] , int t[][2] )
{
	int i;
	int j;
	for ( i = 0; i < 2; i++ )
		for ( j = 0; j < 2; j++ )
			k[i][j] = t[i][j];
}
int power ( int n )		// return 2^n
{
	int sum = 1;
	int i ;
	for ( i = 0; i < n; i++ )
		sum *= 2;
	return sum;
}
int getexp ( int n )
{
	for ( int i = 0; i <= 31; i++ )
		if ( n < exp[i] )
			break;
	return i-1;
}
void cheng ( int t[][2], int p[][2] )
{
	int a = t[0][0];
	int b = t[0][1];
	int c = t[1][0];
	int d = t[1][1];
	int a2 = p[0][0];
	int b2 = p[0][1];
	int c2 = p[1][0];
	int d2 = p[1][1];
	t[0][0] = (a*a2+b*c2)%10000;
	t[0][1] = (a*b2+b*d2)%10000;
	t[1][0] = (c*a2+d*c2)%10000;
	t[1][1] = (c*b2+d*d2)%10000;
}

void square ( int t[][2] )
{
	int a = t[0][0];
	int b = t[0][1];
	int c = t[1][0];
	int d = t[1][1];
	t[0][0] = (a*a+b*c)%10000;
	t[0][1] = (a*b+b*d)%10000;
	t[1][0] = (c*a+d*c)%10000;
	t[1][1] = (c*b+d*d)%10000;
}
void print ( int t[][2] )
{
	int i;
	int j;
	for ( i = 0; i < 2; i++ )
	{
		for (j = 0; j < 2; j++ )
			cout<<t[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}


void main ()
{
	int a[2][2] = { 1, 1, 1, 0 };
	int b[2][2] = { 1, 0, 0, 1 };
	int n = 3;
	int i;
	int j;
	int k;
	for ( i = 0; i <= 31; i++ )
		exp[i] = power(i);
	while (cin>>n &&n!=-1 )
	{
		if ( n == 0 )
		{
			cout<<0<<endl;
			continue;
		}
		save ( a , zero );
		save ( arr, b );
		k = n;
		while ( k != 0 )
		{
			j = getexp ( k );
			k = k - power(j);
			save ( a, zero );
			for ( i = 0; i < j; i++ )
				square(a);
			cheng( arr, a );
		}
		cout<<arr[0][1]<<endl;
	}
	

}
