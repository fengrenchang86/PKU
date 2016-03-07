
//3125438 RebornACM 3373 Accepted 3116K 15MS C++ 1653B 2008-02-27 08:31:43 
#include <iostream>
using namespace std;
int c[7][110000];
char cht[120];
int mod;
int a[120];
char change[120];
int minL,len;
char ans[120];
int begin;
void init ()
{
	minL = 6;
	int i,k=1;
	for ( i = 0; i < 7; i++ )
		memset(c[i],0,sizeof(c[i]));
	len=strlen(cht);
	begin = 0;
	for ( i = 0; i < len; i++ )
	{
		begin *= 10;
		begin += cht[i]-'0';
		begin %= mod;
		a[len-1-i] = k;
		k *= 10;
		k %= mod;
		change[i] = cht[i];
	}
}
void dfs ( int lay, int x, int edit )
{
	if ( edit > minL )
		return;
	else if ( x == 0 )
	{
		if ( edit < minL )
		{
			minL = edit;
			for ( int i = 0; i < len; i++ )
				ans[i] = change[i];
			ans[i] = NULL;
		}
		else if ( strcmp(ans,change)>0 )
			strcpy(ans,change);
		return;
	}
	else if ( lay == len )
		return;
	int i,y,g;
	if ( lay == 0 )
		i = 1;
	else
		i = 0;
	for ( ; i < cht[lay]-'0' ; i++ )
	{
		y = a[lay]*(cht[lay]-'0'-i);
		y = (x-y+9*mod)%mod;
		if ( edit + 1 >= minL )
			return;
//		if ( !c[edit+1][y] )
		{
			c[edit+1][y] = 1;
			g = change[lay]-'0';
			change[lay] = i+'0';
			dfs(lay+1,y,edit+1);
			change[lay] = g+'0';
		}
	}
	dfs(lay+1,x,edit);
	if ( edit+1 >= minL )
		return;
	for ( i = cht[lay]-'0'+1; i < 10; i++ )
	{
		y = a[lay]*(i-(cht[lay]-'0'));
		y = (x+y)%mod;
//		if ( !c[edit+1][y] )
		{
			c[edit+1][y] = 1;
			g = change[lay]-'0';
			change[lay] = i+'0';
			dfs(lay+1,y,edit+1);
			change[lay] = g+'0';
		}
	}
}
int main ()
{
	while ( scanf(" %s %d",&cht,&mod) != EOF )
	{
		init();
		dfs(0,begin,0);
		cout<<ans<<endl;
	}
	return 0;
}
