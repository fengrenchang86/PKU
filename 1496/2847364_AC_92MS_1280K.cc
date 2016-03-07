#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
struct ac
{
	char name[8];
	int num;
}a[90000];
char t[10],ch;
int end;
int main ()
{
	end = 0;
	int cmp ( const void*, const void* );
	int find();
	void dfs(int,int,int);
	dfs(1,0,0);
	dfs(2,0,0);
	dfs(3,0,0);
	dfs(4,0,0);
	dfs(5,0,0);
	a[83681].num = 0;
	qsort(a,83681,sizeof(a[0]),cmp);
	while ( cin>>t )
		cout<<a[find()].num<<endl;
	return 0;
}
int cmp ( const void*a, const void*b )
{
	struct ac* c = (ac*)a;
	struct ac* d = (ac*)b;
	return strcmp(c->name,d->name);
}
int find( )
{
	int i = 0, j = end-1, k,x;
	while ( i < j )
	{
		k = (i+j)/2;
		x = strcmp(t,a[k].name);
		if ( x < 0 )
			j = k;
		else if ( x > 0 )
			i = k+1;
		else
			return k;
	}
	if ( strcmp(t,a[i].name)==0)
		return i;
	else
		return 83681;
}
void dfs( int n, int k, int p )
{
	if ( k == n )
	{
		t[n+1] = NULL;
		strcpy(a[end].name,t);
		a[end].num = end+1;
		end++;
		return;
	}
	int i;
	for ( i = p+1; i <= 26; i++ )
	{
		t[k] = i+'a'-1;
		dfs(n,k+1,i);
	}
}