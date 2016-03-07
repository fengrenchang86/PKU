#include <iostream>
using namespace std;
int main ()
{
	int t[10100];
	int a[10100];
	int tcase,i,j,k,n,m;
	scanf("%d",&tcase);
	while ( tcase-- )
	{
		t[0] = 0;
		scanf("%d%d",&m,&n);
		for ( i = 1; i <= n; i++ )
			scanf("%d",&a[i]);
		t[1] = (m-a[1])*(m-a[1]);
		for ( i = 2; i <= n; i++ )
		{
			t[i] = t[i-1] + (m-a[i])*(m-a[i]);
			j = a[i];
			for ( k = i-1; k > 0; k-- )
			{
				j += a[k]+1;
				if ( j > m )
					break;
				if ( t[i] > t[k-1] + (m-j)*(m-j) )
					t[i] = t[k-1] + (m-j)*(m-j);
			}
		}
		cout<<t[n]<<endl;
	}
	return 0;
}