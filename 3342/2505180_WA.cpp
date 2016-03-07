#include <iostream>
#include <string>
using namespace std;
struct wf
{
	char name[120];
	wf *next;
}list[300];
int a[300],queen[300];
bool visit[300];
int end;
bool unique;
void insert ( char *a, char *b )
{
	int i;
	for ( i = 0; i < end; i++ )
	{
		if (strcmp(b,list[i].name)==0)
			break;
	}
	if ( i == end )
	{
		strcpy(list[end].name,b);
		end++;
	}
	wf *p = new wf;
	strcpy(p->name,a);
	p->next = list[i].next;
	list[i].next = p;
}
int max;
int count;
void init()
{
	memset(a,0,sizeof(a));
	end = 0;
	max = 0;
	unique = true;
	for ( int i = 0; i < 300; i++ )
	{
		list[i].next = NULL;
		visit[i] = false;
	}
}
int find ( char *a )
{
	int i;
	for ( i = 0; i < end; i++ )
	{
		if ( strcmp(a,list[i].name) ==0 )
			break;
	}
	return i;
}
void dfs ( int node, int &x, int &y )
{
	visit[node] = true;
	int t,tx=0,ty=0;
	x = 0;
	y = 1;
	wf *p = list[node].next;
	while ( p != NULL )
	{
		t = find(p->name);
		if ( visit[t] == true )
		{
			p = p->next;
			continue;
		}
		dfs(t,tx,ty);
		if ( x == 0 )
		{
			if ( x + tx>ty?tx:ty > max )
			{
				max = x+tx>ty?tx:ty;
				unique = true;
			}
		}
		x += tx>ty?tx:ty;
		if ( x > max )
		{
			max = x;
			unique = true;
		}
		y += tx;
		p = p->next;
		if ( y > max )
		{
			max = y;
			unique = true;
		}
		else if ( y == max )
			unique = false;
	}
	if ( y < 1 )
		y = 1;
}
int main ()
{
 	int n,i,x,y;
	char boss[120];
	char cha[120],chb[120];
	while ( cin>>n && n!=0 )
	{
		cin>>boss;
		init();
		x = 0;
		y = 0;
		for ( i = 0; i < n-1; i++ )
		{
			cin>>cha>>chb;
			insert(cha,chb);
			insert(chb,cha);
		}
		dfs(find(boss),x,y);
		cout<<max<<" ";
		if ( unique == true )
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}