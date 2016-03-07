#pragma   warning(disable:4786)
#include<iostream> 
#include<string> 
#include<stack>
#include<queue>
#include<map> 
using namespace std; 
#define nch char[12]
char v[8][8];
char ans[462889];
int begin,end,flag;
string tch;
string final = "12345678x";
int e=0;
struct chang
{
	string sch;
	string pa;
}p,q;
struct ren
{
	string path;
	char dir;
}acren;
map<string,int>ac;
map<string,ren>path;
queue<chang>que;
void init ()
{
	int i,j;
	for ( i = 0; i < 5; i++ )
		v[i][0] = v[0][i] = v[4][i] = v[i][4] = 'x';
	cin>>v[1][2]>>v[1][3];
	for ( i = 2; i <= 3; i++ )
	{
		for ( j = 1; j <= 3; j++ )
		{
			cin>>v[i][j];
			if ( v[i][j] == 'x' )
			{
				begin = i;
				end = j;
			}
		}
	}
	while ( !que.empty() )
		que.pop();
	flag = 0;
}
int s ( string str )
{
	int i;
	for ( i = 0; i < str.length(); i++ )
	{
		if ( str[i] == 'x' )
			break;
	}
	begin = i/3;
	end = i%3;
	return i;
}
bool run ()
{
	int i,j;
	tch = "";
	for ( i = 1; i <= 3; i++ )
	{
		for ( j = 1; j <= 3; j++ )
			tch += v[i][j];
	}
	ac.clear();
	path.clear();
	ac[tch] = 1;
	p.sch = tch;
	p.pa = "";
	que.push(p);
	string str;
	while ( !que.empty() )
	{
		q = que.front();
		str = q.sch;
		que.pop();
		i = s(str);
		if ( begin > 0 )
		{
			j = (3*(begin-1))+end;
			tch = str;
			tch[i] = str[j];
			tch[j] = str[i];
			if ( ac[tch] == 0 )
			{
				ac[tch] = 1;
				p.sch = tch;
				p.pa = q.pa+"u";
				e++;
				if ( tch == final )
				{
					return true;
				}
				que.push(p);
			}
		}
		if ( begin < 2 )
		{
			j = (3*(begin+1))+end;
			tch = str;
			tch[i] = str[j];
			tch[j] = str[i];
			if ( ac[tch] == 0 )
			{
				ac[tch] = 1;
				p.sch = tch;
				p.pa = q.pa+"d";
				e++;
				if ( tch == final )
				{
					return true;
				}
				que.push(p);
			}
		}
		if ( end > 0 )
		{
			j = 3*begin+end-1;
			tch = str;
			tch[i] = str[j];
			tch[j] = str[i];
			if ( ac[tch] == 0 )
			{
				ac[tch] = 1;
				p.sch = tch;
				p.pa = q.pa+"l";
				e++;
				if ( tch == final )
				{
					return true;
				}
				que.push(p);
			}
		}
		if ( end < 2 )
		{
			j = 3*begin+end+1;
			tch = str;
			tch[i] = str[j];
			tch[j] = str[i];
			if ( ac[tch] == 0 )
			{
				ac[tch] = 1;
				p.sch = tch;
				p.pa = q.pa+"r";
				e++;
				if ( tch == final )
				{
					return true;
				}
				que.push(p);
			}
		}
	}
	return false;
}
void test ()
{
	queue<int>t;
	int i,j;
	for ( i = 1; i <= 5; i++ )
	{
		cin>>j;
		t.push(j);
	}
	while ( !t.empty() )
	{
		j = t.front();
		cout<<j<<endl;
		t.pop();
	}
}
int main ()
{
	bool f;
	while ( cin>>v[1][1] )
	{
		init();
		f = run();
		if ( f == true )
		{
			cout<<p.pa<<endl;
		}
		else
			printf("unsolvable\n");
	//	printf("%s\n",ans);
	}
	return 0;
}