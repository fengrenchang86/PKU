#include <iostream>
#include <algorithm>
using namespace std;
int n,t;
int d[1100];
class ac
{
public:
	int data,id;
}w[1100],p[1100];
bool cmp ( const ac &ma, const ac &mb )
{
	return ma.data < mb.data;
}
int ans[1100];
void input ()
{
	int i;
	scanf("%d%d",&n,&t);
	for ( i = 0; i < n; i++ )
	{
		w[i].id = i;
		scanf("%d",&w[i].data);
	}
	for ( i = 0; i < n; i++ )
		scanf("%d",&d[i]);
	for ( i = 0; i < n; i++ )
	{
		p[i].id = i;
		scanf("%d",&p[i].data);
	}
	for ( i = 0; i < n; i++ )
		p[i].data -= t*d[i];
	sort(w,w+n,cmp);
	sort(p,p+n,cmp);
	for ( i = 0; i < n; i++ )
		ans[p[i].id] = w[i].id;
	for ( i = 0; i < n; i++ )
		printf("%d ",ans[i]+1);
	printf("\n");
}
int main ()
{
	input();
	return 0;
}