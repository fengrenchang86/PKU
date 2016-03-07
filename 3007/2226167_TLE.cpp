#include <iostream>
#include <string>
using namespace std;
struct node
{
	char t[100];
	node *next;
	node()
	{
		next = NULL;
	}
};
node *head = NULL;
int count;
void insert ( char *ch )
{
	node *p = head;
	while ( p != NULL )
	{
		if ( strcmp(p->t,ch) == 0 )
			return;
		p = p->next;
	}
	if ( p == NULL )
	{
		p = new node;
		strcpy(p->t,ch);
		p->next = head;
		head = p;
		count ++;
	}
}
int main ()
{
	int tcase;
	char a[100];
	char tempa[100],tempb[100],b[100];
	int sizea,sizeb,size;
	int i,j,len;
	scanf("%d",&tcase);
	while ( tcase )
	{
		tcase--;
		count = 0;
		scanf("%s",&a);
		len = strlen(a);
		insert(a);
		size = 0;
		for ( i = 0; i < len; i++ )
			b[size++] = a[len-i-1];
		b[size] = NULL;
		insert(b);
		for ( i = 1; i <= len-1; i++ )
		{
			size = sizea = sizeb = 0;
			for ( j = 0; j < i; j++ )
				tempa[sizea++] = a[j];
			tempa[sizea] = NULL;
			while ( j < len )
			{
				tempb[sizeb++] = a[j];
				j++;
			}
			tempb[sizeb] = NULL;
			for ( j = 0; j < sizea; j++ )
				b[size++] = tempa[j];
			for ( j = sizeb-1; j >= 0; j-- )
				b[size++] = tempb[j];
			b[size] = NULL;
			insert(b);
			size = 0;
			for ( j = sizea-1; j >= 0;j -- )
				b[size++] = tempa[j];
			for ( j = 0; j < sizeb; j++ )
				b[size++] = tempb[j];
			b[size] = NULL;
			insert(b);
			size = 0;
			for ( j = sizea-1; j >=0; j-- )
				b[size++] = tempa[j];
			for ( j = sizeb-1; j>=0; j-- )
				b[size++] = tempb[j];
			b[size] = NULL;
			insert(b);
			size = 0;
			for ( j = 0; j < sizeb; j++ )
				b[size++] = tempb[j];
			for ( j = 0; j < sizea; j++ )
				b[size++] = tempa[j];
			b[size] = NULL;
			insert(b);
			size = 0;
			for ( j = sizeb-1; j >=0 ;j-- )
				b[size++] = tempb[j];
			for ( j = 0; j < sizea; j++ )
				b[size++] = tempa[j];
			b[size] = NULL;
			insert(b);
			size = 0;
			for ( j = 0; j < sizeb; j++ )
				b[size++] = tempb[j];
			for ( j = sizea-1; j>=0; j-- )
				b[size++] = tempa[j];
			b[size] = NULL;
			insert(b);
		}
		printf("%d\n",count);
	}
	return 0;
}