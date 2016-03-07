#include <iostream>
using namespace std;

struct ac
{
	int father;
	int mother;
	int sex;
	int marriged;
	ac()
	{
		father = mother = sex = -1;
		marriged = 0;
	}
}node[120];

int one ( int x, int y )	//x是不是y的父亲或母亲，或者掉转
{
	if ( node[x].father == y )
		return 0;
	if ( node[x].mother == y )
		return 0;
	if ( node[y].father == x )
		return 0;
	if ( node[y].mother == x )
		return 0;
	return 1;
}
int grand ( int x, int y )	//是不是孙关系
{
	if ( node[x].sex == 0 )
	{
		if ( node[y].father != -1 )
			if ( node[node[y].father].father == x )
				return 0;
		if ( node[y].mother != -1 )
			if ( node[node[y].mother].father == x )
				return 0;
	}
	else
	{
		if ( node[y].mother != -1 )
			if ( node[node[y].mother].mother == x )
				return 0;
		if ( node[y].father != -1 )
			if ( node[node[y].father].mother == x )
				return 0;
	}
	if ( node[y].sex == 0 )
	{
		if ( node[x].father != -1 )
			if ( node[node[x].father].father == y )
				return 0;
		if ( node[x].mother != -1 )
			if ( node[node[x].mother].father == y )
				return 0;
	}
	else
	{
		if ( node[x].father != -1 )
			if ( node[node[x].father].mother == y )
				return 0;
		if ( node[x].mother != -1 )
			if ( node[node[x].mother].mother == y )
				return 0;
	}
	return 1;
}
int	uncle ( int x, int y )
{
	if ( node[x].father == node[y].father && node[x].father != -1 )
		return 0;
	if ( node[x].father != -1 && node[y].father != -1 )
		if ( node[node[x].father].father == node[node[y].father].father && node[node[y].father].father != -1 )
			return 0;
	if ( node[x].mother != -1 && node[y].father != -1 )
		if ( node[node[x].mother].father == node[node[y].father].father && node[node[y].father].father != -1  )
			return 0;
	if ( node[x].father != -1 && node[y].mother != -1 )
		if ( node[node[x].father].father == node[node[y].mother].father && node[node[y].mother].father != -1 )
			return 0;
	if ( node[x].mother != -1 && node[y].mother != -1 )
		if ( node[node[x].mother].father == node[node[y].mother].father && node[node[y].mother].father != -1  )
			return 0;
	if ( node[x].mother != -1 && node[y].father != -1 )
		if ( node[node[x].mother].father == node[y].father )
			return 0;
	if ( node[x].father != -1 && node[y].father != -1 )
		if ( node[node[x].father].father == node[y].father )
			return 0;
	if ( node[y].mother != -1 && node[x].father != -1 )
		if ( node[node[y].mother].father == node[x].father )
			return 0;
	if ( node[y].father != -1 && node[x].father != -1 )
		if ( node[node[y].father].father == node[x].father )
			return 0;
	return 1;
}
int main ()
{
	int x,y;
	scanf("%d %d",&x,&y);
	int a[100];
	int i;
	int n,m;
	while ( scanf("%d",&n)!=EOF )
	{
	//	if ( n == 0 )
	//		break;
		i = 0;
		while ( scanf("%d",&a[i]) && a[i]!=-1 && a[i] != 0 )
			i++;
		if ( a[i] == -1 )
		{
			node[n].sex = -1;
			node[n].marriged = 1;
			i--;
			while ( i >= 0 )
			{
				node[a[i]].mother = n;
				i--;
			}
		}
		else
		{
			node[n].sex = 0;
			node[n].marriged = 1;
			i--;
			while ( i >= 0 )
			{
				node[a[i]].father = n;
				i--;
			}
		}
	}
		if ( node[x].sex == node[y].sex )
			cout<<"same\n";
		else
		{
			m = one(x,y);
			if ( m == 0 )
				cout<<"close\n";
			else
			{
				m = grand(x,y);
				if ( m == 0 )
					cout<<"close\n";
				else
				{
					m = uncle(x,y);
					if ( m == 0 )
						cout<<"close\n";
					else
						cout<<"marriage\n";
				}
			}
		}
	return 0;
}