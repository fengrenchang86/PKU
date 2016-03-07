#include <iostream>
using namespace std;
const int MAXN = 100000;
int *father;
bool visit[MAXN];
int n,m;
int getfather ( int x )
{
	int t;
	if ( father[x] != x )
	{
		t = getfather(father[x]);
		father[x] = t;
	}
	return x;
}
void init ()
{
	int i;
	father = new int[MAXN];
	for ( i = 0; i < MAXN; i++ )
		father[i] = i;
	memset(visit,false,sizeof(visit));
}
int solve ()
{
	int ans = 0,j = 0;
	int i,x,y,z,fx,fy;
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d%d",&z,&x,&y);
		if ( x == y || x > n || y > n )
		{
			ans++;
			continue;
		}
		fx = getfather(x);
		fy = getfather(y);
		if ( z == 1 )//同类
		{
			if ( visit[x] == false && visit[y] == false )//两个都没有访问过
			{
				visit[x] = visit[y] = true;
				father[x] = father[y] = j;
				j+=3;
			}
			else if ( visit[x] == false )
			{
				visit[x] = true;
				father[x] = fy;
			}
			else if ( visit[y] == false )
			{
				visit[y] = true;
				father[y] = fx;
			}
			else
			{
				if ( fx == fy )//已经同类
					continue;
				else if ( fx/3 == fy/3 && fx%3 != fy%3 )//同组不同类
					ans++;
				else
				{
					father[fy] = fx;
					father[fy/3*3+(fy+1)%3] = fx/3*3+(fx+1)%3;
					father[fy/3*3+(fy+2)%3] = fx/3*3+(fx+2)%3;
				}
			}
		}
		else
		{
			if ( visit[x] == false && visit[y] == false )
			{
				visit[x] = visit[y] = true;
				father[x] = j;
				father[y] = j+1;
				j+=3;
			}
			else if ( visit[x] == false )
			{
				visit[x] = true;
				father[x] = fy/3+(fy+1)%3;
			}
			else if ( visit[y] == false )
			{
				visit[y] = true;
				father[y] = fx/3+(fx+2)%3;
			}
			else
			{
				if ( fx/3==fy/3 && (fy+1)%3==fx%3 )
					continue;
				else if ( fx/3 == fy/3 )
					ans++;
				else
				{
					father[fy] = fx/3+(fx+2)%3;
					father[fy/3*3+(fy+1)%3] = fx/3*3+fx%3;
					father[fy/3*3+(fy+2)%3] = fx/3*3+(fx+1)%3;
				}
			}
		}
	}
	return ans;
}
int main ()
{
	while ( scanf("%d%d",&n,&m) != EOF )
	{
		init();
		printf("%d\n",solve());
		delete[] father;
	}
	return 0;
}