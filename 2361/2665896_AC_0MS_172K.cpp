#include <iostream>
using namespace std;
char a[5][5];
int check1 ( char ch )
{
	int i,j=0;
	for ( i = 0; i < 3; i++ )
	{
		if ( a[i][0] == ch && a[i][1] == ch && a[i][2] == ch )
			j++;
	}
	return j;
}
int check2 ( char ch )
{
	int i,j = 0;
	for ( i = 0; i < 3; i++ )
	{
		if ( a[0][i] == ch && a[1][i] == ch && a[2][i] == ch )
			j++;
	}
	return j;
}
int check3 ( char ch )
{
	int j = 0;
	if ( a[0][0] == ch && a[1][1] == ch && a[2][2] == ch )
		j=1;
	if ( a[0][2] == ch && a[1][1] == ch && a[2][0] == ch )
		j=1;
	return j;
}
int main ()
{
	int tcase,i,j,x,o;
	cin>>tcase;
	while ( tcase )
	{
		tcase--;
		for ( i = 0; i < 3; i++ )
			cin>>a[i];
		x = o = 0;
		for ( i = 0; i < 3; i++ )
		{
			for ( j = 0; j < 3; j++ )
			{
				if ( a[i][j] == 'O' )
					o++;
				else if ( a[i][j] == 'X' )
					x++;
			}
		}
		if ( o > x )
			cout<<"no"<<endl;
		else if ( x-o>1 )
			cout<<"no"<<endl;
		else if ( x > o )
		{
			if ( check1('O') == 0 && check2('O')==0 && check3('O') == 0 &&
				check1('X')<=1 && check2('X')<=1 && check3('X')<=1 )
				cout<<"yes"<<endl;
			else
				cout<<"no"<<endl;
		}
		else
		{
			if ( check1('X') == 0 && check2('X')==0 && check3('X') == 0 &&
				check1('O')<=1 && check2('O')<=1 && check3('O')<=1 )
				cout<<"yes"<<endl;
			else
				cout<<"no"<<endl;
		}
	}
	return 0;
}