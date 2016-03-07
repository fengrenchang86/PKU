#include <iostream.h>
void main ()
{
	int a[3] = {0,0,0};
	int arr[100];
	int i;
	int j;
	int sum;
	int cf ( int, int );
	for ( i = 0; i < 100; i++ )
		arr[i] = cf ( i+1, 3 );

//	for ( i = 0; i < 100; i++ )
//		cout<<i+1<<" "<<arr[i]<<endl;
	int n;
	cin>>n;
	for ( i = 1; i <= n; i++ )
	{
		a[0] = 1;
		a[1] = 1;
		a[2] = 1;
		while ( a[0] < i )
		{
			sum = arr[a[0]] + arr[a[1]] + arr[a[2]];
			if ( sum == arr[i-1] && a[0] <= a[1] && a[1] <= a[2])
				cout<<"Cube = "<<i<<", Triple = ("<<a[0] +1<<','<<a[1] + 1<<','<<a[2] + 1<<')'<<endl;
			a[2]++;
			j = 2;
			while ( a[j] == i )
			{
				a[j] = 0;
				j--;
				a[j]++;
				if ( a[0] == i )
					break;
			}
		
		}
	}

}

int cf ( int num, int n )
{
	
	int i;
	int ans = 1;
	for ( i = 0; i < n; i++ )
		ans *= num;
	return ans;
}