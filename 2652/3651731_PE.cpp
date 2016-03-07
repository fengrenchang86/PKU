#include <iostream>
#include <stdlib.h>
using namespace std;
int acleft[12000];
int acright[12000];
int acl[12000];
int acr[12000];
int cmp ( const void*a, const void*b )
{
	return *(int*)a- *(int*)b;
}
int main ()
{
	int n,m,t;
	int i,j,k,tc,l,r,pos;
	int time;
	char ch[1000];
	scanf("%d",&tc);
	while ( tc-- )
	{
		scanf("%d%d%d",&n,&t,&m);
		l = r = 0;
		for ( i = 0; i < m; i++ )
		{
			scanf("%d %s",&time,ch);
			if ( ch[0] == 'l' )
				acleft[l++] = time;
			else
				acright[r++] = time;
		}
		acleft[l] = 2000000000;
		acright[r] = 2000000000;
		pos = i = j = time = 0;
		while ( i <= l && j <= r )
		{
			if ( time < acleft[i] && time < acright[j] )
			{
				time = acleft[i]<acright[j]?acleft[i]:acright[j];
			}
			if ( pos == 0 && time >= acleft[i] )
			{
				k = i+1;
				while ( k < l && time >= acleft[k] && k-i < n )
					k++;
				time += t;
				pos = 1;
				while ( i < k )
				{
					acl[i] = time;
					i++;
				}
			}
			else if ( pos == 0 && time >= acright[j] )
			{
				time += t;
				pos = 1;
			}
			else if ( pos == 1 && time >= acright[j] )
			{
				k = j+1;
				while ( k < r && time >= acright[k] && k-j < n )
					k++;
				time += t;
				pos = 0;
				while ( j < k )
				{
					acr[j] = time;
					j++;
				}
			}
			else if ( pos == 1 && time >= acleft[i] )
			{
				time += t;
				pos = 0;
			}
		}
		i = j = 0;
		while ( i < l && j < r )
		{
			if ( acleft[i] < acright[j] )
			{
				printf("%d\n",acl[i]);
				i++;
			}
			else
			{
				printf("%d\n",acr[j]);
				j++;
			}
		}
		while ( i < l )
			printf("%d\n",acl[i++]);
		while ( j < r )
			printf("%d\n",acr[j++]);
	}
	return 0;
}