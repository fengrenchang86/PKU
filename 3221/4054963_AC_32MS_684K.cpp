#pragma warning ( disable:4786 )
#include <iostream>
#include <map>
#include <string>
#include <queue>
using namespace std;
struct ac
{
	string name;
	int step;
};
map<string,int>ma;
queue<ac>que;
void init ()
{
	ma.clear();
	while ( !que.empty() )
		que.empty();
}
int find0 ( string str )
{
	int i;
	for ( i = 0; i < 7; i++ )
	{
		if ( str[i] == '0' )
			break;
	}
	return i;
}
void solve ()
{
	ac p,q;
	int k;
	p.name = "0123456";
	p.step = 1;
	ma["0123456"] = 1;
	que.push(p);
	while ( !que.empty() )
	{
		p = que.front();
		que.pop();
		if ( ma[p.name] < p.step )
			continue;
		k = find0(p.name);
		if ( k != 0 )
		{
			q = p;
			q.step++;
			q.name[k] = q.name[k%6+1];
			q.name[k%6+1] = '0';
			if ( ma[q.name] == 0 || ma[q.name] > q.step )
			{
				ma[q.name] = q.step;
				que.push(q);
			}
			q = p;
			q.step++;
			if ( k == 1 )
			{
				q.name[1] = q.name[6];
				q.name[6] = '0';
			}
			else
			{
				q.name[k] = q.name[k-1];
				q.name[k-1] = '0';
			}
			if ( ma[q.name] == 0 || ma[q.name] > q.step )
			{
				ma[q.name] = q.step;
				que.push(q);
			}
		}
		if ( k == 0 )
		{
			q = p;
			q.step++;
			q.name[0] = q.name[2];
			q.name[2] = '0';
			if ( ma[q.name] == 0 || ma[q.name] > q.step )
			{
				ma[q.name] = q.step;
				que.push(q);
			}
			q = p;
			q.step++;
			q.name[0] = q.name[4];
			q.name[4] = '0';
			if ( ma[q.name] == 0 || ma[q.name] > q.step )
			{
				ma[q.name] = q.step;
				que.push(q);
			}
			q = p;
			q.step++;
			q.name[0] = q.name[6];
			q.name[6] = '0';
			if ( ma[q.name] == 0 || ma[q.name] > q.step )
			{
				ma[q.name] = q.step;
				que.push(q);
			}
		}
		else if ( k == 2 )
		{
			q = p;
			q.step++;
			q.name[2] = q.name[0];
			q.name[0] = '0';
			if ( ma[q.name] == 0 || ma[q.name] > q.step )
			{
				ma[q.name] = q.step;
				que.push(q);
			}
		}
		else if ( k == 4 )
		{
			q = p;
			q.step++;
			q.name[4] = q.name[0];
			q.name[0] = '0';
			if ( ma[q.name] == 0 || ma[q.name] > q.step )
			{
				ma[q.name] = q.step;
				que.push(q);
			}
		}
		else if ( k == 6 )
		{
			q = p;
			q.step++;
			q.name[6] = q.name[0];
			q.name[0] = '0';
			if ( ma[q.name] == 0 || ma[q.name] > q.step )
			{
				ma[q.name] = q.step;
				que.push(q);
			}
		}
	}
}
int main ()
{
	int tc,k;
	string str;
	cin>>tc;
	init();
	solve();
	while ( tc-- )
	{
		cin>>str;
		k = ma[str];
		printf("%d\n",k-1);
	}
	return 0;
}