#include <iostream>
#include <string>
#include <map>
using namespace std;
map <string,int>chang;
const int N = 1220;
int n,full,TC;
__int64 p[N];
struct ac
{
	string name;
	int type;
	int price;
	int quality;
}a[N];
void input()
{
	TC = 1;
	int i;
	string x,y;
	scanf("%d %d",&n,&full);
	for ( i = 0; i < n; i++ )
	{
		cin>>a[i].name>>y>>a[i].price>>a[i].quality;
		a[i].type = chang[a[i].name];
		if ( a[i].type == 0 )
		{
			chang[a[i].name] = TC;
			a[i].type = TC;
			TC++;
		}
	}
}
bool fit ( int mid )
{
	int i;
	__int64 k = 0;
	for ( i = 0; i < TC; i++ )
		p[i] = 2000000000;
	for ( i = 0; i < n; i++ )
	{
		if ( p[a[i].type] > a[i].price && a[i].quality >= mid )
			p[a[i].type] = a[i].price;
	}
	for ( i = 1; i < TC; i++ )
		k += p[i];
	if ( k <= full )
		return true;
	else
		return false;
}
int solve ()
{
	int begin=0,end=1000000000,mid;
	while ( begin < end )
	{
		mid = (begin+end)/2;
		if ( fit(mid) == true )
			begin = mid+1;
		else
			end = mid;
	}
	if ( fit(begin) == true )
		return begin;
	else
		return begin-1;
}
void over()
{
	int i;
	for ( i = 0; i < n; i++ )
		chang[a[i].name] = 0;
}
int main ()
{
	int tcase,k;
	scanf("%d",&tcase);
	while ( tcase-- )
	{
		input();
		k = solve();
		cout<<k<<endl;
		over();
	}
	return 0;
}