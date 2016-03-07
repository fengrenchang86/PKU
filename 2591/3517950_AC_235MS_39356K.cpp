#include <iostream>
using namespace std;
int a[10000010];
int n;
void make ( )
{
	int i=1,j=1,k=2;
	a[1] = 1;
	n = 10000000;
	while ( k <= n )
	{
		if ( 2*a[i] < 3*a[j] )
		{
			a[k++] = 2*a[i]+1;
			i++;
		}
		else if ( 2*a[i] == 3*a[j] )
		{
			a[k++] = 2*a[i]+1;
			i++;
			j++;
		}
		else
		{
			a[k++] = 3*a[j]+1;
			j++;
		}
	}
}
int main ()
{
	make();
	int k;
	while ( cin>>k )
		cout<<a[k]<<endl;
	return 0;
}