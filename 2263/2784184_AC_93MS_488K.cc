#include <iostream>
#include <string>
using namespace std;
int c[220][220];
int w[220],s[220];
bool visit[220];
char name[220][40];
int n,end;
int main ()
{
	int find(char*);
	int dij(int,int);
	int m,i,len,x,y,tc=1;
	char from[40],to[40];
	while ( cin>>n>>m && !(m==0&&n==0))
	{
		end = 0;
		memset(c,-1,sizeof(c));
		for ( i = 0; i < m; i++ )
		{
			cin>>from>>to>>len;
			x = find(from);
			if ( x == -1 )
			{
				strcpy(name[end],from);
				x = end;
				end++;
			}
			y = find(to);
			if ( y == -1 )
			{
				strcpy(name[end],to);
				y = end;
				end++;
			}
			if( c[x][y] < len )
				c[x][y] = c[y][x] = len;
		}
		cin>>from>>to;
		x = find(from);
		y = find(to);
		x = dij(x,y);
		printf("Scenario #%d\n",tc++);
		printf("%d tons\n\n",x);
	}
	return 0;
}
int find ( char* a )
{
	int i;
	for ( i =0 ;i<end; i++ )
	{
		if ( strcmp(name[i],a)==0 )
			return i;
	}
	return -1;
}
int fmin ( int x, int y )
{
	return x<y?x:y;
}
int dij ( int begin, int end )
{
	int i,j,k,min;
	memset(visit,false,sizeof(visit));
	for ( i =0 ; i < 200; i++ )
	{
		w[i] = 2000000000;
		s[i] = 0;
	}
	s[begin] = 2000000000;
	w[begin] = 0;
	for ( i = 0; i < n; i++ )
	{
		min = 2000000000;
		for ( j = 0; j < n; j++ )
		{
			if ( visit[j] == false && w[j] < min )
			{
				min = w[j];
				k = j;
			}
		}
		visit[k] = true;
		for ( j = 0; j < n; j++ )
		{
			if ( visit[j] == false && w[j] > w[k]+1&& c[j][k] != -1 )
			{
				w[j] = w[k]+1;
				if ( s[j] < fmin(s[k],c[j][k]) )
					s[j] = fmin(s[k],c[j][k]);
			}
			else if ( c[j][k] != -1 )
			{
				if ( s[j] < fmin(s[k],c[j][k]) )
					s[j] = fmin(s[k],c[j][k]);
			}
		}
	}
	return s[end];
}
