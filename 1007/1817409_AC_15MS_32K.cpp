#include < iostream.h >

void main()
{
	char A[100][50];
	int m;
	int n;
	cin>>n>>m;
	int i = 0;
	int j;
	int k;
	int temp;
	int a[100][2];
	while ( i < m )
	{
		cin>>A[i];
		a[i][0] = i;
		a[i][1] = 0;
		for ( j = 0; j < n-1; j++ )
		{
			for ( k = j+1; k < n; k++)
			{
				if ( A[i][j] > A[i][k] )
					a[i][1]++;
			}
		}
		i++;
	}
	for ( j = 0; j < m-1; j++ )
	{
		for ( k = j+1; k < m; k++ )
		{
			if ( a[j][1] > a[k][1] )
			{
				temp = a[j][1];
				a[j][1] = a[k][1];
				a[k][1] = temp;
				temp = a[j][0];
				a[j][0] = a[k][0];
				a[k][0] = temp;
			}
		}
	}
	for ( i = 0; i < m; i++ )
	{
		j = a[i][0];
		for ( k = 0; k < n; k++ )
		{
			cout<<A[j][k];
		}
		cout<<endl;
	}
}
