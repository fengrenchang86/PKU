#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
const int max = 50010;
int list[26] = {2,2,2,3,3,3,4,4,1,1,5,5,6,6,0,7,0,7,7,8,8,8,9,9,9,0};
char ori[120];
int n;
struct ac
{
	char name[51];
	char dig[51];
}a[max];
struct acm
{
	int pre;
	int data;
	acm(){pre=-1;}
}v[120];
void trans ( char *a, char *b )
{
	int i;
	for ( i = 0; a[i] != NULL; i++ )
		b[i] = list[a[i]-'a']+'0';
	b[i] = NULL;
}
int find ( char *ch, int low, int high )
{
	int mid;
	int d = -1;
	while ( low < high )
	{
		mid = (low+high)/2;
		d = strcmp(ch,a[mid].dig);
		if ( d < 0 )
			high = mid;
		else if ( d > 0 )
			low = mid+1;
		else
			break;
	}
	if ( d == 0 )
		return mid;
	if ( strcmp(ch,a[low].dig) == 0 )
		return low;
	else
		return -1;
}
int cmp( const void *a ,const void *b) 
{ 
     return strcmp((*(ac *)a).dig, (*(ac *)b).dig );
} 
void f ( int i )
{
	if ( i != 0 )
	{
		f(v[i].pre);
		printf("%s ",a[v[i].data].name);
	}
}
int main ()
{
	int i,j,k;
	int len;
	char ch[120];
	scanf("%s",&ori);
	len = strlen(ori);
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		scanf("%s",&a[i].name);
		trans(a[i].name,a[i].dig);
	}
	qsort(a,n,sizeof(a[0]),cmp);
	strcpy(ch,ori);
	i = len;
	while ( i > 0 )
	{
		ch[i] = NULL;
		k = find(ch,0,n-1);
		if ( k != -1 )
		{
			v[i-1].pre = 0;
			v[i-1].data = k;
		}
		i--;
	}
	for ( i = 1; i < len; i++ )
	{
		if ( v[i].pre != -1 )
			continue;
		for ( j = 1; j < i; j++ )
		{
			if ( v[j].pre != -1 )
			{
				for ( k = j+1; k <= i; k++ )
					ch[k-j-1] = ori[k];
				ch[k-j-1] = NULL;
				k = find(ch,0,n-1);
				if ( k != -1 )
				{
					v[i].pre = j;
					v[i].data = k;
					break;
				}
			}
		}
	}
	i = len-1;
	if ( v[i].pre == -1 )
		printf("No solution.\n");
	else
	{
		f(i);
		printf("\n");
	}
	return 0;
}