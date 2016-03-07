#include <iostream>
using namespace std;
struct ac
{
	int begin,end,money,day;
}a[11000];
int c[11000][110];
int day[110];
int n,m;
void input ()
{
	int i,j,k,id,deadline,money;
	for ( i = 1; i <= n; i++ )
		scanf("%d",&day[i]);
	scanf("%d",&m);
	for ( i = 1; i <= m; i++ )
	{
		scanf("%d%d%d",&id,&deadline,&money);
		a[i].money = money;
		a[i].end = deadline;
		a[i].day = day[id];
		a[i].begin = a[i].end-a[i].day;
	}
	for ( i = 0; i <= 100; i++ )
		c[0][i] = 0;
	for ( i = 1; i <= m; i++ )
	{
		for ( j = 1; j <= 100; j++ )
		{
			c[i][j] = c[i][j-1];
			if ( c[i-1][j] > c[i][j] )
				c[i][j] = c[i-1][j];
			k = j-a[i].day;
			if ( k >= 0 && k <= a[i].end-a[i].day+1 && c[i][j] < c[i-1][k]+a[i].money )
				c[i][j] = c[i-1][k]+a[i].money;
		}
	}
	cout<<c[m][100]<<endl;
}
int main ()
{
	while ( scanf("%d",&n)!=EOF )
	{
		input();
	}
	return 0;
}