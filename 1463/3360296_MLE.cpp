#include <iostream>
using namespace std;
const int inf = 2000000000;
struct ac
{
	int x,y,z;
};
struct node
{
	int v;
	node *next;
}*list[1600];
bool visit[1600];
int n;
void init ()
{
	int i;
	for ( i = 0; i < n; i++ )
	{
		visit[i] = false;
		list[i] = NULL;
	}
}
void insert ( int begin ,int end )
{
	node *p = new node;
	p->v = end;
	p->next = list[begin];
	list[begin] = p;
}
void input ()
{
	int id,k,i,j,end;
	for ( i = 0; i < n; i++ )
	{
		scanf("%d:(%d)",&id,&k);
		for ( j = 0; j < k; j++ )
		{
			scanf("%d",&end);
			insert(id,end);
			insert(end,id);
		}
	}
}
int tmin ( int x, int y )
{
	return x<y?x:y;
}
int dfs ( int v, ac &f )
{
	visit[v] = true;
	ac *temp = new ac[n];
	int i=0,t=inf,k,sy=0,sx=inf;
	node *p = list[v];
	while ( p != NULL )
	{
		if ( visit[p->v] == false )
		{
			k = dfs(p->v,temp[i]);
			sy += temp[i].y;
			sx = tmin(tmin(tmin(temp[i].x,temp[i].y)+1,temp[i].z+1),sx);
			i++;
			if ( k < t )
				t = k;
		}
		p = p->next;
	}
	if ( t == inf )
	{
		f.x = 1;
		f.y = 0;
		f.z = inf;
		delete[] temp;
		return 1;
	}
	else if ( t == 1 )
	{
		f.x = f.y = 1;
		f.z = inf;
		delete[] temp;
		return 2;
	}
	else
	{
		f.x = sx;
		f.z = sy;
		f.y = inf;
		i--;
		while ( i >= 0 )
		{
			f.y = tmin(f.y,f.z-temp[i].y+temp[i].x);
			i--;
		}
		delete[] temp;
		return t+1;
	}
}
int main ()
{
	ac p;
	while ( scanf("%d",&n) != EOF )
	{
		init();
		input();
		dfs(0,p);
		printf("%d\n",tmin(p.x,p.y));
	}
	return 0;
}