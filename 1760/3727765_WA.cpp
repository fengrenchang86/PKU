#pragma warning (disable:4786)
#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>
using namespace std;
#define N 1001
char dic[N][10];
int n,m;
bool c[1100][1100];
struct strt
{
	char ch[10];
	int id;
}a[N];
int visit[N];
bool head[N];
map<string,int>ma;
int cmp ( const void*a, const void*b )
{
	struct strt *c = (strt*)a;
	struct strt *d = (strt*)b;
	return strcmp(c->ch,d->ch);
}
void init ()
{
	int i,j;
	m = 1;
	for ( i = 0; i < N; i++ )
	{
		visit[i] = 0;
		head[i] = true;
		for ( j = 0; j < N; j++ )
			c[i][j] = false;
	}
}
void insert ( int x, int y )
{
/*	ac *p = new ac;
	p->v = y;
	p->next = list[x];
	list[x] = p;*/
	c[x][y] = true;
}
void f ( char *t )
{
	int x,y;
	int i=0,j=0;
	while ( t[i] != ' ' && t[i] != 0 && t[i] != '\\' )
	{
		dic[m][j++] = t[i];
		i++;
	}
	dic[m][j] = 0;
	if ( ma[dic[m]] == 0 )
	{
		ma[dic[m]] = m;
		x = m;
		m++;
	}
	else
		x = ma[dic[m]];
	if ( t[i] == '\\' )
		i++;
	while ( t[i] != 0 )
	{
		while ( t[i] == ' ' )
			i++;
		if ( t[i] == 0 )
			break;
		j = 0;
		while ( t[i] != ' ' && t[i] != 0 && t[i] != '\\' )
		{
			dic[m][j++] = t[i];
			i++;
		}
		dic[m][j] = 0;
		if ( ma[dic[m]] == 0 )
		{
			ma[dic[m]] = m;
			y = m;
			m++;
		}
		else
		{
			y = ma[dic[m]];
		}
		head[y] = false;
		insert(x,y);
		visit[y]++;
		x = y;
		if ( t[i] == '\\' )
			i++;
	}
}
void dfs ( int node, int lay )
{	
//	visit[node]--;
	int i,j,n=0;
	for ( i = 0; i < lay; i++ )
		printf(" ");
	printf("%s\n",dic[node]);
	for ( i = 1; i < m; i++ )
	{
		if ( c[node][i] )
			n++;
	}
	strt q[1000];
	j = 0;
	for ( i = 1; i < m; i++ )
	{
		if ( !c[node][i] )
			continue;
		q[j].id = i;
		strcpy(q[j].ch,dic[i]);
		j++;
	}
	qsort(q,n,sizeof(q[0]),cmp);
	for ( i = 0; i < n; i++ )
	{
//		if ( visit[q[i].id] != 0 )
			dfs(q[i].id,lay+1);
	}
}
bool solve ()
{
	char c[200];
	int i,j=0;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		scanf(" %s",c);
		f(c);
	}
	for ( i = 1; i < m; i++ )
	{
		if ( head[i] )
		{
			strcpy(a[j].ch,dic[i]);
			a[j++].id = i;
		}
	}
	qsort(a,j,sizeof(a[0]),cmp);
	for ( i = 0; i < j; i++ )
	{
	//	if ( visit[a[i].id] >= 0 )
			dfs(a[i].id,0);
	}
	return true;
}
int main ()
{
	init();
	solve();
	return 0;
}