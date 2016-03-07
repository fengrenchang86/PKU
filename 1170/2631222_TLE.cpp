#include <iostream>
#include <stdlib.h>
using namespace std;
int id[1000];
struct ac
{
	int m;
	int obj[10];
	int num[10];
	int price;
	int low;
}a[100];
struct wa
{
	int name,item,singlePirce;
}b[6];
int cmp ( const void*a, const void*b )
{
	struct ac *c = (ac*)a;
	struct ac *d = (ac*)b;
	return d->low - c->low;
}
int min;
int n,s;
int v[6];
bool flag;
void dfs ( int CurrentPrice, int lay )
{
	if ( CurrentPrice >= min )
		return;
	int i,j;
	for ( i = 0; i < n; i++ )
		if ( v[i] < b[i].item )
			break;
	if ( i == n )
	{
		for ( i = 0; i < n; i++ )
			if ( v[i] > b[i].item )
				break;
		if ( min > CurrentPrice )
			min = CurrentPrice;
		if ( i == n )
			flag = true;
		return;
	}
	if ( lay == s )
		return;
//	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < a[lay].m; j++ )
			v[id[a[lay].obj[j]]] += a[lay].num[j];
	}
	dfs(CurrentPrice+a[lay].price,lay);
	dfs(CurrentPrice+a[lay].price,lay+1);
//	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < a[lay].m; j++ )
			v[id[a[lay].obj[j]]] -= a[lay].num[j];
	}
	dfs(CurrentPrice,lay+1);
}
int main ()
{
	int i,j,sum = 0;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d%d%d",&b[i].name,&b[i].item,&b[i].singlePirce);
		id[b[i].name] = i;
		sum += b[i].item*b[i].singlePirce;
		v[i] = 0;
		a[i].m = 1;
		a[i].low = 0;
		a[i].num[0] = 1;
		a[i].obj[0] = b[i].name;
		a[i].price = b[i].singlePirce;
	}
	min = sum;
	flag = false;
	scanf("%d",&s);
	s +=n;
	for ( i = n; i < s; i++ )
	{
		scanf("%d", &a[i].m );
		sum = 0;
		for ( j = 0; j < a[i].m; j++ )
		{
			scanf("%d%d",&a[i].obj[j],&a[i].num[j]);
			sum += a[i].num[j]*b[id[a[i].obj[j]]].singlePirce;
		}
		scanf("%d",&a[i].price);
		a[i].low = sum-a[i].price;
	}
	qsort(a,s,sizeof(a[0]),cmp);
	dfs(0,0);
	cout<<min<<endl;
	return 0;
}