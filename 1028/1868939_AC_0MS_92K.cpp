#include <iostream.h>
struct s_node 
{
	char ch[200];
	s_node *next;
	s_node *back;
	s_node ( ){
		next = NULL;
		back = NULL;
	}
};
s_node *head = NULL;
s_node *end = NULL;
void fuzhi ( int begin, s_node *p, char *k )
{
	int i;
	int c = 0;
	for ( i = begin; k[c] != NULL; c++,i++ )
	{
		p->ch[c] = k[i];
	}
}
s_node *insert ( int begin, s_node *p, char *k )
{
	s_node *t;
	t = new s_node;
	if ( p == NULL )
	{
		head = t;
		t->next = NULL;
	}
	else
	{
		t->back = p;
		t->next = p->next;
		p->next = t;
		if ( t->next != NULL )
			t->next->back = t;
	}
	end = t;
	fuzhi ( begin, t, k );
	return t;
}
void print ( s_node *p )
{
	int i;
	for ( i = 0; p->ch[i] != NULL; i++ )
		cout<<p->ch[i];
	cout<<endl;
}

void main ()
{
	char input[100];
	s_node *point = head;
	s_node *q = point;
	head = new s_node;
	head->back = NULL;
	head->next = NULL;
	end = head;
	char cha[30] = "http://www.acm.org/";
	fuzhi ( 0,head,cha);
	head->ch[19] = NULL;
	point = head;
	while ( cin.getline(input,100,'\n') && input[0] != 'Q')
	{
		if ( input[0] == 'V' )
		{
			q = point;
			point = insert(6,point,input);
			print (point);
		}
		else if ( input[0] == 'B' )
		{
			if ( point == NULL || point == head )
				cout<<"Ignored"<<endl;
			else
			{
				point = point->back;
				print (point);
			}
		}
		else if ( input[0] == 'F' )
		{
			if ( point->next == NULL || point == end)
				cout<<"Ignored"<<endl;
			else
			{
				point = point->next;
				print ( point );
			}
		}
	}
	
}