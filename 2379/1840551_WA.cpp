#include <iostream.h>
void main ()
{
	int ci,pi,ti,ri;
	int c,n;
	int i;
	int j =0;
	int k;
	cin>>c>>n;
	int count[1010][2];
	int a[1010][30];
	int *time = new int[c+5];
	for ( i = 0; i < c; i++ )
	{
		count[i][0] = 0;
		count[i][1] = i;
		time[i] = 0;
	}
	for ( i = 0; i < c; i++ )
		for ( j = 0; j < 30; j++ )
			a[i][j] = 0;
	for( i = 0; i < n; i++ )
	{
		cin>>ci>>pi>>ti>>ri;
		ci--;
		pi--;
		if ( a[ci][pi] <= 0 )
			a[ci][pi] -= 1200;
		if ( ri == 1 && a[ci][pi]<0 )
		{
			a[ci][pi]+=1200;
			a[ci][pi] *= -1;
			a[ci][pi] += ti;
			count[ci][0]++;
			time[ci] += a[ci][pi];

		}
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
		}
	}
	for ( i = 0; i < c-1; i++ )
	{
		for ( j = i+1; j < c; j++ )
		{
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
		cout<<count[i][1]+1<<' ';
	cout<<endl;
}
