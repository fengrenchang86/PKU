#include <iostream>
using namespace std;
struct ac
{
	int v;
	ac*next;
	ac*back;
}*head;
int n,m,k;
ac* create ( int n )
{
	int i;
	ac *p = new ac;
	p->v = 1;
	head=p;
	ac *tail=p;
	for ( i = 2; i <= n; i++ )
	{
		p = new ac;
		p->v = i;
		p->back = tail;
		tail->next = p;
		tail = p;
	}
	tail->next = head;
	head->back = tail;
	return head;
}
ac* del ( ac*p, int x, int rest )//删除从p开始往下第x个(p算是第一个)
{
	int i;
	ac *q;
	x %= rest;
	if ( x <= rest-x )
	{
		for ( i = 0; i < x; i++ )
			p = p->next;
		p->back->next = p->next;
		p->next->back = p->back;
		q = p->back;
		delete p;
	}
	else
	{
		for ( i = 0; i < rest-x; i++ )
			p = p->back;
		p->back->next = p->next;
		p->next->back = p->back;
		q = p->back;
		delete p;
	}
	return q;
}
int main ()
{
	ac *p,*q;
	while ( scanf("%d%d%d",&n,&k,&m) &&n&&k&&m )
	{
		q = create(n);
		p = del(q,m-1,n);
		n--;
		while ( n > 1 )
		{
			q = del(p,k,n);
			p = q;
			n--;
		}
		printf("%d\n",p->v);
	}
	return 0;
}