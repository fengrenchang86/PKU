#pragma   warning(disable:4786)
#include<iostream> 
#include<string> 
#include<stack>
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
	int lay;
};
map<string,int>ac;
stack<chang>stac;
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
	while ( !stac.empty() )
		stac.pop();
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
	chang p;
	int i,j,k=0;
	tch = "";
	for ( i = 1; i <= 3; i++ )
	{
		for ( j = 1; j <= 3; j++ )
			tch += v[i][j];
	}
	ac.clear();
	ac[tch] = 1;
	p.sch = tch;
	p.lay = -1;
	stac.push(p);
	string str;
	while ( !stac.empty() )
	{
		p = stac.top();
		p.lay++;
		k = p.lay;
		str = p.sch;
		stac.pop();
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
				ans[k] = 'u';
				p.sch = tch;
				e++;
				if ( tch == final )
				{
					ans[k+1] = NULL;
					return true;
				}
				stac.push(p);
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
				ans[k] = 'd';
				p.sch = tch;
				e++;
				if ( tch == final )
				{
					ans[k+1] = NULL;
					return true;
				}
				stac.push(p);
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
				ans[k] = 'l';
				p.sch = tch;
				e++;
				if ( tch == final )
				{
					ans[k+1] = NULL;
					return true;
				}
				stac.push(p);
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
				ans[k] = 'r';
				p.sch = tch;
				e++;
				if ( tch == final )
				{
					ans[k+1] = NULL;
					return true;
				}
				stac.push(p);
			}
		}
	}
	return false;
}
void dfs ( int x, int y,int lay )
{
	int i,j,k=0;
	tch = "";
	for ( i = 1; i <= 3; i++ )
	{
		for ( j = 1; j <= 3; j++ )
			tch[k++] += v[i][j];
	}
	tch[k] = NULL;
	if ( tch == final )
	{
		ans[lay] = NULL;
		flag = 1;
		return;
	}
	if ( ac[tch] == 1 )
		return;
	ac[tch] = 1;
	e++;
	i = x;
	j = y;
	if ( v[i-1][j] != 'x' )
	{
		v[i][j] = v[i-1][j];
		v[i-1][j] = 'x';
		ans[lay] = 'u';
		dfs(x-1,y,lay+1);
		if ( flag )
			return;
		v[i-1][j] = v[i][j];
		v[i][j] = 'x';
	}
	if ( v[i+1][j] != 'x' )
	{
		v[i][j] = v[i+1][j]; 
		v[i+1][j] = 'x';
		ans[lay] = 'd';
		dfs(x+1,y,lay+1);
		if ( flag )
			return;
		v[i+1][j] = v[i][j];
		v[i][j] = 'x';
	}
	if ( v[i][j-1] != 'x' )
	{
		v[i][j] = v[i][j-1];
		v[i][j-1] = 'x';
		ans[lay] = 'l';
		dfs(x,y-1,lay+1);
		if ( flag )
			return;
		v[i][j-1] = v[i][j];
		v[i][j] = v[i][j-1];
	}
	if ( v[i][j+1] != 'x' )
	{
		v[i][j] = v[i][j+1];
		v[i][j+1] = 'x';
		ans[lay] = 'r';
		dfs(x,y+1,lay+1);
		if ( flag )
			return;
		v[i][j+1] = v[i][j];
		v[i][j] = 'x';
	}
}

int main ()
{
	bool f;
	while ( cin>>v[1][1] )
	{
		init();
		f = run();
		printf("%s\n",ans);
	}
	return 0;
}