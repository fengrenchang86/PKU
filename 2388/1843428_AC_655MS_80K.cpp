#include <iostream.h>
/*
class node 
{
public:
	int data;
	node *next;
	node(){data=0; next= NULL;}
};

class chang
{
public:
	node *head;
	void insert( int k );
};

void chang::insert( int k)
{
	node *p = new node;
	if ( head == NULL )
		head = p;
	else
	{
		if ( head->data > k )
		{
			p->next = head;
			head = p;
		}
		else
			while ( p!=NULL)
			{
				if ( p->next->
	}
}
*/
void main ()
{
	int n;
	cin>>n;
	int *a = new int[n];
	int i;
	for ( i = 0; i < n; i++ )
		cin>>a[i];
	int j;
	int k;
	for ( i = 0; i < n-1; i++ )
	{
		for ( j= i+1; j < n; j++ )
		{
			if ( a[i]<a[j] )
			{
				k = a[i];
				a[i] = a[j];
				a[j] = k;
			}
		}
	}
	cout<<a[n/2]<<endl;
}