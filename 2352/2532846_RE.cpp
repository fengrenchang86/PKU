#include <iostream>
using namespace std;
int a[30000];
struct wf
{
	int x,y;
}t[16000];
void insert ( int key, int i, int left, int right )
{
	int mid;
	while ( left != right )
	{
		mid = (left+right)/2;
		if ( key <= mid )
		{
			a[i]++;
			i*=2;
			right = mid;
		}
		else
		{
			a[i]++;
			i = i*2 + 1;
			left = mid + 1;
		}
	}
	a[i]++;
}
int find ( int left, int right, int x, int y, int i )
{
	if ( left == x && right == y )
		return a[i];
	int mid = (left+right)/2;
	if ( y <= mid )
		return find(left,mid,x,y,i*2);
	else if ( x > mid )
		return find(mid+1,right,x,y,i*2+1);
	else
		return (find(left,mid,x,mid,i*2))+(find(mid+1,right,mid+1,y,i*2+1));
}
int main ()
{
	int list[16000];
	memset(a,0,sizeof(a));
	memset(list,0,sizeof(list));
	int n,i,j;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d%d",&t[i].x,&t[i].y);
		j = find(1,32000,1,t[i].x,1);
		insert(t[i].x,1,1,32000);
		list[j]++;
	}
	for ( i = 0; i < n; i++ )
		printf("%d\n",list[i]);
	return 0;
}