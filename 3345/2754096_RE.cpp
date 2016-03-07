#include <iostream>
#include <string>
using namespace std;
struct ac
{
	int v;
	ac *next;
}*list[210];
struct data
{
	char name[120];
	int cost,number;
	bool ok;
}a[210];
int end;
int m,n;
int min ( int x, int y )
{
	return x<y?x:y;
}
void insert ( int x, int y )
{
	ac *p = new ac;
	p->next = list[x];
	p->v = y;
	list[x] = p;
}
void getmn( char *a )
{
	int i = 0;
	m = n = 0;
	while ( a[i] == ' ' )
		i++;
	while ( a[i] >= '0' && a[i] <= '9' )
	{
		n *= 10;
		n += a[i]-'0';
		i++;
	}
	while ( a[i] == ' ' )
		i++;
	while ( a[i] >= '0' && a[i] <= '9' )
	{
		m *= 10;
		m += a[i]-'0';
		i++;
	}
}
int search ( char *t )
{
	int i;
	for ( i = 0; i < end; i++ )
		if ( strcmp(t,a[i].name)==0 )
			return i;
	return -1;
}
void f ( char *t, int k )
{
	int i = 0,j=0,q;
	char c[120];
	while ( t[i] != NULL )
	{
		while ( t[i] == ' ' )
			i++;
		if ( t[i] == NULL )
			return;
		while ( t[i] != ' ' && t[i] != NULL )
			c[j++] = t[i++];
		c[j] = NULL;
		q = search(c);
		if ( q == -1 )
		{
			q = end;
			strcpy(a[end].name,c);
			end++;
		}
		insert(k,q);
		j = 0;
	}
}
int dfs ( int node )
{
	int k = 1;
	ac *p = list[node];
	while ( p != NULL )
	{
		k += dfs(p->v);
		p = p->next;
	}
	a[node].number=k;
	return k;
}
int main ()
{
	char input[1200];
	int c[210][210];
	int i,t,j,num;
	while ( gets(input) && input[0] != '#' )
	{
		if ( input[0] == NULL )
			continue;
		end = 0;
		getmn(input);
		for ( i = 0; i < n; i++ )
		{
			list[i] = NULL;
			a[i].number = 0;
		}
		for ( i = 0; i < n; i++ )
		{
			cin>>input>>num;
			t = search(input);
			if ( t == -1 )
			{
				t = end;
				strcpy(a[end].name,input);
				a[end].cost = num;
				end++;
			}
			else
				a[t].cost = num;
			gets(input);
			f(input,i);
		}
		for ( i = 0; i < n; i++ )
		{
			if ( a[i].number == 0 )
				dfs(i);
			for ( j = 0; j <= m; j++ )
				c[i][j] = 2000000000;
		}
		c[0][a[0].number] = a[0].cost;
		c[0][0] = 0;
		for ( j = a[0].number+1; j <= m; j++ )
			c[0][i] = c[0][i-1];
		for ( i = 1; i < n; i++ )
		{
			c[i][0] = 0;
			for ( j = 1; j <= m; j++ )
			{
				if ( c[i-1][j] != 2000000000 )
					c[i][j] = c[i-1][j];
				if ( j >= a[i].number )
					c[i][j] = min(c[i][j],c[i-1][j-a[i].number]+a[i].cost);
			}
		}
		cout<<c[n-1][m]<<endl;
	//	cin.ignore();
	}
	return 0;
}