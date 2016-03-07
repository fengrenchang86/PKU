#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
const int max = 50010;
int list[26] = {2,2,2,3,3,3,4,4,1,1,5,5,6,6,0,7,0,7,7,8,8,8,9,9,9,0};
int v[120];
char ori[120];
int n;
struct ac
{
	char name[51];
	char dig[51];
}a[max];
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
	int d = 0;
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
void f ( int k )
{
	char ch[102];
	int i,j;
	if ( v[k] == -1 )
		return;
	f ( v[k] );
	for ( i = v[k]; i <= k; i++ )
		ch[i-v[k]] = ori[i];
	ch[i-v[k]] = NULL;
	j = find(ch,0,n-1);
	printf("%s ",a[j].name);
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
	for ( i = 0; i < 120; i++ )
		v[i] = -1;
	for ( i = 0; i < len; i++ )
	{
		for ( j = 0; j < i; j++ )
		{
			if ( v[j-1] == -1 && j!=0 )
				continue;
			for ( k = j; k <= i; k++ )
				ch[k-j] = ori[k];
			ch[k-j] = NULL;
			if ( find(ch,0,n-1)!=-1 )
			{
				v[i] = j;
				break;
			}
		}
	}
	v[0] = -1;
	if ( v[len-1] == -1 )
		printf("No solution.\n");
	else
	{
		f(v[len-1]);
		k = len-1;
		for ( i = v[k]+1; i <= k; i++ )
			ch[i-v[k]-1] = ori[i];
		ch[i-v[k]-1] = NULL;
		j = find(ch,0,n-1);
		printf("%s\n",a[j].name);
	}
	return 0;
}