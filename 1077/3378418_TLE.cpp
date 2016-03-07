
#pragma   warning(disable:4786)
#include<iostream> 
#include<string> 
#include<stack>
#include<queue>
#include<map> 
using namespace std;
struct ac
{
	int step;
	string str;
};
struct MSG
{
	int step;
	string str;
	char dir;
	MSG(){str="";step=0;}
};
map<string,MSG>ma;
map<string,int>mb;
queue<ac>que;
int f ( string str )
{
	int i;
	for ( i = 0; i < 9; i++ )
	{
		if ( str[i] == 'x' )
			break;
	}
	return i;
}
void solve ()
{
	int x,y,j,k;
	char ch;
	ac p,q;
	p.str = "12345678x";
	p.step = 1;
	ma[p.str].step = p.step;
	MSG msg;
	que.push(p);
	while ( !que.empty() )
	{
		p = que.front();
		que.pop();
		if ( p.step > ma[p.str].step )
			continue;
		msg = ma[p.str];
		msg.step = p.step;
		ma[p.str] = msg;
		k = f(p.str);
		j = k;
		x = k/3;
		y = k%3;
		if ( x > 0 )
		{
			q.step = p.step+1;
			q.str = p.str;
			ch = q.str[k];
			q.str[k] = q.str[k-3];
			q.str[k-3] = ch;
			k = ma[q.str].step;
			if ( k == 0 || q.step < k )
			{
				que.push(q);
				msg.dir = 'd';
				msg.str = p.str;
				msg.step = q.step;
				ma[q.str] = msg;
			}
		}
		k = j;
		if ( x < 2 )
		{
			q.step = p.step+1;
			q.str = p.str;
			ch = q.str[k];
			q.str[k] = q.str[k+3];
			q.str[k+3] = ch;
			k = ma[q.str].step;
			if ( k == 0 || q.step < k )
			{
				que.push(q);
				msg.dir = 'u';
				msg.str = p.str;
				msg.step = q.step;
				ma[q.str] = msg;
			}
		}
		k = j;
		if ( y > 0 )
		{
			q.step = p.step+1;
			q.str = p.str;
			ch = q.str[k];
			q.str[k] = q.str[k-1];
			q.str[k-1] = ch;
			k = ma[q.str].step;
			if ( k == 0 || q.step < k )
			{
				que.push(q);
				msg.dir = 'r';
				msg.str = p.str;
				msg.step = q.step;
				ma[q.str] = msg;
			}
		}
		k = j;
		if ( y < 2 )
		{
			q.step = p.step+1;
			q.str = p.str;
			ch = q.str[k];
			q.str[k] = q.str[k+1];
			q.str[k+1] = ch;
			k = ma[q.str].step;
			if ( k == 0 || q.step < k )
			{
				que.push(q);
				msg.dir = 'l';
				msg.str = p.str;
				msg.step = q.step;
				ma[q.str] = msg;
			}
		}
	}
}
int main ()
{
	solve();
	char ch;
	int i;
	MSG msg;
	string str = "";
	while ( cin>> ch )
	{
		str = "";
		str += ch;
		for ( i = 0; i < 8; i++ )
		{
			cin>>ch;
			str += ch;
		}
		while ( str != "12345678x" )
		{
			msg = ma[str];
			printf("%c",msg.dir);
			str = msg.str;
		}
		printf("\n");
	}
	return 0;
}