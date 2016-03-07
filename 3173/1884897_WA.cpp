
#include <iostream>
using namespace std;
void print ( int k )
{
	k*=2;
	for ( int i = 0; i < k; i++ )
		cout<<" ";
}
int main ()
{
	int n;
	int s;
	int i;
	int j;
	int k;
	scanf("%d %d",&n,&s);
	for ( i = 1; i <= n; i++ )
	{
		print(i-1);
		k = i*(i+1)/2+s-1;
		if ( k%9 != 0 )
		k = k%9;
		for ( j = i; j <= n; j++ )
		{
			cout<<k<<" ";
			k = k +j;
			if ( k%9 != 0 )
			k %=9;
			
		}
		cout<<endl;
	}
	return 1;
}