#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
struct ac
{
	char name[40];
	int num;
}a[100000];
int main ()
{
	int cmp(const void*,const void*);
	int i,j,k,p;
	char ch[100];
	while ( gets(ch) )
	{
		i = 0;
		while ( gets(ch))
		{
			if ( strcmp(ch,"END")==0 )
				break;
			for ( j = 0; ch[j] != ' '; j++ )
				a[i].name[j] = ch[j];
			a[i].name[j] = NULL;
			j++;
			k = 0;
			while ( ch[j] >= '0' && ch[j] <= '9' )
			{
				k *= 10;
				k += ch[j]-'0';
				j++;
			}
			j++;
			p = 0;
			while ( ch[j] == ' ' )
				j++;
			while ( ch[j] >= '0' && ch[j] <= '9' )
			{
				p *= 10;
				p += ch[j]-'0';
				j++;
			}
			a[i].num = p-k;
			i++;
		}
		qsort(a,i,sizeof(a[0]),cmp);
		for ( j = 0; j < i; j++ )
			printf("%s\n",a[j].name);
		printf("\n");
	}
	return 0;
}
int cmp ( const void *a, const void*b )
{
	struct ac *c = (ac*)a;
	struct ac *d = (ac*)b;
	return d->num-c->num;
}