#pragma warning(disable:4786)
#include <iostream>
#include <string>
#include <map>
using namespace std;
struct ac
{
	int dig;
	ac *child[10];
}*root;
int suc;
char a[11000][12];
map<string,int>ma;
void init()
{
	root = new ac;
	int i;
	for ( i = 0; i < 10; i++ )
		root->child[i] = NULL;
	suc = 1;
}
void solve ()
{
	int n,i,j;
	char t[12];
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		scanf(" %s",&a[i]);
		strcpy(t,a[i]);
		j = strlen(t)-1;
		while ( j > 0 )
		{
			t[j] = NULL;
			ma[t] = 1;
			j--;
		}
	}
	for ( i = 0; i < n; i++ )
	{
		if ( ma[a[i]] != 0 )
			break;
	}
	if ( i == n )
		printf("YES\n");
	else
		printf("NO\n");
}
void insert ( char *t )
{
	int i,len=strlen(t);
	ac *p = root;
	for ( i = 0; i < len; i++ )
	{
		if ( p->child[t[i]-'0'] != NULL )
			p = p->child[t[i]-'0'];
		else
			break;
	}
	if ( i == len )
		return;
}
int main ()
{
	int tc;
	scanf("%d",&tc);
	while ( tc-- )
		solve();
	return 0;
}