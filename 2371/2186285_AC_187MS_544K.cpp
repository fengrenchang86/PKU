#include <iostream>
#include <stdlib.h>
using namespace std;
const int max = 101000 ;
int cmp ( const void *a , const void *b ) 
{ 
     return *(int *)a - *(int *)b; 
} 
int main ()
{
	int a[max];
	int k,i;
	cin>>k;
	for ( i = 0; i < k; i++ )
		cin>>a[i];
	qsort(a,k,sizeof(a[0]),cmp);
	char h[100];
	cin>>h;
	cin>>k;
	int d;
	for ( i = 0; i < k; i++ )
	{
		cin>>d;
		cout<<a[d-1]<<endl;
	}
	return 0;
}