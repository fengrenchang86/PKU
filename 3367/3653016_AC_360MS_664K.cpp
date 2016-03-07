#include <iostream>
#include <vector>
using namespace std;
const int N = 11000;
vector<char>a[N];
char t[N];
int pos,maxlay;
void f( int lay )
{
	if ( maxlay < lay )
		maxlay = lay;
	char ch = t[pos];
	a[lay].push_back(t[pos]);
	pos--;
	if ( ch >= 'A' && ch <= 'Z' )
	{
		f(lay+1);
		f(lay+1);
	}
}
int main ()
{
	int tc;
	char ch;
	scanf("%d",&tc);
	int i,j,n;
	while ( tc-- )
	{
		maxlay = -1;
		scanf("%s",&t);
		pos = strlen(t)-1;
		f(0);
		for ( i = maxlay; i >= 0; i-- )
		{
			n = a[i].size();
			for ( j = 0; j < n; j++ )
			{
				ch = a[i][j];
				printf("%c",ch);
			}
			a[i].clear();
		}
		printf("\n");
	}
	return 0;
}