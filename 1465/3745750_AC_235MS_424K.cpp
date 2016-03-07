#include<iostream>
#include<string>
#include<queue>
using namespace std;
#define inf 2000000000
struct ac
{
	int step;
	string dig;
	int mod;
	ac(){dig="";}
};
queue<ac>que;
bool digUse[10];
int w[5000];
int n,m,flag;
char ans[10000];
void input()
{
	scanf("%d",&m);
	memset(digUse,false,sizeof(digUse));
	int i,x;
	for (i = 0; i < m; i++)
	{
		scanf("%d",&x);
		digUse[x] = true;
	}
	for ( i = 0; i < n; i++ )
		w[i] = inf;
	flag = 0;
}
void solve()
{
	while ( !que.empty())
		que.pop();
	ac p,q;
	int i;
	for ( i = 1; i <= 9; i++ )
	{
		if(digUse[i]==false)
			continue;
		p.mod = i%n;
		p.step = 1;
		p.dig = '0'+i;
		w[i] = 1;
		que.push(p);
	}
	while ( !que.empty() )
	{
		p = que.front();
		que.pop();
		if ( w[p.mod] < p.step )
			continue;
		if ( p.mod == 0 )
		{
			for ( i = 0; i < p.step; i++ )
				ans[i] = p.dig[i];
			ans[i] = NULL;
			flag = 1;
			break;
		}
		for ( i = 0; i < 10; i++ )
		{
			if(digUse[i]==false)
				continue;
			q = p;
			q.step++;
			if ( w[(p.mod*10+i)%n] > q.step )
			{
				w[(p.mod*10+i)%n] = q.step;
				q.dig+=i+'0';
				q.mod = (p.mod*10+i)%n;
				que.push(q);
			}
		}
	}
}
int main ()
{
	while ( scanf("%d",&n) != EOF)
	{
		input();
		if( n == 0 )
		{
			printf("0\n");
			continue;
		}
		solve();
		if(flag==1)
			printf("%s\n",ans);
		else
			printf("0\n");
	}
	return 0;
}