#include <iostream>
using namespace std;
const int inf = 2000000000;
struct ac
{
	int v,len;
	ac *next;
}*list[500];
bool visit[500];
int dis[500];
int n,m,N;
void init ()
{
	int i;
	for ( i = 0; i < N; i++ )
		list[i] = NULL;
}
void insert ( int x, int y, int len )
{
	ac *p = new ac;
	p->len = len;
	p->v = y;
	p->next = list[x];
	list[x] = p;
}
void input ()
{
	int i,j,x,y,z;
	char dir;
	for ( i = 0; i < n-1; i++ )
	{
		for ( j = 0; j < m-1; j++ )
		{
			scanf(" %d %c",&z,&dir);
			z = 2520/z;
			x = i*m+j;
			y = x+1;
			if ( dir == '<' )
				insert(y,x,z);
			else if ( dir == '>' )
				insert(x,y,z);
			else
			{
				insert(x,y,z);
				insert(y,x,z);
			}
		}
		for ( j = 0; j < m; j++ )
		{
			scanf(" %d %c",&z,&dir);
			if ( z == 0 )
				continue;
			z = 2520/z;
			x = i*m+j;
			y = x+m;
			if ( dir == 'v' )
				insert(x,y,z);
			else if ( dir == '^' )
				insert(y,x,z);
			else
			{
				insert(x,y,z);
				insert(y,x,z);
			}
		}
	}
	for ( j = 0; j < m-1; j++ )
	{
		scanf(" %d %c",&z,&dir);
		z = 2520/z;
		x = i*m+j;
		y = x+1;
		if ( dir == '<' )
			insert(y,x,z);
		else if ( dir == '>' )
			insert(x,y,z);
		else
		{
			insert(x,y,z);
			insert(y,x,z);
		}
	}
}
void dij ( )
{
	int i,j,k,tmin;
	ac *p;
	for ( i = 0; i < N; i++ )
	{
		visit[i] = false;
		dis[i] = inf;
	}
	dis[0] = 0;
	for ( i = 0; i < N; i++ )
	{
		tmin = inf;
		for ( j = 0; j < N; j++ )
		{
			if ( !visit[j] && dis[j] < tmin )
			{
				tmin = dis[j];
				k = j;
			}
		}
		if ( tmin == inf )
			break;
		visit[k] = true;
		p = list[k];
		while ( p != NULL )
		{
			if ( !visit[p->v] && dis[p->v] > dis[k]+p->len )
			{
				dis[p->v] = dis[k]+p->len;
			}
			p = p->next;
		}
	}
	if ( dis[N-1] == inf )
		printf("Holiday\n");
	else
		printf("%d blips\n",dis[N-1]);
}
int main ()
{
	while ( scanf("%d %d",&n,&m) != EOF )
	{
		N = (n+1)*(m+1);
		init();
		if ( n == 0 && m == 0 )
			break;
		n++;
		m++;
		input();
		dij();
	}
	return 0;
}