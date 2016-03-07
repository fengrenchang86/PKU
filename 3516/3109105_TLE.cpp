#include <iostream>
#include <string>
using namespace std;
struct ac
{
	bool yes;
	int pre,data;
}c[260][110000];
int len,m;
char t[300];
char in[500];
int pow[] = {0,1,10,100,1000,10000};
void init()
{
	int i,j;
	t[0] = '.';
	for ( i = 0; in[i] != '='; i++ )
		t[i+1] = in[i];
	t[i+1] = NULL;
	i++;
	j = 0;
	while ( in[i] != NULL )
	{
		j *= 10;
		j += in[i]-'0';
		i++;
	}
	m = j;
}
bool run ()
{
	int i,j,k,x;
	len = strlen(t)-1;
	for ( i = 0; i <= m; i++ )
		c[0][i].yes = false;
	c[0][0].yes = true;
	for ( i = 1; i <= len; i++ )
	{
		for ( j = 1; j <= m; j++ )
		{
			c[i][j].yes = false;
			x = 0;
			for ( k = 1; k <= 5 && k <= i; k++ )
			{
				x += pow[k]*(t[i-k+1]-'0');
				if ( j >=x && c[i-k][j-x].yes == true && t[i-k+1] != '0' )
				{
					c[i][j].yes = true;
					c[i][j].pre = i-k;
					c[i][j].data = x;
					break;
				}
			}
		}
	}
	return c[len][m].yes;
}
void print( int i, int j )
{
	int k;
	if (c[i][j].pre!=0)
	{
		print(c[i][j].pre,j-c[i][j].data);
	}
	else
	{
		for ( k = c[i][j].pre+1; k <= i; k++ )
			printf("%c",t[k]);
		return;
	}
	{
		printf("+");
		for ( k = c[i][j].pre+1; k <= i; k++ )
			printf("%c",t[k]);
	}
}
int main ()
{
	int tc= 1;
	while ( scanf(" %s",&in) != EOF )
	{
		if ( strcmp(in,"0=0")==0 )
			return 0;
		printf("%d. ",tc);
		tc++;
		init();
		if ( run()==true )
		{
			print(len,m);
			printf("\n");
		}
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}