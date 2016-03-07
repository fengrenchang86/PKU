#include <iostream.h>
#include <iomanip.h>
void main ()
{
	int N;
	cin>>N;
	int i;
	int j;
	int n;
	int a;
	double sum = 0.0;
	double count;
	int jw;
	for ( i = 0; i < N ;i++ )
	{
		count = 0.0;
		sum = 0.0;
		cin>>n;
		int *arr = new int[n];
		for ( j = 0; j < n; j++ )
		{
			cin>>arr[j];
			sum += arr[j];
		}
		sum = sum / n;
		for (j = 0; j < n; j++ )
		{
			if ( arr[j] > sum )
				count++;
		}
		sum = count/n;
		a = sum * 1000000;
		sum = a;
		if ( a - a / 10 * 10 >= 5 )
			jw = 1;
		else 
			jw = 0;
		a = a / 10 + jw;
		cout<< a / 1000<<'.';
		a = a - a/1000*1000;
		cout<< a / 100;
		a = a - a/100 * 100;
		cout<< a / 10;
		a = a - a / 10 * 10;
		cout<<a<<'%'<<endl;
		delete arr;
	}
}