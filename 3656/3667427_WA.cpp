#include <iostream>
using namespace std;
char ch[50];
int maxi,maxd,maxcount,maxlen,maxpos;
void f( int i, int d )
{
	int count=0,len,pos,dis;
	pos = i;
	int j,k=0,bpos;
	int tlen = strlen(ch);
	for ( j = i+d; j < tlen; j+=d )
	{
		k++;
		if ( ch[j] != '.' )
			break;
	}
	if ( j >= tlen )
		bpos = j-d;
	else
		bpos = j;
	if ( k > maxcount )
	{
		maxcount = k;
		maxpos = i;
		maxd = d;
		maxlen = bpos;
	}
	else if ( k == maxcount && k != 0 && maxlen < bpos )
	{
		maxlen = bpos;
		maxpos = i;
		maxd = d;
	}
	else if ( k == maxcount && k != 0 && j == maxlen && maxpos < i )
	{
		maxpos = i;
		maxd = d;
	}
	else if ( k == maxcount && k != 0 && j == maxlen && maxpos == i && maxd > d )
	{
		maxd = d;
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
			if ( ch[i] != '.' )
				continue;
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