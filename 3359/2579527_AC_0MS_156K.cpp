#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
struct ac
{
	char name[30];
	int num;
	int count;
}a[30];
int cmp ( const void*a, const void*b )
{
	struct ac *c = (ac*)a;
	struct ac *d = (ac*)b;
	if ( c->count != d->count )
		return d->count - c->count;
	else
		return c->num - d->num;
}
int f ( char *a )
{
	int min = 100;
	int i;
	for ( i = 1; a[i] != NULL; i++ )
	{
		if ( abs(a[i]-a[i-1]) < min )
			min = abs(a[i]-a[i-1]);
	}
	return min;
}
void next ( char *a )
{
	char b[30];
	char t;
	int i,j,k,len=strlen(a);
	j = 0;
	for ( i = len-1; i > 0; i-- )
	{
		b[j++] = a[i];
		if ( a[i] > a[i-1] )
			break;
	}
	i--;
	for ( k = 0; k < j; k++ )
	{
		if ( b[k] > a[i] )
		{
			t = b[k];
			b[k] = a[i];
			a[i] = t;
			break;
		}
	}
	i++;
	for ( k = 0; k < j; k++ )
		a[i++] = b[k];
}
void pre ( char *a )
{
	char b[30];
	char t;
	int i,j,k,len=strlen(a);
	j = 0;
	for ( i = len-1; i > 0; i-- )
	{
		b[j++] = a[i];
		if ( a[i] < a[i-1] )
			break;
	}
	i--;
	for ( k = 0; k < j; k++ )
	{
		if ( b[k] < a[i] )
		{
			t = b[k];
			b[k] = a[i];
			a[i] = t;
			break;
		}
	}
	i++;
	for ( k = 0; k < j; k++ )
		a[i++] = b[k];
}
int main ()
{
	char username[100];
	char t[30];
	int i;
	while ( cin>>username )
	{
		strcpy(t,username);
		for ( i = 10; i >= 1; i-- )
		{
			pre(t);
			strcpy(a[i].name,t);
			a[i].count = f(t);
			a[i].num = i;
		}
		strcpy(t,username);
		for ( i = 11; i < 21; i++ )
		{
			next(t);
			strcpy(a[i].name,t);
			a[i].count = f(t);
			a[i].num = i;
		}
	//	for ( i = 1; i < 21; i++ )
	//		printf("%s\n",a[i].name);
		a[0].count = -1;
		qsort(a,21,sizeof(a[0]),cmp);
		printf("%s%d\n",a[0].name,a[0].count);
	}
	return 0;
}