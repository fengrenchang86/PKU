#include <iostream>
using namespace std;
struct ac
{
	int type;
}oper[200];
int s[1010][1010];
bool flag = false;
void print ( int k )
{
	int i;
	for ( i = 1; i < k; i++ )
	{
		switch(oper[i].type)
		{
		case 1:cout<<"pour A B"<<endl;
			break;
		case 2:cout<<"pour B A"<<endl;
			break;
		case 3:cout<<"fill A"<<endl;
			break;
		case 4:cout<<"fill B"<<endl;
			break;
		case 5:cout<<"empty A"<<endl;
			break;
		case 6:cout<<"empty B"<<endl;
			break;
		}
	}
}
void dfs ( int i, int a, int b, int ma, int mb, int c )
{
	s[a][b] = 1;
	if ( a == c )
	{
		print(i);
		cout<<"empty B"<<endl;
		cout<<"pour A B"<<endl;
		cout<<"success"<<endl;
		flag = true;
		return;
	}
	else if ( b == c )
	{
		print(i);
		cout<<"success"<<endl;
		flag = true;
		return;
	}
	if ( a != 0 && b != mb && oper[i-1].type != 2  )
	{
		oper[i].type = 1;
		if ( a < mb-b && s[0][a+b]==0 )
			dfs(i+1,0,b+a,ma,mb,c);
		else if ( a >= mb-b && s[a-mb+b][mb] == 0 )
			dfs(i+1,a-mb+b,mb,ma,mb,c);
		if ( flag == true )
			return;
	}
	if ( b != 0 && a != ma && oper[i-1].type != 1 )
	{
		oper[i].type = 2;
		if ( b < ma-a && s[a+b][0] == 0 )
			dfs(i+1,a+b,0,ma,ma,c);
		else if ( b >= ma-a && s[ma][b-ma+a] == 0 )
			dfs(i+1,ma,b-ma+a,ma,mb,c);
		if ( flag == true )
			return;
	}
	if ( a!=ma && s[ma][b] == 0 )
	{
		oper[i].type = 3;
		dfs(i+1,ma,b,ma,mb,c);
		if ( flag == true )
			return;
	}
	if (  b!=mb && s[a][mb] == 0 )
	{
		oper[i].type = 4;
		dfs(i+1,a,mb,ma,mb,c);
		if ( flag == true )
			return;
	}
	if ( s[0][b] == 0 && s[0][b] == 0 )
	{
		oper[i].type = 5;
		dfs(i+1,0,b,ma,mb,c);
		if ( flag == true )
			return;
	}
	if ( s[a][0] == 0 )
	{
		oper[i].type = 6;
		dfs(i+1,a,0,ma,mb,c);
		if ( flag == true )
			return;
	}
}
int main ()
{
	int i,j;
	int ma,mb,c;
	oper[0].type = 0;
	while ( cin>>ma>>mb>>c)
	{
		for ( i = 0; i <= 1000; i++ )
			for ( j = 0; j <= 1000;j++)
				s[i][j] = 0;
		flag = false;
		dfs(1,0,0,ma,mb,c);
	}
	return 0;
}