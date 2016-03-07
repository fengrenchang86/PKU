
#include <iostream>
#include <stdlib.h>
#include <map>
using namespace std;
map<int,bool>ma;
struct ac
{
	int x,y,z;
}t[41000];
int n;
int a[81000],b[81000];
int cmp ( const void*a, const void*b )
{
	return *(int*)a-*(int*)b;
}
int find ( int begin , int end, int key )
{
	int mid = (begin+end)/2;
	while ( begin < end )
	{
		if ( a[mid] > key )
			end = mid;
		else if ( a[mid] < key )
			begin=mid+1;
		else
			return mid;
		mid = (begin+end)/2;
	}
	return mid;
}

int main ()
{
	int x,y;
	int i,j,m=0;
	scanf("%d",&n);
	ma.clear();
	for ( i = 0; i < n; i++ )
	{
//		t[i].x = (rand()*rand())%1000000000;
//		t[i].y = (rand()*rand())%1000000000;
//		t[i].z = rand()%10;
		scanf("%d%d%d",&t[i].x,&t[i].y,&t[i].z);
		if ( t[i].x > t[i].y )
		{
			y = t[i].x;
			t[i].x = t[i].y;
			t[i].y = y;
		}
		if ( ma[t[i].x] == false )
		{
			ma[t[i].x]=true;
			a[m++] = t[i].x;
		}
		if ( ma[t[i].y] == false )
		{
			ma[t[i].y] = true;
			a[m++] = t[i].y;
		}
	}
	qsort(a,m,sizeof(a[0]),cmp);
	memset(b,0,sizeof(b));
	for ( i = 0; i < n; i++ )
	{
		x = find(0,m-1,t[i].x);
		y = find(0,m-1,t[i].y);
		for ( j = x; j < y; j++ )
		{
			if ( b[j] < t[i].z )
				b[j] = t[i].z;
		}
	}
	x = 0;
	for ( i = 0; i < m-1; i++ )
		x += (a[i+1]-a[i])*b[i];
	cout<<x<<endl;
	return 0;
}