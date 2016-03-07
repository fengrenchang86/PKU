#include <iostream>
#include <string>
using namespace std;
struct wf
{
	char name[120];
	wf *next;
}list[300];
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
void dfs ( int node, int &x, int &y, int &wx, int &wy )
{
	visit[node] = true;
	int t,tx=0,ty=0;
	int unix,uniy;
	x = 0;
	y = 1;
	wx = wy = 0;
	wf *p = list[node].next;
	while ( p != NULL )
	{
		t = find(p->name);
		if ( visit[t] == true )
		{
			p = p->next;
			continue;
		}
		dfs(t,tx,ty,unix,uniy);
		if ( tx == ty )
			wx = 1;
		if ( tx > ty && unix == 1 )
			wx = 1;
		else if ( ty > tx && uniy == 1 )
			wy = 1;
		if ( unix == 1 )
			wy = 1;
		if ( x == 0 )
		{
			if ( x + tx>ty?tx:ty > max )
				max = x+tx>ty?tx:ty;
		}
		x += tx>ty?tx:ty;
		if ( x > max )
			max = x;
		y += tx;
		p = p->next;
		if ( y > max )
			max = y;
	}
	if ( y < 1 )
	{
		y = 1;
		wx = 0;
		wy = 0;
	}
}
int main ()
{
 	int n,i,x,y,wx,wy;
	char boss[120];
	char cha[120],chb[120];
	while ( cin>>n && n!=0 )
	{
		cin>>boss;
		if ( n == 1 )
		{
			cout<<"1 Yes"<<endl;
			continue;
		}
		init();
		x = 0;
		y = 0;
		for ( i = 0; i < n-1; i++ )
		{
			cin>>cha>>chb;
		//	insert(cha,chb);
			insert(chb,cha);
		}
		dfs(find(boss),x,y,wx,wy);
		cout<<max<<" ";
//		cout<<wx<<" "<<wy<<" ";
		if ( x == y )
			cout<<"No"<<endl;
		else if ( x > y && wx == 1 )
			cout<<"No"<<endl;
		else if ( x < y && wy == 1 )
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
	return 0;
}