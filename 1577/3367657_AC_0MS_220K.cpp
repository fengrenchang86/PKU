#include <iostream>
using namespace std;
struct tree
{
	int left,right;
	char date;
}t[30];
void init ()
{
	int i;
	for ( i = 0; i < 30; i++ )
	{
		t[i].left = t[i].right = -1;
	}
}
char input[30][30];
void print ( int node )
{
	printf("%c",t[node].date);
	if ( t[node].left != -1 )
		print(t[node].left);
	if ( t[node].right != -1 )
		print(t[node].right);
}
void solve ( int n )
{
	n--;
	int i,j,k=0,p;
	t[0].date = input[n][0];
	t[0].left = t[0].right = -1;
	for ( i = n-1; i >= 0; i-- )
	{
		for ( j = 0; input[i][j] != NULL; j++ )
		{
			p = 0;
			while ( 1 )
			{
				if ( input[i][j] < t[p].date )
				{
					if ( t[p].left != -1 )
						p = t[p].left;
					else
					{
						t[p].left = ++k;
						t[k].date = input[i][j];
						t[k].left = t[k].right = -1;
						break;
					}
				}
				else
				{
					if ( t[p].right != -1 )
						p = t[p].right;
					else
					{
						t[p].right = ++k;
						t[k].date = input[i][j];
						t[k].left = t[k].right = -1;
						break;
					}
				}
			}
		}
	}
	print(0);
	printf("\n");
}

int main ()
{
	int n=0;
	while ( cin>>input[n] )
	{
		if ( input[n][0] == '$' )
		{
			solve(n);
			break;
		}
		else if ( input[n][0] == '*' )
		{
			solve(n);
			n = 0;
		}
		else
			n++;
	}
	return 0;
}