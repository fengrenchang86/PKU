#include <iostream>
using namespace std;
bool t[1200];
int main ()
{
	int tc=1;
	int i,q,ans,num,n,m;
	while ( scanf("%d%d",&n,&m) && !(n==0&&m==0) )
	{
		memset(t,false,sizeof(t));
		for ( i = 0; i < m; i++ )
		{
			scanf("%d",&q);
			t[q] = true;
		}
		num = 0;
		ans = 0;
		for ( i = n*m; i >= 1; i-- )
		{
			if ( t[i] == false )
				num++;
			else
			{
				if ( num == 0 )
					ans++;
				else
					num--;
			}
		}
		printf("Case %d: %d\n",tc++,ans);
	}
	return 0;
}