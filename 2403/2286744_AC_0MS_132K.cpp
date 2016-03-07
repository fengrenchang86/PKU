#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
struct ac
{
	char name[20];
	int mark;
	int num;
	ac(){num=-1;}
}a[1200];
int cmp( const void *a ,const void *b) 
{ 
     return strcmp( (*(ac *)a).name , (*(ac *)b).name ); 
} 

int main ()
{
	int m,n;
	char ch[200];
	int d;
	scanf("%d%d",&m,&n);
	int i;
	int c;
	int low,high,mid;
	int end = 0;
	for ( i = 0; i < m; i++ )
	{
		scanf("%s%d",&ch,&d);
		a[end].mark = d;
		strcpy(a[end].name,ch);
		end++;
	}
	cin.ignore();
	qsort(a,end,sizeof(a[0]),cmp);
	for ( i = 0; i < n; i++ )
	{
		c = 0;
		while ( scanf("%s",&ch) && ch[0] != '.' )
		{
			low = 0;
			high = end-1;
			while ( low <= high )
			{
				mid = (low+high)/2;
				if ( strcmp(a[mid].name,ch) < 0 )
					low = mid+1;
				else if ( strcmp(a[mid].name,ch) > 0 )
					high = mid-1;
				else
					break;
			}
			if ( strcmp(a[mid].name,ch)==0  )
			{
				c += a[mid].mark;
			}
		}
		cout<<c<<endl;
	}
	return 0;
}