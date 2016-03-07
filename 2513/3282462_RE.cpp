#pragma   warning(disable:4786)
#include <iostream>
#include <string>
#include <map>
using namespace std;
const int Num = 260000;
bool visit[Num];
int degree[Num];
int father[Num];
map<string,int>m;
int getfather( int x )
{
	while ( x != father[x] )
		x = father[x];
	return x;
}
int main ()
{
	string sa,sb;
	int fx,fy,n=1,x,y;
	char ca[100],cb[100];
	memset(visit,false,sizeof(visit));
	int i,j;
	for ( i = 0; i < Num; i++ )
	{
		father[i] = i;
		degree[i] = 0;
	}
	while ( scanf("%s%s",&ca,&cb)!=EOF )
	{
		sa.assign(ca);
		sb.assign(cb);
		if ( sa == sb )
			continue;
		x = m[sa];
		y = m[sb];
		if ( x == 0 )
		{
			x = n;
			m[sa] = n++;
		}
		if ( y == 0 )
		{
			y = n;
			m[sb] = n++;
		}
		degree[x]++;
		degree[y]++;
		if ( visit[x] == false )
			fx = -1;
		else
			fx = getfather(x);
		if ( visit[y] == false )
			fy = -1;
		else
			fy = getfather(y);
		if ( fx == -1 && fy == -1 )
		{
			visit[x] = true;
			visit[y] = true;
			father[x] = y;
		}
		else if ( fx == -1 )
		{
			visit[x] = true;
			father[x] = fy;
		}
		else if ( fy == -1 )
		{
			visit[y] = true;
			father[y] = fx;
		}
		else
			father[fx] = fy;
	}
	j = 0;
	for ( i = 1; i < n && j <= 2; i++ )
	{	
		if ( degree[i] % 2 == 1 )
			j++;
	}
	if ( i < n || j==1)
	{
		printf("Impossible\n");
		return 1;
	}
	if ( n == 0 )
	{
		printf("Possible\n");
		return 1;
	}
	j = getfather(1);
	for ( i = 2; i < n; i++ )
	{
		if ( getfather(i) != j )
			break;
	}
	if ( i < n)
	{
		printf("Impossible\n");
		return 1;
	}
	else
		printf("Possible\n");	
	return 0;
}