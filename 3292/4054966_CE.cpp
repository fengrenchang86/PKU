#include <iostream>
#include <stdlib.h>
//#include <time.h>
using namespace std;
//int ta,tb;
const int max = 1000002;
bool b[max],c[max];
int a[max];
int cmp ( const void *a , const void *b ) 
{ 
     return *(int *)a - *(int *)b; 
} 
int main ()
{
//	ta = clock();
	int i,j,k = 0;
	for ( i = 0; i < max; i++ )
		c[i] = b[i] = false;
	for ( i = 5; i <= 1002; i+=4 )
	{
		for ( j = i; i*j <= max; j+=4 )
			b[i*j] = true;
	}
	for ( i = 5; i <= 1002; i+=4 )
	{
		if ( b[i] == true )
			continue;
		for ( j = i; i*j <= max; j+=4 )
		{
			if ( b[j] == true )
				continue;
			if ( c[i*j] == false )
			{
				a[k++] = i*j;
				c[i*j] = true;
			}
		}
	}
//	cout<<"k="<<k<<endl;
//	tb = clock();
//	cout<<"time is "<<tb-ta<<endl;
	qsort(a,k,sizeof(a[0]),cmp);
//	tb = clock();
//	cout<<"after sorted, use "<< tb-ta <<endl;
//	int begin,end,mid;
//	begin = 0;
//	end = k-1;
	while ( cin>>j && j!=0 )
	{
		for ( i = 0; a[i] <= j; i++ )
			;
		cout<<j<<" "<<i<<endl;
	}
	return 0;
}
