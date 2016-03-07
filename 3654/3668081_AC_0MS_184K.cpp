#include <iostream>
#include <stdlib.h>
using namespace std;
int a[30][30];
bool use[30];
char t[300];
int it=1;
struct ac
{
	int zimu;
	int num;
}v[30];
int cmp ( const void*a, const void*b )
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	if ( c->num != d->num )
		return d->num - c->num;
	else
		return c->zimu - d->zimu;
}
bool comp ( int k )
{
	int i,j;
	for ( i = k+1; i < 26; i++ )
	{
		if ( v[i].num == 0 )
			continue;
		else
			break;
	}
	if ( i==26)
		return true;
	for ( j = 0; j < 26; j++ )
	{
		if ( a[i][j] != a[k][j] )
			return true;
	}
	return false;
}
void solve ( )
{
	int i,j,k,oper;
	for ( i = 0; i < 26; i++ )
	{
		for ( j = 0; j < 26; j++ )
			a[i][j] = 0;
		use[i] = false;
	}
	for ( i = 0; t[i] != 0;  )
	{
		while ( !(t[i]>='a'&&t[i]<='z') && !(t[i]>='A'&&t[i]<='Z') && t[i]!='=' && t[i] !='+' && t[i] != '-' && t[i] != 0)
			i++;
		while ( t[i] >= 'A' && t[i] <= 'Z' )
		{
			use[t[i]-'A']=true;
			i++;
		}
		if ( t[i] == '-' )
			oper = 1;
		else if ( t[i] == '+' )
			oper = 2;
		else
		{
			oper = 3;
			for ( j = 0; j < 26; j++ )
			{
				if ( use[j] == false )
					continue;
				for ( k = 0; k < 26; k++ )
					a[j][k] = 0;
			}
		}
		i++;
		while ( !(t[i]>='a'&&t[i]<='z') && !(t[i]>='A'&&t[i]<='Z') && t[i]!='=' && t[i] !='+' && t[i] != '-' && t[i] != 0)
			i++;
		while ( t[i] >= 'a' && t[i] <= 'z' )
		{
			for ( j = 0; j < 26; j++ )
			{
				if ( use[j] == false )
					continue;
				if ( oper == 1 )
					a[j][t[i]-'a'] = 0;
				else
					a[j][t[i]-'a'] = 1;
			}
			i++;
		}
		while ( !(t[i]>='a'&&t[i]<='z') && !(t[i]>='A'&&t[i]<='Z') && t[i]!='=' && t[i] !='+' && t[i] != '-' && t[i] != 0)
			i++;
		memset(use,false,sizeof(use));
	}
	k = 0;
	for ( i = 0; i < 26; i++ )
	{
		k = 0;
		for ( j = 0; j < 26; j++ )
			k += a[i][j];
		v[i].zimu = i;
		v[i].num = k;
	}
	printf("%d:",it++);
	for ( i = 0; i < 26; i++ )
	{
		if ( v[i].num == 0 )
			continue;
		printf("%c",char('A'+i));
		if ( comp(i) == false )
			continue;
		for ( j = 0; j < 26; j++ )
		{
			if ( a[i][j] == 1 )
				printf("%c",char('a'+j));
		}
	}
	printf("\n");
}
int main ()
{
	while ( scanf(" %s",t) != EOF )
	{
		if ( t[0] == '#' )
			break;
		solve();
	}
	return 0;
}