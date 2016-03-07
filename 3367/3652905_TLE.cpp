#include <iostream>
#include <vector>
using namespace std;
const int N = 11000;
vector<char>a[N];
char t[N];
int pos,maxlay;
struct ac
{
	char op;
	ac *lchild,*rchild;
};
ac *f( int lay )
{
	if ( maxlay < lay )
		maxlay = lay;
	ac *p = new ac;
	p->op = t[pos];
	a[lay].push_back(p->op);
	pos--;
	if ( p->op >= 'A' && p->op <= 'Z' )
	{
		p->lchild = f(lay+1);
		p->rchild = f(lay+1);
	}
	else
	{
		p->lchild = NULL;
		p->rchild = NULL;
	}
	return p;
}
int main ()
{
	int tc;
	char ch;
	scanf("%d",&tc);
	ac *root;
	int i,j,n;
	while ( tc-- )
	{
		maxlay = -1;
		scanf("%s",&t);
		pos = strlen(t)-1;
		root = f(0);
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