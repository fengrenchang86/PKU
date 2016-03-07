#include <iostream>
#include <fstream.h>
#include <string>
using namespace std;
struct ac
{
	char name[32];
	ac *left,*right;
	int count;
	ac(){left=right=NULL;count=1;}
}*head;
void insert ( ac* node, char *t )
{
	int j = strcmp(node->name,t);
	if ( j == 0 )
		node->count++;
	else if ( j > 0 )
	{
		if ( node->left == NULL )
		{
			ac *p = new ac;
			strcpy(p->name,t);
			node->left = p;
		}
		else
			insert(node->left,t);
	}
	else
	{
		if( node->right == NULL )
		{
			ac *p = new ac;
			strcpy(p->name,t);
			node->right = p;
		}
		else
			insert(node->right,t);
	}
}
int n = 0;
void print ( ac *node )
{
	if ( node->left != NULL )
		print(node->left);
	printf("%s %.4lf\n",node->name,double(node->count)/double(n)*100.0);
	if ( node->right != NULL )
		print(node->right);
}
int main ()
{
	head = NULL;
	char t[32];
	while ( gets(t) )
	{
		if ( head == NULL )
		{
			head = new ac;
			strcpy(head->name,t);
		}
		else
			insert(head,t);
		n++;
	}
	print(head);
	return 0;
}