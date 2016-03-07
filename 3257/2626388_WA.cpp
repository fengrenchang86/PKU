#include <iostream>
using namespace std;
const int MAX = 100;
struct node
{
	int begin;
	int fun;
	int cost;
	node *next;
}*list[MAX+10];
int end = 0;
void insert ( int x, int w, int f, int c )
{
	node *p = new node;
	p->begin = x;
	p->cost = c;
	p->fun = f;
	p->next = list[x+w];
	list[x+w] = p;
}
int main ()
{
	int t[MAX+10][MAX+10];
	bool ok[MAX+10][MAX+10];
	int L,N,B,i,j;
	int x,w,f,c;
	node *p;
	for ( i = 0; i <= MAX; i++ )
	{
		t[i][0] = t[0][i] = 0;
		list[i] = NULL;
		ok[0][i] = true;
		ok[i][0] = false;
	}
	scanf("%d%d%d",&L,&N,&B);
	for ( i = 0; i < N; i++ )
	{
		scanf("%d%d%d%d",&x,&w,&f,&c);
		insert(x,w,f,c);
	}
	w = 0;
	for ( i = 1; i <= L; i++ )
	{
		for ( j = 1; j <= B; j++ )
		{
			t[i][j] = t[i][j-1];
			ok[i][j] = ok[i][j-1];
			p = list[i];
			while ( p != NULL )
			{
				if ( j-p->cost >= 0 && t[i][j] < t[p->begin][j-p->cost]+p->fun && ok[p->begin][j-p->cost] == true)
				{
					t[i][j] = t[p->begin][j-p->cost]+p->fun;
					ok[i][j] = true;
				}
				p = p->next;
			}
		}
	}
	w = t[L][B];
	if ( w == 0 )
		w = -1;
	cout<<w<<endl;
	return 0;
}