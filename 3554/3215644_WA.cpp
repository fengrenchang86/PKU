#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 11000;
map<int,int>z[MAX];
vector<int> vec;
vector<int>::iterator tend;
struct ac
{
	int data;
	int point;
}a[MAX];
int w[MAX];
int ans[MAX];
struct node
{
	int v;
	int len;
	int id;
	node *next;
}*list[MAX];
void insert ( int a, int b,int len,int id )
{
	node *p = new node;
	p->v = b;
	p->len = len;
	p->id = id;
	p->next = list[a];
	list[a] = p;
}
void GoUp ( int i )
{
	int x,y,t;
	while ( i > 1 && a[i].data < a[i/2].data )
	{
		x = a[i].point;
		y = a[i/2].point;
		t = w[x];
		w[x] = w[y];
		w[y] = t;
		a[0] = a[i];
		a[i] = a[i/2];
		a[i/2] = a[0];
		i /= 2;
	}
}
void GoDown ( int i, int CurrentSize )
{
	i *= 2;
	int x,y,t;
	while ( i <= CurrentSize )
	{
		if ( i < CurrentSize && a[i].data > a[i+1].data )
			i++;
		if ( a[i/2].data <= a[i].data )
			break;
		x = a[i].point;
		y = a[i/2].point;
		t = w[x];
		w[x] = w[y];
		w[y] = t;
		a[0] = a[i];
		a[i] = a[i/2];
		a[i/2] = a[0];
		i *= 2;
	}
}
void SmallHeapInsert ( int &CurrentSize, int x )
{
	w[CurrentSize] = CurrentSize;
	a[CurrentSize].point = CurrentSize;
	a[CurrentSize].data = x;
	GoUp(CurrentSize);
	CurrentSize++;
}
void SmallHeapDel ( int &CurrentSize )
{
	CurrentSize--;
	int i = 1;
	int x,y,t;
	x = a[1].point;
	y = a[CurrentSize].point;
	t = w[x];
	w[x] = w[y];
	w[y] = t;
	a[0] = a[1];
	a[1] = a[CurrentSize];
 	GoDown(1,CurrentSize);
}
int dij ( int n )
{
	bool visit[MAX];
	int i,j,x;
	int CurrentSize = 1;
	for ( j = 1; j <= n; j++ )
	{
		SmallHeapInsert(CurrentSize,2000000000);
		visit[j] = false;
	}
	node *p = list[1];
	visit[1] = true;
	ans[1] = 0;
	a[w[1]].data = 0;
	GoUp(w[1]);
	for ( i = 1; i <= n; i++ )
	{
		j = a[1].point;
		visit[j] = true;
		ans[j] = a[1].data;
		p = list[j];
		SmallHeapDel(CurrentSize);
		while ( p != NULL )
		{
			x = z[j][p->v];
			if ( ans[j]+ x< a[w[p->v]].data && visit[p->v] == false )
			{
				a[w[p->v]].data = ans[j]+x;
				GoUp(w[p->v]);
			}
			p = p->next;
		}
	}
	j = a[1].point;
	visit[j] = true;
	ans[j] = a[1].data;
	return ans[n];
}
int main ()
{	
	int i,j,k,n,a,m,b,len;
	node *p;
	scanf("%d%d%d",&n,&m,&k);
	for ( i = 1; i <= m; i++ )
	{
		scanf("%d%d%d",&a,&b,&len);
		if ( z[a][b] == 0 || z[a][b] > len )
			z[a][b] = len;
		insert(a,b,len,i);
	}
	dij(n);
//	printf("%d\n",dij(n));
	tend = vec.begin();
	for ( i = 1; i <= n; i++ )
	{
		p = list[i];
		while ( p != NULL )
		{
			if ( ans[i]+p->len<=ans[p->v]+k )
				vec.push_back(p->id);
			p = p->next;
		}
	}
	k = vec.size();
	sort(vec.begin(),vec.begin()+k);
	printf("%d\n",k);
	for ( i = 0; i < k; i++ )
		printf("%d\n",vec[i]);
	return 0;
}