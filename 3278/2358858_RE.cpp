#include <iostream>
using namespace std;
int w[100500];
struct node
{
	int v;
	node *next;
	node(){next=NULL;}
}*head,*tail;
void insert ( int key )
{
	node *t = new node;
	tail->next = t;
	t->v = key;
	tail = t;
	if ( head == NULL )
		head = tail;
}
int del ()
{
	int t = head->v;
	node *p = head;
	head = head->next;
//	delete p;
	return t;
}
int bfs ( int x, int y )
{
	if ( x == y )
		return 0;
	int i,begin,end;
	for ( i = 0; i <= 100100; i++ )
		w[i] = 1000000;
	end = 1;
	begin = 0;
	node *p = new node;
	head = p;
	tail = p;
	p->v = x;
	w[x] = 0;
	while ( head != NULL )
	{
		i = del();
		if ( i*2 == y || i+1 == y || i-1 == y )
			return w[i]+1;
		if ( w[i]+1 < w[i*2] )
		{
			w[i*2] = w[i]+1;
			insert(i*2);
		}
		if ( w[i]+1 < w[i+1] )
		{
			w[i+1] = w[i]+1;
			insert(i+1);
		}
		if ( w[i]+1 < w[i-1] )
		{
			w[i-1] = w[i]+1;
			insert(i-1);
		}
	}
	return 0;
}
int main ()
{
	int a,b;
	cin>>a>>b;
		cout<<bfs(a,b)<<endl;
	return 0;
}