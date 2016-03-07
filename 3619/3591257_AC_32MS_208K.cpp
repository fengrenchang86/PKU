#include <iostream>
using namespace std;
int main ()
{
	int n,k,s,t,r;
	int i,j,ans,m,p;
	scanf("%d%d",&n,&k);
	m = n;
	for ( i = 0; i < k; i++ )
	{
		n = m;
		scanf("%d%d%d",&s,&t,&r);
		ans = 0;
		for ( j = 0; j < n; )
		{
			for ( p = 0; p < t && j < n; p++ )
			{
				ans++;
				j+=s;
			}
			if ( j >= n )
				break;
			ans += r;
		}
		printf("%d\n",ans);
	}
	return 0;
}