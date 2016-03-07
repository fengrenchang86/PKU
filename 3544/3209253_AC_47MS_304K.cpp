#include <iostream>
#include <algorithm>
using namespace std;
int n,t;
int d[1100];
class ac
{
public:
	__int64 data;
	int id;
}w[1100],p[1100];
bool cmp ( const ac &ma, const ac &mb )
{
	return ma.data < mb.data;
}
int ans[1100];
void input ()
{
	int i;
	for ( i = 0; i < n; i++ )
	{
		w[i].id = i;
		scanf("%I64d",&w[i].data);
	}
	for ( i = 0; i < n; i++ )
		scanf("%d",&d[i]);
	for ( i = 0; i < n; i++ )
	{
		p[i].id = i;
		scanf("%I64d",&p[i].data);
	}
	for ( i = 0; i < n; i++ )
		p[i].data -= __int64(t*__int64(d[i]));
	sort(w,w+n,cmp);
	sort(p,p+n,cmp);
	for ( i = 0; i < n; i++ )
		ans[p[i].id] = w[i].id;
	for ( i = 0; i < n-1; i++ )
		printf("%d ",ans[i]+1);
	printf("%d\n",ans[i]+1);
}
int main ()
{
	while ( scanf("%d%d",&n,&t) != EOF )
		input();
	return 0;
}