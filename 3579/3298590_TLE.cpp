#include <iostream>
#include <queue>
#include <stdlib.h>
using namespace std;
struct ac
{
	int x,y;
	int val;
	friend bool operator<(const ac&m1, const ac&m2)
	{
		return m1.val > m2.val;
	}
}pac,t;
priority_queue<ac>que;
int arr[100100];
int n;
int cmp ( const void*a, const void*b )
{
	return *(int*)a - *(int*)b;
}
int main ()
{
	int i;
	__int64 m;
	while ( scanf("%d",&n) != EOF )
	{
		while ( !que.empty() )
			que.pop();
		m = n;
		m = m*(m-1)/2;
		m = (m-1)/2;
		for ( i = 1; i <= n; i++ )
			scanf("%d",&arr[i]);
		arr[0] = -1;
		qsort(arr,n+1,sizeof(arr[0]),cmp);
		for ( i = 2; i <= n; i++ )
		{
			pac.x = i-1;
			pac.y = i;
			pac.val = arr[i] - arr[i-1];
			que.push(pac);
		}
		for ( i = 0; i <= m; i++ )
		{
			t = que.top();
	//		printf("%d\n",t.val);
			que.pop();
			if ( t.y < n )
			{
				pac.x = t.x;
				pac.y = t.y+1;
				pac.val = arr[pac.y]-arr[pac.x];
				que.push(pac);
			}
		}
		printf("%d\n",t.val);
	}
	return 0;
}