#include <iostream>
#include <stdlib.h>
using namespace std;
struct ac
{
	int num;
}a[100100];
int cmp ( const void *a, const void *b )
{
	struct ac* c = (ac*)a;
	struct ac* d = (ac*)b;
	return (c->num - d->num);
}
int main ()
{
	int list[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
	int n,i,j;
	char ch[200];
	bool ok = false;
	scanf("%d",&n);
	cin.ignore();
	for ( i = 0; i < n; i++ )
	{
		a[i].num = 0;
		gets(ch);
		for ( j = 0; ch[j] != NULL;j++ )
		{
			if ( ch[j] >= '0' && ch[j] <= '9' )
			{
				a[i].num *= 10;
				a[i].num += ch[j]-'0';
			}
			else if ( ch[j] >= 'A' && ch[j] <= 'Z' )
			{
				a[i].num *= 10;
				a[i].num += list[ch[j]-'A'];
			}
		}
	}
	qsort(a,n,sizeof(a[0]),cmp);
	int x = a[0].num;
	j = 1;
	for ( i = 0; i < n-1; i++ )
	{
		if ( a[i+1].num == x )
			j++;
		else
		{
			if ( j > 1 )
			{
				ok = true;
				printf("%03d-%04d %d\n",x/10000,x%10000,j);
			}
			x = a[i+1].num;
			j = 1;
		}
	}
	if ( j > 1 )
	{
		printf("%03d-%04d %d\n",x/10000,x%10000,j);
		ok = true;
	}
	if ( ok == false )
		printf("No duplicates.\n");
	return 0;
}