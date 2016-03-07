#include <iostream>
using namespace std;
char c[50][50];
bool visit[50];
struct ac
{
short max,n;
short number;
short begin,end;
}ok;
int main ()
{
	void dfs(short,short,short);
	short r,i,j,k,t;
	ok.begin = -1;
	scanf("%d%d",&ok.n,&r);
	for ( i = 1; i <= ok.n; i++ )
	{
		for ( j = 1; j <= ok.n; j++ )
			scanf("%d",&c[i][j]);
		visit[i] = true;
	}
	k = 0;
	cin.ignore();
	while(cin.peek()!=EOF )
	{
		if(isdigit(cin.peek()))
		{
			cin>>t;
			if ( ok.begin == -1 )
				ok.begin = t;
			visit[t] = false;
			k++;
		}
		if(cin.peek()=='\n')
		{
			r--;
			ok.end = t;
			ok.number = k;
			ok.max = 20000;
			visit[ok.begin] =true;
			dfs(ok.begin,1,0);
			if ( ok.max == 20000 )
				cout<<0<<endl;
			else
				cout<<ok.max<<endl;
			if ( r == 0 )
				break;
			for ( k = 0; k <= ok.n; k++ )
				visit[k] = 1;
			k = 0;
			ok.begin = -1;
		}
		cin.ignore();
	}		
	return 0;
}
void dfs ( short v, short count, short path )
{
	if ( v == ok.end )
	{
		if ( count < ok.number )
			return;
		if ( path < ok.max )
			ok.max = path;
		return;
	}
	if ( path + ok.number - count >= ok.max )
		return;
	short i;
	for ( i = 1; i <= ok.n; i++ )
	{
		if ( c[v][i] != 0 && visit[i] == false  )
		{
			visit[i] = true;
			dfs(i,count+1,path+c[v][i]);
			visit[i] = false;
		}
	}
}