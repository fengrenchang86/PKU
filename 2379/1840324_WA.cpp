#include <iostream.h>
void main ()
{
	int ci,pi,ti,ri;
	int c,n;
	int i;
	int j =0;
	int k;
	cin>>c>>n;
	int **count;
	count = new int *[2];
	int **a;
	a = new int *[10];
	int *time = new int[c];
	for ( i = 0; i < c; i++ )
	{
		count[i] = new int[1000];
		a[i] = new int[1000];
		count[i][0] = 0;
		count[i][1] = i+1;
	}
	for ( i = 0; i < c; i++ )
		for ( j = 0; j < 1000; j++ )
			a[i][j] = 0;
	for( i = 0; i < n; i++ )
	{
		cin>>ci>>pi>>ti>>ri;
		if ( a[ci][pi] <= 0 )
			a[ci][pi] -= ti;
		if ( ri == 1 && a[ci][pi]<0 )
		{
			a[ci][pi] *= -1;
			count[ci][0]++;
		}
	}
	for ( i = 0; i < c; i++ )
	{
		for ( j = 0; j < 1000; j++ )
			time[i] += a[i][j];
	}
	for ( i = 0; i < c-1; i++ )
	{
		for ( j = i+1; j < c; j++ )
		{
			if ( count[i][0] < count[j][0] )
			{
				k = count[i][0];
				count[i][0] = count[j][0];
				count[j][0] = k;
				k = count[i][1];
				count[i][1] = count[j][1];
				count[j][1] = k;
			}
			if ( count[i][0] == count[j][0] )
			{
				if ( time[i] > time[j] )
				{
					k = count[i][0];
					count[i][0] = count[j][0];
					count[j][0] = k;
					k = count[i][1];
					count[i][1] = count[j][1];
					count[j][1] = k;
				}
			}
		}
	}
	for ( i = 0; i < c; i++ )
		cout<<count[i][1]<<" ";
	cout<<endl;
}
