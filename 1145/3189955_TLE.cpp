#include <iostream>
using namespace std;
int sum,pk;
char t[500];
bool flag;
struct ac
{
	int val;
	int sum;
	ac *left,*right,*father;
}*head,*p,*q;
void dfs ( ac *p)
{
	if ( p->sum == 0 )
		return;
	else if ( p->val == sum && p->left->sum == 0 && p->right->sum == 0 )
	{
		flag = true;
		return;
	}
	if ( p->left->sum != 0 )
	{
		dfs(p->left);
		if ( flag == true )
			return;
	}
	if ( p->right->sum != 0 )
	{
		dfs(p->right);
	}
}
int main ()
{
	int k,i,x;
	while ( cin>>sum )
	{
		flag = false;
		pk = 0;
		p = head = NULL;
		do
		{
			cin.getline(t,500,'\n');
			for ( i = 0; t[i] != NULL;  )
			{
				while ( t[i] != NULL && t[i] == ' ' )
					i++;
				if ( t[i] == NULL )
					break;
				if ( t[i] == '(' )
				{
					pk--;
					q = new ac;
					q->sum = 0;
					q->father = p;
					if ( p == NULL )
					{
						p = q;
						head = q;
						head->val = 0;
						i++;
						continue;
					}
					q->val = p->val;
					p->sum++;
					if ( p->sum == 1 )
						p->left = q;
					else
						p->right = q;
					p = q;
					i++;
				}
				else if ( t[i] >= '0' && t[i] <= '9' || t[i] == '-' )
				{
					if ( t[i] == '-' )
						x = -1;
					else
						x = 1;
					k = 0;
					while ( t[i] >= '0' && t[i] <= '9' )
					{
						k *= 10;
						k += t[i]-'0';
						i++;
					}
					k *= x;
					p->val += k;
				}
				else
				{
					pk++;
					if ( p->sum == 2 || p->sum == 0 )
						p = p->father;
					i++;
				}
			}
			if ( p == NULL )
				break;
		}while ( pk != 0 );
		flag = false;
		dfs(head);
		if ( flag == false )
			printf("no\n");
		else
			printf("yes\n");
		flag = false;
	}
	return 0;
}