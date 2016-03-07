#include <iostream>
#include <string.h>
using namespace std;
int main ()
{
	char ch[20][100];
	char put;
	int list[10];
	int p,i,j,k,count;
	while ( cin>>ch[0] )
	{
		if ( ch[0][0] == '-' )
			break;
		count = 0;
		p = 1;
		while ( count <= 15 )
		{
			for ( i = 0; i <= 9; i++ )
				list[i] = 0;
			for ( i = 0; ch[p-1][i] != NULL; i++ )
				list[ch[p-1][i]-'0']++;
			j = 0;
			for ( i = 1; i <= 9; i++ )
			{
				if ( list[i] != 0 )
				{
					ch[p][j] = list[i]+'0';
					j++;
					ch[p][j] = i+'0';
					j++;
				}
			}
			ch[p][j] = NULL;
			for ( i = 0; i < p; i++ )
			{
				if ( strcmp(ch[i],ch[p]) == 0 )
					break;
			}
			if ( i == p )
				p++;
			else
				break;
		}
		if ( count > 15 )
			printf("%s can not be classified after 15 iterations\n",ch[0]);
		else
		{
			if ( p == 1 )
				printf("%s is self-inventorying\n",ch[0]);
			else if ( p-i == 1 )
				printf("%s is self-inventorying after %d steps\n",ch[0],i);
			else
				printf("%s enters an inventory loop of length %d\n",ch[0],p-i);
		}
	}
	return 0;
}