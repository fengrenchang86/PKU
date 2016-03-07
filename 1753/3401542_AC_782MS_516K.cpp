#include <iostream>
#include <queue>
using namespace std;
const int inf = 2147483647;
int w[70000];
int power[20];
int p[20];
int v[5][5];
char b[5][5];
struct ac
{
	int con;
	int step;
};
queue<ac>que;
void init ()
{
	int i;
	power[0] = 1;
	for ( i = 1; i < 20; i++ )
		power[i] = power[i-1]*2;
}
int flip ( int n, int k )
{
	int i,j=n;
	for ( i = 16; i >= 0; i-- )
	{
		p[i] = j/power[i];
		j %= power[i];
	}
	int x = k/4;
	int y = k%4;
	p[k] = !p[k];
	if ( x > 0 )
		p[k-4] = !p[k-4];
	if ( x < 3 )
		p[k+4] = !p[k+4];
	if ( y > 0 )
		p[k-1] = !p[k-1];
	if ( y < 3 )
		p[k+1] = !p[k+1];
	k = 0;
	for ( i = 0; i < 16; i++ )
		k += power[i]*p[i];
	return k;
}
void solve ()
{
	while ( !que.empty() )
		que.pop();
	ac p,q;
	int i,k;
	for ( i = 0; i <= 65536; i++ )
		w[i] = inf;
	w[0] = w[65535] = 0;
	p.con = 0;
	p.step = 0;
	que.push(p);
	p.con = 65535;
	que.push(p);
	while ( !que.empty() )
	{
		p = que.front();
		que.pop();
		if ( w[p.con] < p.step )
			continue;
		for ( i = 0; i < 16; i++ )
		{
			k = flip(p.con,i);
			if ( w[k] > p.step+1 )
			{
				q.con = k;
				q.step = p.step+1;
				w[k] = q.step;
				que.push(q);
			}
		}
	}
}
int main ()
{
	init();
	solve();
	int tcase;
//	scanf("%d",&tcase);
	int i,j,k;
//	while (tcase-- )
	{
		for ( i = 0; i < 4; i++ )
			scanf("%s",&b[i]);
		k = 0;
		for ( i = 0; i < 4; i++ )
		{
			for ( j = 0; j < 4; j++ )
			{
				if ( b[i][j] == 'b' )
					k += power[4*i+j];
			}
		}
		if ( w[k] == inf )
			printf("Impossible\n");
		else
			printf("%d\n",w[k]);
//		if ( tcase != 0 )
//			printf("\n");
	}
	return 0;
}