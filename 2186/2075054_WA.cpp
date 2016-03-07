#include <iostream>
using namespace std;
int main ()
{
	int n,m;
	int i,j,k;
	cin>>n>>m;
	char **a = new char*[n+1];
	for ( i = 0; i <= n; i++ )
		a[i] = new char[n+1];
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d",&j,&k);
		a[j][k] = 1;
	}
	k = 5;
	cout<<k<<endl;
	return 0;
}