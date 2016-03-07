#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
struct ac
{
	char name[32];
}ch[1000100];
int cmp ( const void*a, const void*b )
{
	return strcmp((*(ac*)a).name,(*(ac*)b).name);
}
int main ()
{
	int i,pre,count;
	int n = 0;
	while ( scanf("%s",&ch[n].name)!=EOF )
		n++;
	qsort(ch,n,sizeof(ch[0]),cmp);
	pre = 0;
	count = 1;
	for ( i = 1; i < n; i++ )
	{
		if ( strcmp(ch[i].name,ch[pre].name) == 0 )
			count++;
		else
		{
			printf("%s %.4lf\n",ch[pre].name,double(count)/double(n)*100.0);
			pre = i;
			count = 1;
		}
	}
	printf("%s %.4lf\n",ch[pre].name,double(count)/double(n)*100.0);
	return 0;
}