#include <iostream>
using namespace std;

struct msg
{
	char txt[120];
	msg *next;
	msg() {
		next = NULL; 
	}
};
msg *list[130]={0};
int com ( char *a , char * b )
{
	int i;
	for ( i = 0; a[i] != NULL&&b[i]!=NULL; i++ )
		if ( a[i] != b[i] )
			return 0;
	if ( a[i]!=NULL && b[i]==NULL )
		return 0;
	else
		return 1;
}
void insert ( msg *t )
{
	t->next = list[t->txt[0]];
	list[t->txt[0]] = t;
}
int main ()
{
	int n;
	int m;
	int i;
	int j = 0;
	int k;
	int max = 0;
	msg *p;
	scanf("%d %d",&m,&n);
	msg *a = new msg[m+1];
	msg *b = new msg[n+1];
	cin.ignore(100,'\n');
	for ( i = 0; i < m; i++ )
	{
		cin.getline(a[i].txt,100,'\n');
//		scanf("%['\0']",a[i].txt);
//		insert(&a[i]);
	}
	for ( i = 0; i < n; i++ )
	{
		cin.getline ( b[i].txt,100,'\n');
//		scanf("%['\0']",b[i].txt);
//		p = list[b[i].txt[0]];
//		while ( p != NULL )
//		{
//			max+= com(b[i].txt,p->txt);
//			p = p->next;
//		}
		for ( j = 0; j < m; j++ )
		{
			if( b[i].txt[0] != a[j].txt[0] )
				continue;
			k = com(b[i].txt,a[j].txt);
			max+= k;
			b[i].txt[0] = '!';
		}
	}
	printf("%d\n",max);
	return 1;
}