#include <iostream.h>
#include <math.h>
#include <iomanip.h>
class node
{
public:
	double data;
	node *next;
	node *back;
	node (){next= NULL; back = NULL; }
};
class chang
{
public:
	node *end;
	node *head;
	chang () {end = NULL; head = NULL; }
	void insert ( double k);
	void print ( );
	void oper ( );
	void clear ( );
};
void chang::clear ()
{
	end = NULL;
	head = NULL; 
}
void chang::print ( )
{
	int i;
	int k;
	int j;
	int sum;
	sum = head->data * 10000;
	k =sum - sum / 10 * 10;
	if ( k >= 5 )
		i = 1;
	else 
		i = 0;
	j = sum / 10 + i;
	cout<<j/1000<<'.';
	j = j - j/1000*1000;
	cout<<setw(3)<<setfill('0')<<j<<endl;


	
}
void chang::insert (double k )
{
	node *temp = new node;
	node *p = head;
	if ( head == NULL )
	{
		head = temp;
		end = temp;
		head->next = NULL;
		temp->back = temp;             
		temp->data = k;
	}
	else
	{
		if ( p->data < k )
		{
			temp->next = head;
			temp->back = end;
			temp->next->back = temp;
			head = temp;
			temp->data = k;
		}
		else
		{
		while ( p!= NULL )
		{
			if ( p->data < k )
			{
				temp->next = p;
				p->back->next = temp;
				temp->back = p->back;
				p->back = temp;
				temp->data = k;
				break;
			}
			p = p ->next;
		}
		if ( p == NULL )
		{
			head->back->next = temp;
			temp->back = head->back;
			head->back = temp;
			temp->next = NULL;
			temp->data = k;
			end = temp;
		}
		}
	}
}

void chang::oper ( )
{
	double temp;
	node *p = head;
	node *q = head->next;
	head = q->next;
	while ( head != NULL )
	{
		head->back = end;
		temp = 2 * sqrt (p->data*q->data);
		chang::insert(temp);
		p = head;
		q = head->next;
		head = q ->next;
	}
	temp = 2 * sqrt ( p->data * q->data );
	chang::insert( temp );
}
void main ()
{
	chang a;
	int n;
	int i;
	int in[30];
	while ( 1 )
	{
		cin>>n;
		if ( n == 0 )
			break;
		for ( i = 0; i < n; i++ )
		{
			cin>>in[i];
		}
		for ( i = 0; i < n; i++ )
			a.insert ( in[i] );
		a.oper ( );
		a.print ( );
		a.clear ( );
	}
}