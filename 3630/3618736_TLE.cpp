#pragma warning(disable:4786)
#include <iostream>
#include <string>
#include <map>
using namespace std;
struct ac
{
	int dig;
	ac *child[10];
	ac(){dig=0;
	int i;
	for ( i = 0; i < 10; i++ )
	child[i]=NULL;}
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
void insert ( char *t )
{
	int i,len=strlen(t);
	ac *p = root;
	root->dig = 1;
	for ( i = 0; i < len; i++ )
	{
		if ( p->child[t[i]-'0'] != NULL )
			p = p->child[t[i]-'0'];
		else
			break;
	}
	if ( i == len  )
		suc = -1;
	else
	{
		if ( p->dig == 0 )
			suc = -1;
		else
		{
			while ( i < len )
			{
				p->dig = 1;
				p->child[t[i]-'0'] = new ac;
				p = p->child[t[i]-'0'];
				i++;
			}
		}
	}
}
void solve ()
{
	char t[12];
	int i,n;
	scanf("%d",&n);
	init();
	for ( i = 0; i < n; i++ )
	{
		scanf(" %s",t);
		insert(t);
	}
	if ( suc == -1 )
		printf("NO\n");
	else
		printf("YES\n");
}
int main ()
{
	int tc;
	scanf("%d",&tc);
	while ( tc-- )
		solve();
	return 0;
}