#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int id;
	int next,back;
}a[100100];
int arr[120];
int cmp ( const void*a, const void*b )
{
	return *(int*)a-*(int*)b;
}
void init ( int k )
{
	int i;
	for ( i = 0; i <= k; i++ )
	{
		a[i].id = i;
		a[i].next = i+1;
		a[i].back = i-1;
	}
	a[1].back = k;
	a[k].next = 1;
}
int del ( int id )
{
	int i = a[id].next;
	a[a[id].back].next = a[id].next;
	a[a[id].next].back = a[id].back;
	return i;
}
int Gonext ( int id, int m )
{
	int i;
	for ( i = 0; i < m; i++ )
		id = a[id].next;
	return id;
}
void solve ( int n, int k, int p )
{
	int i,j=0,num=1;
	j = 0;
	for ( i = 1; i < n; i++ )
	{
		j = del(a[j].next);
		j = Gonext(j,p-1);
	}
	arr[0] = a[j].next;
	j = del(a[j].next);
	while ( num < n )
	{
		for ( i = 1; i < n; i++ )
		{
			j = Gonext(j,p-1);
			j = del(a[j].next);
		}
		j = Gonext(j,p-1);
		arr[num++] = a[j].next;
		if ( num < n )
			j = del(a[j].next);
	}
	qsort(arr,n,sizeof(arr[0]),cmp);
	for ( i = 0; i < n; i++ )
		printf("%d\n",arr[i]);
}
int main ()
{
	int n,k,p;
	scanf("%d%d%d",&n,&k,&p);
	init(k);
	solve(n,k,p);
	return 0;
}