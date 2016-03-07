#pragma warning ( disable:4786)
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
int n,m;
char b[92000][200];
char a[92000][200];
bool visit[92000];
int cmp(const void * a,const void * b)
{
	return strcmp((char*)(a),(char*)(b));
}
bool acm ( char *t )
{
	int begin = 0;
	int end = n-1;
	int mid,k;
	while ( begin < end )
	{
		mid = (begin+end)/2;
		k = strcmp(t,b[mid]);
		if ( k == 0 )
			return true;
		else if ( k < 0 )
			end = mid;
		else
			begin = mid+1;
	}
	if ( strcmp(b[begin],t) == 0 )
		return true;
	else
		return false;
}
int main ()
{
	int i,j,k;
	char dic[100];
	scanf("%d",&n);
	{
		for ( i = 0; i < n; i++ )
		{
			scanf("%s",b[i]);
			visit[i] = false;
		}
		qsort(b,n,sizeof(b[0]),cmp);
		scanf("%d",&m);
		for ( i = 1; i <= m; i++ )
		{
			k = 0;
			while ( scanf(" %s",dic) )
			{
				if ( strcmp(dic,"-1") == 0 )
					break;
				if ( !acm(dic) )
				{
					strcpy(a[k],dic);
					k++;
				}
			}
			if ( k == 0 )
				printf("Email %d is spelled correctly.\n",i);
			else
			{
				printf("Email %d is not spelled correctly.\n",i);
				for ( j = 0; j < k; j++ )
					printf("%s\n",a[j]);
			}
		}
	}
	printf("End of Output\n");
	return 0;
}