#include <iostream>
using namespace std;
char a[300],b[300];
int list[10];
bool check ()
{
	int i;
	for ( i = 0; i < 10; i++ )
	{
		if ( list[i] > 0 )
			return false;
	}
	return true;
}
void solve ( )
{
	int i,n;
	int x,y;
	memset(list,0,sizeof(list));
	scanf(" %s %s",a,b);
	n = strlen(b);
	for ( i = 0; a[i] != 0; i++ )
		list[a[i]-'0']++;
	for ( i = 0; b[i] != 0; i++ )
		list[b[i]-'0']--;
	if ( check() )
	{
		printf("friends\n");
		return;
	}
	for ( i = 0; i < n-1; i++ )
	{
		x = b[i]-'0';
		y = b[i+1]-'0';
		if ( x-1>=0 && y+1 <= 9 )
		{
			list[x]++;
			list[y]++;
			list[x-1]--;
			list[y+1]--;
			if ( check() )
			{
				printf("almost friends\n");
				return;
			}
			list[x]--;
			list[y]--;
			list[x-1]++;
			list[y+1]++;
		}
		if ( x+1 <= 9 && y-1 >= 0 )
		{
			list[x]++;
			list[y]++;
			list[x+1]--;
			list[y-1]--;
			if ( check() )
			{
				printf("almost friends\n");
				return;
			}
			list[x]--;
			list[y]--;
			list[x+1]++;
			list[y-1]++;
		}
	}
	printf("nothing\n");
}
int main ()
{
	int tc;
	scanf("%d",&tc);
	while ( tc-- )
		solve();
	return 0;
}