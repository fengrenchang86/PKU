#include <iostream>
#include <stdlib.h>
using namespace std;
int id[1100];
struct ac
{
	int m;
	int num[10];
	int price;
}a[100];
struct wa
{
	int id;
	int number;
	int singlep;
}b[6];
int n,s;
int v[6];
int min=0;
int main ()
{
	int c[6][6][6][6][6];
	int i,j,x,y;
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d%d%d",&b[i].id,&b[i].number,&b[i].singlep);
		id[b[i].id] = i;
		min += b[i].number*b[i].singlep;
	}
	while ( i < 5 )
	{
		b[i].id = 1000+i;
		b[i].number = 0;
		b[i].singlep = 0;
		id[1000+i] = i;
		i++;
	}
	scanf("%d",&s);
	for ( i = 0; i < n; i++ )
	{
		scanf("%d",&a[i].m);
		for ( j = 0; j < 5; j++ )
			a[i].num[j] = 0;
		for ( j = 0; j < a[i].m; j++ )
		{
			scanf("%d%d",&x,&y);
			x = id[x];
			a[i].num[x] = y;
		}
	 	scanf("%d",&a[i].price);
	}
	c[0][0][0][0][0] = 0;
	int i1,i2,i3,i4,i5;
	for ( i1 = 0; i1 <= b[0].number; i1 ++ )
	{
		for ( i2 = 0; i2 <= b[1].number; i2++ )
		{
			for ( i3 = 0; i3 <= b[2].number; i3++ )
			{
				for ( i4 = 0; i4 <= b[3].number; i4++ )
				{
					for ( i5 = 0; i5 <= b[4].number; i5++ )
					{
						c[i1][i2][i3][i4][i5] = i1*b[0].singlep+i2*b[1].singlep+i3*b[2].singlep+i4*b[3].singlep+i5*b[4].singlep;
						for ( i = 0; i < s; i++ )
						{							
							if ( i1-a[i].num[0] >= 0 && i2-a[i].num[1] >=0 && i3-a[i].num[2]>=0 && i4-a[i].num[3]>=0 && i5-a[i].num[4]>=0 )
							{
								if ( c[i1][i2][i3][i4][i5] > c[i1-a[i].num[0]][i2-a[i].num[1]][i3-a[i].num[2]][i4-a[i].num[3]][i5-a[i].num[4]]+a[i].price )
									c[i1][i2][i3][i4][i5] = c[i1-a[i].num[0]][i2-a[i].num[1]][i3-a[i].num[2]][i4-a[i].num[3]][i5-a[i].num[4]]+a[i].price;
							}
						}
					}
				}
			}
		}
	}
	cout<<c[b[0].number][b[1].number][b[2].number][b[3].number][b[4].number]<<endl;
	return 0;
}