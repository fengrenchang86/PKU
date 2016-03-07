#include <iostream>
#include <string.h>
using namespace std;
struct ac
{
	int high;
	char a[120][12];
}t[120];
int n,w,b;
int low;
char ch[210][12];
void init ()
{
	int i,j;
	for ( i = 0; i < 200; i++ )
		for ( j =0 ; j < w;j++)
			ch[i][j] = '.';
}
int comp ( char *a, char *c )
{
	int i;
	for ( i = 0; i < b; i++ )
	{
		if ( a[i] == 'X' && c[i] == 'X' )
			return 0;
	}
	return 1;
}
int main ()
{
	int rec[100][2];
	int e1,e2;
	int i,j,k,l;
	bool com;
	while ( scanf("%d%d%d",&n,&w,&b) )
	{
		e1 = e2 = 0;
		if ( n == 0 && w==0 &&b==0)
			break;
		for ( i = 0; i < n; i++ )
		{
			cin>>t[i].high;
			for ( j = t[i].high-1; j >=0;j-- )
				cin>>t[i].a[j];
		}
		low = 0;
		for ( i = 0; i < t[0].high; i++ )
		{
			for ( j = 0; j < w; j++ )
				ch[i][j] = t[0].a[i][j];
		}
		low = t[0].high;
		for ( k = 1; k < n; k++ )
		{
			for ( i = 1; low-i >=0; i++ )
			{
				com = true;
				for ( j = 0; j < i; j++ )
				{
					if ( comp(t[k].a[j],ch[low-i+j]) == 0 )
					{
						com = false;
						break;
					}
				}
				if ( com == false )
					break;
			}
			i--;
			if ( low-i+t[k].high > b )
			{
				rec[e1][0] = low;
				e1++;
				init();
				for ( i = 0; i < t[k].high;i++)
					for ( j = 0; j < w; j++ )
						ch[i][j] = t[k].a[i][j];
					low = t[k].high;
				continue;
			}
			for ( j = 0; j < t[k].high;j++ )
			{
				for ( l = 0; l < w; l++ )
					if ( ch[low-i+j][l] != 'X' )
						ch[low-i+j][l] = t[k].a[j][l];
			}
			if ( low - i + t[k].high > low )
				low = low-i+t[k].high;
		}
		rec[e1++][0] = low;
		low = 0;
		for ( i = 0; i < t[n-1].high; i++ )
		{
			for ( j = 0; j < w; j++ )
				ch[i][j] = t[0].a[i][j];
		}
		low = t[0].high;
		for ( k = n-2; k >= 0; k-- )
		{
			for ( i = 1; low-i >=0; i++ )
			{
				com = true;
				for ( j = 0; j < i; j++ )
				{
					if ( comp(t[k].a[j],ch[low-i-j]) == 0 )
					{
						com = false;
						break;
					}
				}
				if ( com == false )
					break;
			}
			i--;
			if ( low-i+t[k].high > b )
			{
				rec[e2][1] = low;
				e2++;
				init();
				for ( i = 0; i < t[k].high;i++)
					for ( j = 0; j < w; j++ )
						ch[i][j] = t[k].a[i][j];
					low = t[k].high;
				continue;
			}
			for ( j = 0; j < t[k].high;j++ )
			{
				for ( l = 0; l < w; l++ )
					if ( ch[low-i+j][l] != 'X' )
						ch[low-i+j][l] = t[k].a[j][l];
			}
			if ( low - i + t[k].high > low )
				low = low-i+t[k].high;
		}
		rec[e2++][1] = low;
		if ( e2 < e1 )
		{
			for ( i = 0; i < e2-1; i++ )
				printf("%d ",rec[i][1]);
			printf("%d\n",rec[e2-1][1]);
		}
		else
		{
			for ( i = 0; i < e1-1;i++ )
				printf("%d ",rec[i][0]);
			printf("%d\n",rec[e1-1][0]);
		}
	}
	return 0;
}