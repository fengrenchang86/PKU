#include <iostream>
using namespace std;
const int N = 1200;
int main ()
{
	short a[N][N];
	short b[N][N];
	int c[N][N];
	int i,j,k,h;
	int x,y;
	int sum;
	int n,p,m;
	int flag = 0;
//	while (scanf("%d %d %d",&n,&p,&m) != EOF )
	scanf("%d %d %d",&n,&p,&m);
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
/*	for ( i = 0; i < n; i++ )
		for ( j = 0; j < m;j++ )
			scanf("%d",&c[i][j]);*/
	for ( i = 0; i < n; i++ )	
	{
		for ( j = 0; j < m; j++ )
		{
			scanf("%d",&h);
			if ( flag == 1 )
				continue;
			sum = 0;
			for ( k = 0; k < p; k++ )
				sum+=a[i][k]*b[k][j];
			if ( h != sum )
			{
				x = i+1;
				y = j+1;
				flag = 1;
			}
		}
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
		cout<<x<<" "<<y<<endl;
		cout<<sum<<endl;
	}
	}
	return 0;
}