#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
struct ac
{
	char name[50];
	int list[26];
}word[120];
int cmp ( const void *a, const void*b )
{
	struct ac*c = (ac*)a;
	struct ac*d = (ac*)b;
	return strcmp(c->name,d->name);
}
int main ()
{
	int list[26];
	int n = 0;
	int i,j;
	bool ok;
	char name[50];
	while ( gets(word[n].name) )
	{
		if ( strcmp(word[n].name,"XXXXXX")==0 )
			break;
		for ( i = 0; i < 26; i++ )
			word[n].list[i] = 0;
		for ( i = 0; word[n].name[i] != NULL; i++ )
			word[n].list[word[n].name[i]-'a']++;
		n++;
	}
	qsort(word,n,sizeof(word[0]),cmp);
	while ( gets(name) )
	{
		ok = false;
		memset(list,0,sizeof(list));
		for ( i = 0; name[i] != NULL; i++ )
			list[name[i]-'a']++;
		if ( strcmp(name,"XXXXXX")==0 )
			break;
		for ( i = 0; i < n; i++ )
		{
			for ( j = 0; j < 26; j++ )
				if ( list[j] != word[i].list[j] )
					break;
			if ( j == 26 )
			{
				printf("%s\n",word[i].name);
				ok = true;
			}
		}
		if ( ok == false )
			printf("NOT A VALID WORD\n");
		printf("******\n");
	}
	return 0;
}
