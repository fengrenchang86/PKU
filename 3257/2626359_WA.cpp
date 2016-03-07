#include <iostream>
using namespace std;
struct node
{
	int begin;
	int fun;
	int cost;
	node *next;
}*list[1010];
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
	int t[1010][1010];
	int L,N,B,i,j;
	int x,w,f,c;
	node *p;
	for ( i = 0; i <= 1001; i++ )
	{
		t[i][0] = t[0][i] = 0;
		list[i] = NULL;
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
			p = list[i];
			while ( p != NULL )
			{
				if ( j-p->cost >= 0 && t[i][j] < t[p->begin][j-p->cost]+p->fun)
					t[i][j] = t[p->begin][j-p->cost]+p->fun;
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