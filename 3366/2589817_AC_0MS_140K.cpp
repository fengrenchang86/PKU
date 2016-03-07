#include <iostream>
#include <string>
using namespace std;
struct ac
{
	char word[30];
	char cword[30];
}a[30];
int main ()
{
	int i,j,k,n,m;
	scanf("%d%d",&n,&m);
	char ch[30];
	for ( i = 0; i < n; i++ )
		scanf(" %s %s",&a[i].word,&a[i].cword);
	for ( i = 0; i < m; i++ )
	{
		scanf(" %s",&ch);
		k = -1;
		for ( j = 0; j < n; j++ )
		{
			if( strcmp(ch,a[j].word)==0 )
			{
				k = j;
				break;
			}
		}
		if ( k != -1 )
			printf("%s\n",a[j].cword);
		else
		{
			k = strlen(ch);
			if ( ch[k-1] == 'y' && ch[k-2] == ch[k-3] && k-3 >= 0 )
			{
				ch[k-1] = 'i';
				ch[k++] = 'e';
				ch[k++] = 's';
				ch[k] = NULL;
			}
			else if ( ch[k-1] == 'o' || ch[k-1] == 's' || ch[k-1] == 'x' ||
				ch[k-1]=='h' &&(ch[k-2]=='c'||ch[k-2]=='s') )
			{
				ch[k++] = 'e';
				ch[k++] = 's';
				ch[k] = NULL;
			}
			else
			{
				ch[k++] = 's';
				ch[k] = NULL;
			}
			printf("%s\n",ch);
		}
	}
	return 0;
}