#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
struct ac
{
	char str[120];
	int type;
	bool yes;
}a[9];
int cmp ( const void*a, const void*b )
{
	struct ac* c = (ac*)a;
	struct ac* d = (ac*)b;
	return strcmp(c->str,d->str);
}
int n,c;
void change ( char *t, int buttom )
{
	int i,j;
	if ( buttom == 1 )
	{
		i = 0;
		j = 1;
	}
	else if ( buttom == 2 )
	{
		i = 0;
		j = 2;
	}
	else if ( buttom == 3 )
	{
		i = 1;
		j = 2;
	}
	else
	{
		i = 0;
		j = 3;
	}
	while ( i < n )
	{
		if ( t[i] == '0' )
			t[i] = '1';
		else
			t[i] = '0';
		i += j;
	}
}
bool ok ( int type )
{
	if (  type == 3 || type == 5 || type == 7)
		return true;
	else if ( (type==1 || type == 4 || type == 6 || type == 8) && c >= 2 )
		return true;
	else if ( type == 2 && c != 2 )
		return true;
	else
		return false;
}
void init ()
{
	int i,j;
	for ( i = 0; i < 8; i++ )
	{
		for ( j = 0; j < n; j++ )
			a[i].str[j] = '1';
		a[i].str[j] = NULL;
		a[i].type = i+1;
		a[i].yes = false;
	}
	change(a[1].str,4);
	change(a[2].str,3);
	change(a[3].str,3);
	change(a[3].str,4);
	change(a[4].str,2);
	change(a[5].str,2);
	change(a[5].str,4);
	change(a[6].str,2);
	change(a[6].str,3);
	change(a[7].str,2);
	change(a[7].str,3);
	change(a[7].str,4);
//	for ( i = 0; i < 8; i++ )
//		printf("%s\n",a[i].str);
}
int len1,len2,x[3],y[3];
int main ()
{
	int i,j;
	cin>>n>>c;
	init ();
	len1 = len2 = 0;
	while ( cin>>x[len1] && x[len1] != -1 )
		len1++;
	while ( cin>>y[len2] && y[len2] != -1 )
		len2++;
	for ( i = 0; i < 8; i++ )
	{
		for ( j = 0; j < len1; j++ )
		{
			if ( a[i].str[x[j]-1] == '0' )
				break;
		}
		if ( j < len1 )
			continue;
		for ( j = 0; j < len2; j++ )
		{
			if ( a[i].str[y[j]-1] == '1' )
				break;
		}
		if ( j == len2 )
			a[i].yes = true;
	}
	qsort(a,8,sizeof(a[0]),cmp);
	for ( i = 0; i < 8; i++ )
	{
		if ( a[i].yes == true && ok(a[i].type)==true )
			printf("%s\n",a[i].str);
	}
	return 0;
}