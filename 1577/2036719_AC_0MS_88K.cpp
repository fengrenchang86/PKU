#include <iostream>
using namespace std;
struct ac
{
	char name;
	int left;
	int right;
	int parent;
	ac()
	{
		name = '0';
		left = right = parent = -1;
	}
};
void print( ac node[], int n)
{
	if ( node[n].name != '0' )
		printf("%c",node[n].name);
	if ( node[n].left != -1 )
		print(node,node[n].left);
	if ( node[n].right != -1 )
		print(node,node[n].right);
}
void insert ( ac node[], char ch,int &n)
{
	int i = 1;
	while ( 1 )
	{
		if ( node[i].name > ch )
		{
			if ( node[i].left == -1 )
			{
				node[n].parent = i;
				node[n].name = ch;
				node[i].left = n++;
				return;
			}
			i = node[i].left;
			continue;
		}
		if ( node[i].right == -1 )
		{
			node[n].parent = i;
			node[n].name = ch;
			node[i].right = n++;
			return;
		}
		i = node[i].right;
	}
}
int main ()
{
	char put[30][30];
	ac node[30];
	int i,j=0;
	int k;
	int n = 1;
	while ( scanf("%s",put[j]) )
	{
		if ( put[j][0] == '*' )
		{
			j--;
			node[n++].name = put[j][0];
			j--;
			while ( j >= 0 )
			{
				for ( k = 0; put[j][k] != NULL; k++ )
					insert(node,put[j][k],n);
				j--;
			}
			print(node, 1);
			printf("\n");
			for ( i = 0; i < 30 ; i++ )
			{
				node[i].left = node[i].right = node[i].parent = -1;
				node[i].name = '0';
			}
			n = 1;
			j = 0;
			continue;
		}
		else if ( put[j][0] == '$' )
		{
			j--;
			node[n++].name = put[j][0];
			j--;
			while ( j >= 0 )
			{
				for ( k = 0; put[j][k] != NULL; k++ )
					insert(node,put[j][k],n);
				j--;
			}
			print(node, 1 );
			printf("\n");
			break;
		}
		j++;
	}
	return 1;
}