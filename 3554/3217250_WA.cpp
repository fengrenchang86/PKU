
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 11000;
vector<int> vec;
struct ac
{
	int data;
	int point;
}a[MAX];
int w[MAX];
int ans[MAX];
int ans2[MAX];
struct node
{
	int v;
	int len;
	int id;
	node *next;
}*list[MAX],*plist[MAX];
void insert ( int a, int b,int len,int id )
{
	node *p = new node;
	p->v = b;
	p->len = len;
	p->id = id;
	p->next = list[a];
	list[a] = p;
	p = new node;
	p->v = a;
	p->len = len;
	p->id = id;
	p->next = plist[b];
	plist[b] = p;
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
void F1 ( int n )
{
	bool visit[MAX];
	int i,j,k,tm;
	node *p;
	for ( i = 1; i <= n; i++ )
	{
		visit[i] =false;
		ans[i] = 2000000000;
	}
	ans[1] = 0;
	for ( i = 0; i < n; i++ )
	{
		tm = 2000000000;
		for ( j = 1; j <= n; j++ )
		{
			if ( visit[j] == false && ans[j] < tm )
			{
				k = j;
				tm = ans[j];
			}
		}
		if ( tm == 2000000000 )
			return;
		visit[k] = true;
		p = list[k];
		while ( p != NULL )
		{
			if ( ans[p->v] > ans[k]+p->len )
				ans[p->v] = ans[k]+p->len;
			p = p->next;
		}
	}
}
void F2 ( int n )
{
	bool visit[MAX];
	int i,j,k,tm;
	node *p;
	for ( i = 1; i <= n; i++ )
	{
		visit[i] =false;
		ans2[i] = 2000000000;
	}
	ans2[n] = 0;
	for ( i = 0; i < n; i++ )
	{
		tm = 2000000000;
		for ( j = 1; j <= n; j++ )
		{
			if ( visit[j] == false && ans2[j] < tm )
			{
				k = j;
				tm = ans2[j];
			}
		}
		if ( tm == 2000000000 )
			return;
		visit[k] = true;
		p = plist[k];
		while ( p != NULL )
		{
			if ( ans2[p->v] > ans2[k]+p->len )
				ans2[p->v] = ans2[k]+p->len;
			p = p->next;
		}
	}
}
int dij ( int n )
{
	bool visit[MAX];
	int i,j;
	int CurrentSize = 1;
	for ( j = 1; j <= n; j++ )
	{
		SmallHeapInsert(CurrentSize,2000000000);
		visit[j] = false;
		ans[j] = 2000000000;
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
			if ( ans[j]+ p->len< a[w[p->v]].data && visit[p->v] == false )
			{
				a[w[p->v]].data = ans[j]+p->len;
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
int dij2 ( int n )
{
	bool visit[MAX];
	int i,j;
	int CurrentSize = 1;
	for ( j = 1; j <= n; j++ )
	{
		SmallHeapInsert(CurrentSize,2000000000);
		visit[j] = false;
		ans2[j] = 2000000000;
	}
	node *p = plist[n];
	visit[n] = true;
	ans2[n] = 0;
	a[w[n]].data = 0;
	GoUp(w[n]);
	for ( i = 1; i <= n; i++ )
	{
		j = a[1].point;
		visit[j] = true;
		ans2[j] = a[1].data;
		p = plist[j];
		SmallHeapDel(CurrentSize);
		while ( p != NULL )
		{
			if ( ans2[j]+ p->len< a[w[p->v]].data && visit[p->v] == false )
			{
				a[w[p->v]].data = ans2[j]+p->len;
				GoUp(w[p->v]);
			}
			p = p->next;
		}
	}
	j = a[1].point;
	visit[j] = true;
	ans2[j] = a[1].data;
	return ans2[1];
}
int main ()
{	
	int i,k,n,a,m,b,len;
	node *p;
	scanf("%d%d%d",&n,&m,&k);
	for ( i = 0; i <= n; i++ )
		list[i] = plist[i] = NULL;
	for ( i = 1; i <= m; i++ )
	{
		scanf("%d%d%d",&a,&b,&len);
		insert(a,b,len,i);
	}
//	a = dij(n)+k;
//	dij2(n);
	F1(n);
	F2(n);
	a = ans[n]+k;
	if ( a > 2000000000 )
		a = 2000000000;
	for ( i = 1; i <= n; i++ )
	{
		p = list[i];
		while ( p != NULL )
		{
			if ( ans[i]+p->len+ans2[p->v] <= a )
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
