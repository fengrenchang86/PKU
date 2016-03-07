#include <iostream>
using namespace std;
struct ac
{
	int today;
	int tomorrow;
}v[310];
int max ( int a, int b )
{
	return a>b?a:b;
}
int main ()
{
	int c[800][1002];
	int now,next;
	int i,j,k,t;
	int m,p;
	scanf("%d%d",&m,&p);
	for ( i = 0; i <= 2*p+3; i++ )
	{
		for ( j = 0; j <= m; j++ )
			c[i][j] = 0;
	}
	for ( i = 0; i < p; i++ )
		scanf("%d%d",&v[i].today,&v[i].tomorrow);
	for ( i = 1; ; i++ )
	{
		for ( j = 1; j <=m; j++ )
		{
			t = c[i][j];
			now = j;
			next = m;
			k = t;
			while ( k < p )
			{
				now -= v[k].today;
				next -= v[k].tomorrow;
				if ( now >= 0 && next >= 0 )
					c[i+1][next] = max(c[i+1][next],k+1);
				else
					break;
				k++;
			}
			c[i][j] = max(c[i][j],c[i][j-1]);
			if ( c[i][j] == p )
			{
				cout<<i+1<<endl;
				return 1;
			}
		}
	}
	return 0;
}