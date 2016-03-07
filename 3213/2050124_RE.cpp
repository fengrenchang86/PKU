#include <iostream>
using namespace std;
const int N = 1101;
int main ()
{
	int a[N][N];
	int b[N][N];
	int c[N][N];
	int i,j,k;
	_int64 sum;
	int n,p,m;
	int flag = 0;
	while (scanf("%d %d %d",&n,&p,&m) != EOF )
	{
	for ( i = 0; i < n; i++ )
		for ( j = 0; j < p; j++ )
			scanf("%d",&a[i][j]);

/*	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < p; j++ )
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
*/	for ( i = 0; i < p; i++ )
		for ( j = 0; j < m; j++ )
			scanf("%d",&b[i][j]);
/*	for ( i = 0; i < p; i++ )
	{
		for ( j = 0; j < m; j++ )
			cout<<b[i][j]<<" ";
		cout<<endl;
	}*/
	for ( i = 0; i < n; i++ )
		for ( j = 0; j < m;j++ )
			scanf("%d",&c[i][j]);
	for ( i = 0; i < n; i++ )	
	{
		for ( j = 0; j < m; j++ )
		{
			sum = 0;
			for ( k = 0; k < p; k++ )
				sum+=a[i][k]*b[k][j];
			if ( c[i][j] != sum )
			{
				flag = 1;
				break;
			}
		}
		if ( flag == 1 )
			break;
	}
/*	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < m; j++ )
			cout<<c[i][j]<<" ";
		cout<<endl;
	}
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < m; j++ )
			cout<<d[i][j]<<" ";
		cout<<endl;
	}*/
	if ( flag == 0 )
		cout<<"Yes"<<endl;
	else
	{
		flag = 0;
		cout<<"No"<<endl;
		cout<<i+1<<" "<<j+1<<endl;
		printf("%I64d\n",sum);
	}
	}
	return 1;
}