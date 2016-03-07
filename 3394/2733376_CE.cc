#include <iostream>
using namespace std;
int c[101][101];
int visit[101];
int max,n;
int number;
int begin,end;

int main ()
{
	void dfs(int,int,int);
	int r,i,j,k,t;
	begin = -1;
	cin>>n>>r;
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= n; j++ )
			scanf("%d",&c[i][j]);
		visit[i] = 1;
	}
	k = 0;
	cin.ignore();
	while(cin.peek()!=EOF )
	{
		if(isdigit(cin.peek()))
		{
			cin>>t;
			if ( begin == -1 )
				begin = t;
			visit[t] = 2;
			k++;
		}
		if(cin.peek()=='\n')
		{
			r--;
			end = t;
			number = k;
			max = 2000000000;
			visit[begin] *= -1;
			dfs(begin,1,0);
			if ( max == 2000000000 )
				cout<<0<<endl;
			else
				cout<<max<<endl;
			if ( r == 0 )
				break;
			for ( k = 0; k <= n; k++ )
				visit[i] = 1;
			k = 0;
			begin = -1;
		}
		cin.ignore();
	}		
	return 0;
}
void dfs ( int v, int count, int path )
{
	if ( v == end )
	{
		if ( count < number )
			return;
		if ( path < max )
			max = path;
		return;
	}
	int i;
	for ( i = 1; i <= n; i++ )
	{
		if ( c[v][i] != 0 && visit[i] > 0 )
		{
			if ( visit[i] == 2 )
			{
				visit[i] *= -1;
				dfs(i,count+1,path+c[v][i]);
				visit[i] *= -1;
			}
			else
			{
				visit[i] *= -1;
				dfs(i,count,path+c[v][i]);
				visit[i] *= -1;
			}
		}
	}
}