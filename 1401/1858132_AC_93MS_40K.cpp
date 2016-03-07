#include<iostream.h>
int power ( int a, int b)
{
	int sum = 1;
	int i;
	for ( i = 0; i < b; i++ )
		sum*= a;
	return sum;
}
void main ()
{
	int n;
	int m;
	int arr[20];
	int i;
	int j;
	int k;
	for ( i = 0,j=1;i < 13;i++,j++)
		arr[i] = power(5,j);
	cin>>n;
	for ( j = 0; j < n; j++ )
	{
		cin>>m;
		k = 0;
		for ( i = 0; i < 13; i++ )
			k += ( m/arr[i] );
		cout<<k<<endl;
	}

}