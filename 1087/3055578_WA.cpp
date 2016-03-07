#include <iostream>
#include <string>
using namespace std;
char device[521][30];
char recept[521][30];
int c[521][521] = {0};
bool visit[521];
int w[521];
int path[521];
int n,m,k;
int Find ( char *t )
{
	int i;
	for ( i = 1; i <= n; i++ )
	{
		if ( strcmp(t,recept[i])==0 )
			return i;
	}
	n++;
	strcpy(recept[n],t);
	return n;
}
void init()
{
	int i,j,d;
	for ( i = 0; i < 521; i++ )
	{
		for ( j = 0; j < 521; j++ )
			c[i][j] = 0;
	}
	device[0][0] = NULL;
	recept[0][0] = NULL;
	char ch[30],th[30];
	scanf("%d",&n);
	for ( i = 1; i <= n; i++ )
	{
		scanf(" %s",recept[i]);
		c[i][520] = 1;
	}
	scanf("%d",&m);
	for ( i = 1; i <= m; i++ )
	{
		scanf(" %s %s",&device[i],&ch);
		j = Find(ch);
		c[0][j] ++;
	}
	scanf("%d",&k);
	for ( i = 0; i < k; i++ )
	{
		scanf(" %s %s",ch,th);
		j = Find(ch);
		d = Find(th);
		c[j][d]=100000;
	}
}
void updata( int x )
{
	if ( x == 0 )
		return;
	c[path[x]][x]--;
	updata(path[x]);
}
int dij ()
{
	memset(visit,false,sizeof(visit));
	int i,j,l,min;
	for ( i = 1; i <= 520; i++ )
		w[i] = 2000000000;
	w[0] = 0;
	for ( i = 0; i < 200; i++ )
	{
		min = 2000000000;
		for ( j = 0; j <= 520; j++ )
		{
			if ( w[j] < min && visit[j] == false )
			{
				min = w[j];
				l = j;
			}
		}
		if ( min == 2000000000 )
			break;
		visit[l] = true;
		for ( j = 1; j <= 520; j++ )
		{
			if ( l == j || visit[j] == true )
				continue;
			if ( c[l][j] > 0 && w[j] > w[l]+1 )
			{
				w[j] = w[l]+1;
				path[j] = l;
			}
		}
	}
	if ( w[520] != 2000000000 )
	{
		updata(520);
		return 1;
	}
	else
		return -1;
}
int main ()
{
	int x=0;
	init();
	while ( dij()==1 )
		x++;
	cout<<m-x<<endl;
	return 0;
}