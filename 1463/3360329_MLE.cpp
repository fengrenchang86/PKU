#include <iostream>
using namespace std;
const int inf = 2000000000;
struct ac
{
	int x,y;
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
	int i=0,t=inf,k=0,sy=0,sx=0;
	node *p = list[v];
	while ( p != NULL )
	{
		if ( visit[p->v] == false )
			k++;
		p = p->next;
	}
	ac *temp = new ac[k];
	p = list[v];
	while ( p != NULL )
	{
		if ( visit[p->v] == false )
		{
			k = dfs(p->v,temp[i]);
			sy += temp[i].x;
			sx += tmin(temp[i].x,temp[i].y);
			i++;
			if ( k < t )
				t = k;
		}
		p = p->next;
	}
	delete[] temp;
	if ( t == inf )
	{
		f.x = 1;
		f.y = 0;
		return 1;
	}
	else if ( t == 1 )
	{
		f.x = f.y = 1;
		return 2;
	}
	else
	{
		f.x = sx+1;
		f.y = sy;
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