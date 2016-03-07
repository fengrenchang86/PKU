#pragma warning ( disable:4786)
#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string,int>ma;
int n,m;
char a[52000][200];
int main ()
{
	int i,j,k;
	char dic[100];
	scanf("%d",&n);
	{
		ma.clear();
		for ( i = 0; i < n; i++ )
		{
			scanf(" %s",dic);
			ma[dic] = 1;
		}
		scanf("%d",&m);
		for ( i = 1; i <= m; i++ )
		{
			k = 0;
			while ( scanf(" %s",dic) )
			{
				if ( strcmp(dic,"-1") == 0 )
					break;
				if ( ma[dic] == 0 )
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