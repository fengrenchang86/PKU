#include <iostream>
using namespace std;
struct ac
{
	int x,y,len;
}a[10010];
int c[2100][2100];
int root[2100];
int find ( int a )
{
	while ( root[a] != a )
		a = root[a];
	return a;
}
void join ( int a, int b )
{
	root[find(a)] = find(b);
}
void SmallHeapInsert ( int& CurrentSize, ac x )
{
	int i = CurrentSize;
	while ( i > 1 )
	{
		if ( a[i/2].len > x.len )
		{
			a[i] = a[i/2];
			i /= 2;
		}
		else
			break;
	}
	a[i] = x;
	CurrentSize++;
}
void SmallDel ( int& CurrentSize )
{
	CurrentSize--;
	ac item = a[CurrentSize];
	int i = 2;
	while ( i <= CurrentSize )
	{
		if ( i < CurrentSize && a[i].len > a[i+1].len )
			i++;
		if ( item.len <= a[i].len )
			break;
		a[i/2] = a[i];
		i *= 2;
	}
	a[i/2] = item;
}
struct node
{
	node *next;
	int v;
	int len;
}*list[2100];
int main ()
{
	int n,m,i,j;
	int x,y,len;
	int CurrentSize = 1;
	ac t;
	scanf("%d%d",&n,&m);
	for ( i = 1; i <= n; i++ )
	{
		root[i] = i;
		list[i] = NULL;
		for ( j = 1; j <= n; j++ )
			c[i][j] = 2000000000;
	}
	for ( i = 0; i < m; i++ )
	{
		scanf("%d%d%d",&x,&y,&len);
		if ( c[x][y] > len )
			c[x][y] = c[y][x] = len;
	}
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j < i; j++ )
		{
			if ( c[i][j] != 2000000000 )
			{
				t.x = i;
				t.y = j;
				t.len = c[i][j];
				SmallHeapInsert(CurrentSize,t);
			}
		}
	}
	for ( i = 1; i < n; i++ )
	{
		t = a[1];
		if ( find(a[1].x) == find(a[1].y) )
		{
			i--;
			SmallDel(CurrentSize);
			continue;
		}
		SmallDel(CurrentSize);
		join(t.x,t.y);
	}
	cout<<t.len<<endl;
	return 0;
}