#include <iostream.h>
int arr[6];
void print ( int n, int a[] )
{
	int i;
	cout<<a[arr[0]];
	for ( i = 1; i < 6; i++ )
		cout<<" "<<a[arr[i]];
	cout<<endl;
}

void main ()
{
	int k;
	int s[20];
	int i;
	int j;
	while ( cin>>k && k != 0 )
	{
		for ( i = 0; i < k; i++ )
			cin>>s[i];
		for ( i = 0; i < 6; i++ )
			arr[i] = i;
		print ( k ,s);
		while ( arr[0] < k-6 )
		{
			arr[5]++;
			i = 5;
			while ( arr[i] > k-5+i-1 )
			{
				i--;
				if ( i == -1 )
					break;
				arr[i]++;
				for ( j = i+1; j < 6; j++ )
					arr[j] = arr[j-1]+1;
			}
			print ( k, s );
		}
		cout<<endl;
	}
}