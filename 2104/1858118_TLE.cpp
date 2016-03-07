#include<iostream.h>
int f(int ar[],int a, int b, int c )
{
	int *arr = new int[b+1];
	int i;
	int j;
	int t;
	for (t = 0, i = a; i <= b; i++,t++)
		arr[t] = ar[i];
	for ( i = 0; i < b-a; i++ )
		for ( j = i+1; j<=b-a; j++ )
		{
			if ( arr[i] > arr[j] )
			{
				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	return  arr[c];
}
void main ()
{
	int n;
	int m;
	cin>>n>>m;
	int i;
	int a;
	int b;
	int c;
	int k;
	int *array = new int[n];
	for ( i = 0; i < n; i++ )
		cin>>array[i];
	for ( i = 0; i < m; i++ )
	{
		cin>>a>>b>>c;
		k = f(array,a-1,b-1,c-1);
		cout<<k<<endl;
	}
}