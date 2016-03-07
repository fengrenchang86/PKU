#include <iostream>
using namespace std;

struct msg
{
	char txt[70];
	msg *next;
	msg() {
		next = NULL; 
	}
};
msg *list[26]={0};
int com ( char *a , char * b )
{
	int i;
	for ( i = 0; a[i] != NULL&&b[i]!=NULL; i++ )
		if ( a[i] != b[i] )
			return 0;
	return 1;
}
void insert ( msg *t )
{
	t->next = list[t->txt[0]-'A'];
	list[t->txt[0]-'A'] = t;
}
int main ()
{
	int n;
	int m;
	int i;
	int max = 0;
	msg *p;
	scanf("%d %d",&m,&n);
	msg *a = new msg[m];
	msg *b = new msg[n];
	cin.ignore(100,'\n');
	for ( i = 0; i < m; i++ )
	{
		cin.getline(a[i].txt,100,'\n');
//		scanf("%['\0']",a[i].txt);
		insert(&a[i]);
	}
	for ( i = 0; i < n; i++ )
	{
		cin.getline ( b[i].txt,100,'\n');
//		scanf("%['\0']",b[i].txt);
		p = list[b[i].txt[0]-'A'];
		while ( p != NULL )
		{
			max+= com(b[i].txt,p->txt);
			p = p->next;
		}
	}
	printf("%d\n",max);
	return 1;
}