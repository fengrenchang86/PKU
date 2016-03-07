#include <iostream>
using namespace std;
int main ()
{
	int m,n;
	int k;
	int i;
	while ( scanf("%d %d",&m,&n)!=EOF )
	{
		k = m;
		for ( i = 1; i < n; i++ )
		{
			while ( k%10 == 0 )
				k/=10;
			k = k%10;
				k*=(m-i);
		}
		while ( k%10 ==0 )
			k/=10;
		k = k%10;
		cout<<k<<endl;
	}
	return 1;
}