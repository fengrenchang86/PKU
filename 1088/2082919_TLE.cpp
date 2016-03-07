/*
#include <iostream>
using namespace std;
int a[120][120];
int b[120][120];
int t[10003];
int h[10003];
int v[10003][2];
int max = 1;
void bfs ( int x, int y, int lay )
{
	if ( lay > max )
	{
		max = lay;
	}
	if ( lay + h[a[x][y]] <= max )
		return;
	if ( a[x-1][y] < a[x][y]  )
	{
			b[x-1][y] = 1;
			bfs(x-1,y,lay+1);
	}
	if ( a[x][y-1] < a[x][y] )
	{
			b[x][y-1] = 1;
			bfs ( x, y-1 ,lay+1);
	}
	if ( a[x][y+1] < a[x][y] )
	{
			b[x][y+1] = 1;
			bfs ( x, y+1 ,lay+1);
	}
	if ( a[x+1][y] < a[x][y] ) 
	{
			b[x+1][y] = 1;
			bfs ( x+1, y ,lay+1);
	}
}
int main ()
{
	int m,n,i,j,c = 0;
	int k;
	cin>>m>>n;
	memset(t,0,sizeof(t));
	memset(h,0,sizeof(h));
	memset(b,0,sizeof(b));
	for ( i = 1; i <= m; i++ )
		a[i][0] = a[i][n+1] = 10002;
	for ( j = 1; j <= n; j++ )
		a[0][j] = a[m+1][j] = 10002;
	for ( i = 1; i <= m; i++ )
	{
		for ( j = 1;  j<= n; j++ )
		{
			cin>>a[i][j];
			v[c][0] = i;
			v[c][1] = j;
			t[c++] = a[i][j];
		}
	}
	for ( i = 0; i < c-1; i++ )
	{
		for ( j = i+1; j < c; j++ )
		{
			if ( t[i] > t[j] )
			{
				k = t[i];
				t[i] = t[j];
				t[j] = k;
				k = v[i][0];
				v[i][0] = v[j][0];
				v[j][0] = k;
				k = v[i][1];
				v[i][1] = v[j][1];
				v[j][1] = k;
			}
		}
	}
	for ( i = 0; i < c; i++ )
	{
		h[t[i]] = i;
//		printf("%d(%d):  %d\n",i,t[i],h[t[i]]);
	}
	for ( i = m; i >= 1; i-- )
	{
		for ( j = n; j >=1 ; j-- )
		{
			if ( b[i][j] == 0 )
			{
				bfs(i,j,1);
			}
		}
	}
//	for ( i =c-1 ; i >= 0; i-- )
//	{
//		cout<<v[i][0]<<" "<<v[i][1]<<" : "<<a[v[i][0]][v[i][1]]<<endl;
//	}
	for ( i = c-1; i >= 0; i-- )
	{
		if ( b[v[i][0]][v[i][1]] == 0 )
			bfs(v[i][0],v[i][1],1);
	}
	cout<<max<<endl;
	return 0;
}*/

#include <iostream>
using namespace std;
struct ac
{
	int path;
	int high;
	ac(){path=0;}
}a[102][102];
int m,n;
int max = 1;
void dfs ( int x, int y, int lay )
{
	if ( lay > max )
		max = lay;
	{
		if ( a[x][y].high > a[x-1][y].high  )
		{
			if ( lay+1 > a[x-1][y].path )
			{
				a[x-1][y].path = lay+1;
				dfs(x-1,y,lay+1);
			}
		}
	}
	{
		if ( a[x][y].high > a[x][y+1].high  )
		{
			if ( lay+1 > a[x][y+1].path )
			{
				a[x][y+1].path = lay+1;
				dfs(x,y+1,lay+1);
			}
		}
	}
	{
		if ( a[x][y].high > a[x+1][y].high  )
		{
			if ( lay+1 > a[x+1][y].path )
			{
				a[x+1][y].path = lay+1;
				dfs(x+1,y,lay+1);
			}
		}
	}
	{
		if ( a[x][y].high > a[x][y-1].high  )
		{
			if ( lay+1 > a[x][y-1].path )
			{
				a[x][y-1].path = lay+1;
				dfs(x,y-1,lay+1);
			}
		}
	}
}
int main ()
{
	int ex,ey;
	int i,j;
	int c;
	scanf("%d%d",&m,&n);
	for ( i = 0; i <= n+1; i++ )
		a[0][i].high = a[m+1][i].high = 20000;
	for ( i = 0; i <= m+1; i++ )
		a[i][0].high = a[i][n+1].high = 20000;
	for ( i = 1; i <= m; i++ )
		for ( j = 1; j <= n; j++ )
		{
			scanf("%d",&a[i][j].high);
		}
	while ( 1 )
	{
		c = -1;
		for ( i = 1; i <= m; i++ )
		{
			for ( j = 1; j <= n; j++ )
			{
				if ( a[i][j].path == 0 && a[i][j].high > c)
				{
					c = a[i][j].high;
					ex = i;
					ey = j;
				}
			}
		}
		if ( c == -1 )
			break;
		a[ex][ey].path = 1;
		dfs(ex,ey,1);
	}
	cout<<max<<endl;
	return 0;
}

