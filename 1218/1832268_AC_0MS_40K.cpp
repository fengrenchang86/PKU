#include <iostream.h>
void main ()
{
	int n;
	int i;
	cin>>n;
	int num;
	int j;
	int k;
	int count;
	for ( i = 0; i < n; i++ )
	{
		count = 0;
		cin>>num;
		int *arr = new int[num+1];
		for ( j = 1; j <= num; j++ )
			arr[j] = -1;
		for ( j = 1; j <= num; j++ )
		{
			for ( k = j; k <= num ; k += j )
				arr[k] *= -1;
		}
		for ( j = 1; j <= num; j++ )
			if ( arr[j] > 0 )
				count++;
		cout<<count<<endl;
		delete arr;
	}
	
}
