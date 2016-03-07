#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
const int max = 100100;
struct ac
{
	char dic[12];
	char word[12];
}a[max];
int cmp( const void *a ,const void *b) 
{ 
     return strcmp( (*(ac *)a).word , (*(ac *)b).word ); 
} 
int main ()
{
	char ch[30];
	int i = 0;
	int j,k;
	int begin,end,mid;
	begin = 0;
	while ( cin.getline(ch,30,'\n') )
	{
		if (ch[0] == NULL)
			break;
		k = j = 0;
		while ( ch[j] != ' ' )
		{
			a[i].dic[j] = ch[j];
			j++;
		}
		a[i].dic[j] = NULL;
		j++;
		while ( ch[j] != NULL )
		{
			a[i].word[k] = ch[j];
			k++;
			j++;
		}
		a[i].word[j] = NULL;
		i++;
	}
	end = i;
	qsort(a,i,sizeof(a[0]),cmp);
	while ( scanf("%s",ch)!=EOF )
	{
		begin = 0;
		end = i-1;
		while ( begin < end )
		{
			mid = (begin+end)/2;
			if ( strcmp(ch,a[mid].word) == 0 )
				break;
			else if ( strcmp(ch,a[mid].word) > 0 )
				begin = mid+1;
			else
				end = mid-1;
		}
		if ( strcmp(ch,a[mid].word) != 0 )
			printf("eh\n");
		else
			printf("%s\n",a[mid].dic);
	}
	return 0;
}