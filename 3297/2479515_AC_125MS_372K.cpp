#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
struct person
{
	char name[40];
	int state;
	person *next;
	person(){state=-1;next=NULL;}
}*v[26];
struct project
{
	char name[40];
	int num;
	person *next;
	project(){next=NULL;}
}pro[200];
int cmp ( const void *a, const void *b)
{
	struct project *c = (project*)a;
	struct project *d = (project*)b;
	if ( c->num != d->num )
		return d->num - c->num;
	else
		return strcmp(c->name,d->name);
}
int pronum;
void init()
{
	pronum = 0;
	for ( int i = 0; i < 26; i++ )
		v[i] = NULL;
}
int main ()
{
	char ch[40];
	int i;
	person *p;
	init();
	while ( gets(ch) )
	{
		if ( ch[0] >= 'A' && ch[0] <= 'Z' )
		{
			strcpy(pro[pronum].name,ch);
			pro[pronum].num = 0;
			pronum++;
		}
		else if ( ch[0] >= 'a' && ch[0] <= 'z' )
		{
			p = v[ch[0]-'a'];
			while ( p != NULL )
			{
				if ( strcmp(p->name,ch) == 0 )
					break;
				p = p->next;
			}
			if ( p == NULL )
			{
				pro[pronum-1].num++;
				p = new person;
				strcpy(p->name,ch);
				p->next = v[ch[0]-'a'];
				v[ch[0]-'a'] = p;
				p->state = pronum-1;
			}
			else
			{
				if ( p->state != pronum-1 )
				{
					pro[p->state].num--;
					p->state = -1;
				}
			}
		}
		else if ( ch[0] == '1' )
		{
			qsort(pro,pronum,sizeof(pro[0]),cmp);
			for ( i = 0; i < pronum; i++ )
				printf("%s %d\n",pro[i].name,pro[i].num);
			init();
		}
		else
			break;
	}
	return 0;
}