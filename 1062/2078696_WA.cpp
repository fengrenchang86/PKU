#include <iostream>
using namespace std;
int min;
int v[120];
int mon[120];
struct node 
{
	int money;
	int changeObj;
	node *next;
	node(){next = NULL;}
}*list[120];

void insert ( int money, int objNum, int fromObj )
{
	node *temp = new node;
	temp->money = money;
	temp->changeObj = objNum;
	if ( list[fromObj] == NULL )
		list[fromObj] = temp;
	else
	{
		temp->next = list[fromObj];
		list[fromObj] = temp;
	}
}
void dfs ( int num, int curMoney)
{
	node *p = list[num];
	while ( p != NULL )
	{
		if ( v[p->changeObj] == 0 )
		{
			v[p->changeObj] = 1;
			if ( curMoney + p->money + mon[p->changeObj] < min )
				min = curMoney + p->money+ mon[p->changeObj];
			dfs ( p->changeObj, curMoney+p->money);
			v[p->changeObj] = 0;
		}
		p = p->next;
	}
}
int main ()
{
	int m,n,i,j,g;
	int p,l,x;
	int L;
	memset( list,NULL,sizeof(list));//小弟我第一次用！
	memset( v, 0, sizeof(v));
	memset( mon, 0, sizeof(mon));
	scanf("%d%d",&m,&n);
	scanf("%d%d%d",&min,&L,&x);
	mon[1] = min;
	for ( j = 1; j <= x; j++ )
	{
		scanf("%d%d",&g,&p);
		insert(p,g,1);
	}
	for ( i = 2; i <= n; i++ )
	{
		scanf("%d%d%d",&p,&l,&x);
		mon[i] = p;
//		insert(p,0,i);
		for ( j = 1; j <= x; j++ )
		{
			scanf("%d%d",&g,&p);
			if ( abs(L-l)<=m )
				insert(p,g,i);
		}
	}
	dfs(1,0);
	cout<<min<<endl;
	return 0;
}