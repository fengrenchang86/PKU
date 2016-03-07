#include <iostream>
using namespace std;
int a[100100];
int main ()
{
	int m,n,i,count,j;
	int begin = 0,end = 0, mid;
	scanf("%d%d",&n,&m);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d",&a[i]);
		end += a[i];
	}
	while ( begin < end )
	{
		mid = (begin + end)/2;
		count = 0;
		j = 0;
		for ( i = 0; i < n; i++ )
		{
			j+=a[i];
			if ( j == mid )
			{
				count++;
				j = 0;
			}
			else if ( j > mid )
			{
				count++;
				j = a[i];
			}
			if ( j > mid )
			{
				count = m;
				break;
			}
		}
		if ( j == 0 )
			count--;
		if ( count < m )
			end = mid;
		else
			begin = mid+1;
	}
	cout<<end<<endl;
	return 0;
}