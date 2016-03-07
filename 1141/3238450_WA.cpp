#include <iostream>
using namespace std;
class node
{
public:
	node *back,*next;
	bool sure;
	char ch;
	node();
}*tail;
node::node()
{
	back = NULL;
	next = NULL;
	sure = false;
}
char a[1000];
node* cFind ( node *p )
{
	node *temp;
	if ( p == NULL )
		return p;
	temp = p->back;
	char t;
	if ( p->ch == ')' )
		t = '(';
	else
		t = '[';
	while ( temp != NULL )
	{
		if ( temp->ch == t && temp->sure == false )
			return temp;
		temp = temp->back;
	}
	return NULL;
}
void insertBefore ( node *p )
{
	node *t = new node;
	if ( p->ch == ')' )
		t->ch = '(';
	else
		t->ch = '[';
	t->next = p;
	if ( p->back != NULL )
	{
		p->back->next = t;
		t->back = p->back;
		t->next = p;
		p->back = t;
	}
	else
	{
		t->next = p;
		p->back = t;
		t->back = NULL;
	}
	p->sure = true;
	t->sure = true;
}
void insertAfter ( node *p )//p是'('或者'['，在后面插入')'或者']'
{
	p->sure = true;
	node *temp = new node;
	if ( p->ch == '(' )
		temp->ch = ')';
	else
		temp->ch = ']';
	temp ->sure = true;
	if ( p->next != NULL )
	{
		temp->next = p->next;
		temp->back = p->next->back;
		p->next->back = temp;
		p->next = temp;
	}
	else
	{
		temp->next = NULL;
		p->next = temp;
		temp->back = p;
	}
}
void init ()
{
	if ( a[0] == NULL )
	{
		cout<<endl;
		return;
	}
	node *p;
	int i;
	p = new node;
	p->ch = a[0];
	p->next = p->back = NULL;
	p->sure = false;
	tail = p;
	node *head = p;
	for ( i = 1; a[i] != NULL; i++ )
	{
		p = new node;
		p->ch = a[i];
		p->back = tail;
		tail->next = p;
		tail = p;
	}
	tail->next = NULL;
	p = head;
	node *q;
	while ( p != NULL )
	{
		if ( p->ch == '(' || p->ch == '[' )
			p = p->next;
		else
		{
			q = cFind(p);
			if ( q == NULL )
				insertBefore(p);
			else
			{
				p->sure = true;
				q->sure = true;
				q = q->next;
				while ( q != p )
				{
					if ( q->sure == false )
					{
						if ( q->ch == '(' || q->ch == '[' )
							insertAfter(q);
						else
							insertBefore(q);
					}
					q = q->next;
				}
			}
			p = p->next;
		}
	}
	p = head;
	while ( p != NULL )
	{
		if ( p->sure == false )
		{
			if ( p->ch == '(' || p->ch == '[' )
				insertAfter(p);
			else
				insertBefore(p);
		}
		p = p->next;
	}
	p = head;
	while ( p != NULL )
	{
		cout<<p->ch;
		p = p->next;
	}
	cout<<endl;
}
void run ()
{
}
int main ()
{
	while ( cin.getline(a,1000,'\n') )
		init();
	return 0;
}