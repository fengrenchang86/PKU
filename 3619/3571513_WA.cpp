#include <iostream>
using namespace std;
int main ()
{
	int n,m,k,i,s,t,r,ans;
	scanf("%d%d",&n,&k);
	for ( i = 0; i < k; i++ )
	{
		m = n;
		scanf("%d%d%d",&s,&t,&r);
		ans = m/(s*t);
		ans *= (t+r);
		m %= (s*t);
		ans += m/s;
		if ( m >= (s+1)/s && m % s != 0 )
			ans++;
		printf("%d\n",ans);
	}
	return 0;
}