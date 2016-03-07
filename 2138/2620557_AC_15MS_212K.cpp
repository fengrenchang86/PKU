#include <iostream>
using namespace std;
struct ac
{
	char name[90];
	int len;
	int w;
	bool visit;
}a[1002];
int comp ( char *a, char *b )
{
	int i=0,j=0,k=0;
	while ( b[j] != NULL )
	{
		if ( a[i] == b[j] )
			i++;
		else
			k++;
		j++;
		if ( k == 2 )
			return 0;
	}
	return 1;
}
int main ()
{
	int n,i,j,k,min;
	scanf("%d %s",&n,&a[0].name);
	a[0].len=strlen(a[0].name);
	a[0].visit = true;
	a[0].w = 0;
	for ( i = 1; i <= n; i++ )
	{
		scanf("%s",&a[i].name);
		a[i].len = strlen(a[i].name);
		a[i].w = 2000;
	}
	for ( i = 1; i <= n; i++ )
	{
		if ( a[i].len == a[0].len+1 )
		{
			if ( comp(a[0].name,a[i].name) == 1 )
				a[i].w = 1;
		}
	}
	for ( i = 1; i <= n; i++ )
	{
		min = 2000;
		k = 0;
		for ( j = 1; j <= n; j++ )
		{
			if ( a[j].visit == false && a[j].w < min )
			{
				min = a[j].w;
				k = j;
			}
		}
		if ( k == 0 )
			break;
		a[k].visit = true;
		if ( a[k].w == 2000 )
			break;
		for ( j = 1; j <= n; j++ )
		{
			if ( a[j].visit == true )
				continue;
			if ( a[j].len-a[k].len==1 && comp(a[k].name,a[j].name)==1 )
			{
				if ( a[j].w > a[k].w+1 )
					a[j].w = a[k].w + 1;
			}
		}
	}
	j = a[0].w;
	k = 0;
	for ( i = 1; i <= n; i++ )
	{
		if ( a[i].visit == true && a[i].w > j )
		{
			j = a[i].w;
			k = i;
		}
	}
	printf("%s\n",a[k].name);
	return 0;
}