#include <iostream>
#include <queue>
using namespace std;
const int inf = 2000000000;
bool prime[11000];
int w[11000];
struct ac
{
	int primNum;
	int step;
};
queue<ac>que;
void make ( )
{
	memset(prime,true,sizeof(prime));
	int i,j;
	for ( i = 2; i <= 5000; i++ )
	{
		if ( prime[i] == false )
			continue;
		for ( j = 2; i*j < 10000; j++ )
			prime[i*j] = false;
	}
}
void init ()
{
	int i;
	for ( i = 1000; i <= 10000; i++ )
		w[i] = inf;
}
int comp ( int x, int y )
{
	int i = 0,j,k;
	for ( k = 1; k <= 1000 ; k*=10 )
	{
		if ( x % 10 != y % 10 )
		{
			i++;
			j = k;
		}
		x/=10;
		y/=10;
	}
	if ( i == 1 )
		return j;
	else
		return -1;
}
void solve ()
{
	int begin,end,i,j;
	scanf("%d%d",&begin,&end);
	if ( prime[end] == false || prime[begin] == false )
	{
		printf("Impossible\n");
		return;
	}
	init();
	while ( !que.empty() )
		que.pop();
	ac p,q;
	p.primNum = begin;
	p.step = 0;
	w[begin] = 0;
	que.push(p);
	while ( !que.empty() )
	{
		p = que.front();
		que.pop();
		if ( w[p.primNum] < p.step )
			continue;
		for ( i = 1; i <= 1000; i*=10 )
		{
			for ( j = 1; j <= 9; j++ )
			{
				q.primNum = p.primNum+i*j;
				q.step = p.step+1;
				if ( j+(p.primNum/i)%10 <= 9 && q.primNum < 10000 && prime[q.primNum] && w[q.primNum] > q.step )
				{
					w[q.primNum] = q.step;
					que.push(q);
				}
				q.primNum = p.primNum-i*j;
				if ( (p.primNum/i)%10 - j < 0 )
					continue;
				if ( q.primNum < 1000 )
					continue;
				if ( prime[q.primNum] && w[q.primNum] > q.step )
				{
					w[q.primNum] = q.step;
					que.push(q);
				}
			}
		}
	}
	if ( w[end] == inf )
		printf("Impossible\n");
	else
		printf("%d\n",w[end]);
}
int main ()
{
	make();
	int tc;
	scanf("%d",&tc);
	while ( tc-- )
		solve();
	return 0;
}