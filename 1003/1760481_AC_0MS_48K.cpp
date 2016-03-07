#include<iostream.h>
class node{
public:
	float data;
	node *next;
};

void main(){
	node *head;
	node *end=NULL;
	node *p=NULL;
	head=p;
	float a=1.00;
	float n=2.0;
	float sum=0.0;
	while(a!=0.00){
		cin>>a;
		if(a==0.00)break;
		while(a<0.01||a>5.20)cin>>a;
	n=2.0;
	sum=0.0;
	while(sum<=a)
	{
		sum+=1/n;
		n++;
	}
	n-=2;
	p=new node;
	if(end==NULL)
	{
		head=p;
		end=p;
		p->data=n;
		p->next=NULL;
	}
	else
	{
		end->next=p;
		p->data=n;
		p->next=NULL;
		end=p;
	}
	}
	p=head;
	while(p!=NULL)
	{
		cout<<p->data<<" card(s)"<<endl;
		p=p->next;
	}
}