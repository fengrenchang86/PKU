#include <iostream>
using namespace std;
struct ac
{
	int compare;//比较次数
	int balance;//正数表示重，负数表示轻
	bool good;//true表示不是假币，false表有可能是假币
	ac(){good=false;balance=0;compare=0;}
}a[1010];
int main ()
{
	int ta[1002];
	int tb[1002];
	int n,k;
	int i,d,j;
	char ch;
	scanf("%d%d",&n,&k);
	for ( i = 0; i < k; i++ )
	{
		scanf("%d",&d);
		for ( j = 0; j < d; j++ )
			cin>>ta[j];
		for ( j = 0; j < d; j++ )
			cin>>tb[j];
		cin>>ch;
		if ( ch == '=' )
		{
			for ( j = 0; j < d; j++ )
			{
				a[ta[j]].good = true;
				a[tb[j]].good = true;
			}
		}
		else if ( ch == '>' )
		{
			for ( j = 0; j < d; j++ )
			{
				a[ta[j]].compare++;
				a[tb[j]].compare++;
				a[ta[j]].balance++;
				a[tb[j]].balance--;
			}
		}
		else
		{
			for ( j = 0; j < d; j++ )
			{
				a[ta[j]].compare++;
				a[tb[j]].compare++;
				a[ta[j]].balance--;
				a[tb[j]].balance++;
			}
		}
	}
	k = 0;
	j = -1;
	d = 0;
	int v = -1;
	for ( i = 1; i <= n; i++ )
	{
		if ( abs(a[i].balance) != a[i].compare )
			a[i].good = true;
	}
	for ( i = 1; i <= n; i++ )
	{
		if ( a[i].good == true )
			continue;
		if ( a[i].compare == 0 )
		{
			d++;
			v = i;
		}
		if ( abs(a[i].balance) == a[i].compare && a[i].compare != 0)
		{
			k++;
			j = i;
		}
	}
	if ( k == 1 )
		printf("%d\n",j);
	else if ( k == 0 && d==1 )
		printf("%d\n",v);
	else
		printf("0\n");
	return 1;
}