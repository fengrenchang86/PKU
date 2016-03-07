#include <iostream>
using namespace std;
char ch[50];
int maxi,maxd,maxcount,maxlen,maxpos,maxdis;
void f( int i, int d )
{
	int count=0,len,pos,dis;
	pos = i;
	int j,k=0;
	int tlen = strlen(ch);
	for ( j = i; j >= 0; j -= d )
	{
		if ( ch[j] == '.' )
			k++;
		else
			break;
	}
	if ( k > maxcount )
	{
		maxcount = k;
		maxpos = i;
		maxd = d;
		maxlen = j;
		maxdis = i-j;
	}
	else if ( k == maxcount && k != 0 && j > maxlen && j >= 0 )
	{
		maxlen = j;
		maxpos = i;
		maxd = d;
		maxdis = i-j;
	}
	else if ( k == maxcount && k != 0 && j == maxlen && maxpos < i )
	{
		maxpos = i;
		maxd = d;
		maxdis = i-j;
	}
	else if ( k == maxcount && k != 0 && j == maxlen && maxpos == i && maxdis < i-j )
	{
		maxd = d;
		maxdis = i-j;
	}
	k = 0;
	for ( j = i; j < tlen; j+=d )
	{
		if ( ch[j] == '.' )
			k++;
		else
			break;
	}
	if ( k > maxcount )
	{
		maxcount = k;
		maxpos = i;
		maxd = d;
		maxlen = j;
		maxdis = j-i;
	}
	else if ( k == maxcount && k != 0 && j > maxlen && j < tlen )
	{
		maxlen = j;
		maxpos = i;
		maxd = d;
		maxdis = j-i;
	}
	else if ( k == maxcount && k != 0 && j == maxlen && maxpos < i )
	{
		maxpos = i;
		maxd = d;
		maxdis = j-i;
	}
	else if ( k == maxcount && k != 0 && j == maxlen && maxpos == i && maxdis < j-i )
	{
		maxd = d;
		maxdis = j-i;
	}
}
int main ()
{
	int i,j,len;
	while ( scanf(" %s",ch) != EOF )
	{
		maxcount = 0;
		len = strlen(ch);
		if ( ch[0] == 'E' && ch[1] == 'N' && ch[2] == 'D' )
			break;
		for ( i = 0; i < len; i++ )
		{
			for ( j = 1; j < len; j++ )
				f(i,j);
		}
		if ( maxcount != 0 )
			printf("%d %d\n",maxpos,maxd);
		else
			printf("%d %d\n",len-1,1);
	}
	return 0;
}