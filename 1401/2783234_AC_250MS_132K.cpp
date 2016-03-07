#include<iostream>
using namespace std;
int main ()
{
	int power(int,int);
	int n;
	int m;
	int arr[32];
	int i;
	int j;
	int k;
	for ( i = 0,j=1;i <= 12;i++,j++)
		arr[i] = power(5,j);
	scanf("%d",&n);
	for ( j = 0; j < n; j++ )
	{
		scanf("%d",&m);
		k = 0;
		for ( i = 0; i <= 12; i++ )
			k += ( m/arr[i] );
		cout<<k<<endl;
	}
	return 0;
}
int power ( int a, int b)
{
	if ( b == 0 )
		return 1;
	else if ( b == 1 )
		return a;
	if ( b % 2 == 0 )
	{
		int t = power(a,b/2);
		return t*t;
	}
	else
	{
		int t = power(a,b/2);
		t = t*t*a;
		return t;
	}
}