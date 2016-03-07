
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
int m,n,M;
int tc = 1;
struct ac
{
	int x;
	int y;
	int z;
	int num;
}v[250];
int a[22][201][8010];
int b[22][201][8010];
int *xa = new int[210];
int *xb = new int[210];
int *xc = new int[210];
int *xd = new int[210];
int pos;
int *xt;
int comp ( const void *a, const void *b )
{
	return *(int *)a - *(int *)b;
}
int cmp( const void *a , const void *b ) 
{ 
    struct ac *c = (ac *)a; 
    struct ac *d = (ac *)b; 
	return abs(d->x)+abs(d->y)-abs(c->x)-abs(c->y);
} 
int main ()
{
	int i,j,k,l;
	int max;
	int x,y;
	int suma,sumb,maxa,maxb;
//	fstream cin("in.txt");
	while ( cin>>n>>m && !(m==0&&n==0) )
	{
		for ( i = 0; i <= n; i++ )
			v[i].num = i;
		v[0].z = -1;
		v[0].x = v[0].y = 8000;
		for ( i = 1; i <= n; i++ )
		{
			cin>>v[i].x>>v[i].y;
			v[i].z = v[i].x-v[i].y+20;
		}
		qsort(v,n+1,sizeof(v[0]),cmp);
		for ( j = 1; j <= n; j++ )
		{
			for ( k = 1; k <= 8000; k++ )
			{
				if ( v[j].z <= k )
					a[1][j][k] = v[j].z;
				else
					a[1][j][k] = 0;
			}
		}
		for ( i = 2; i <= m; i++ )
		{
			for ( j = i; j <= n; j++ )
			{
				for ( k = 0; k <= 8000; k++ )
				{
					b[i][j][k] = 0;
					if ( v[j].z > k )
					{
						a[i][j][k] = 0;
						continue;
					}
					max = 0;
					for ( l = i-1; l <= j-1; l++ )
					{
						if ( (a[i-1][l][k-v[j].z] + v[j].z) > max )
						{
							max = (a[i-1][l][k-v[j].z] + v[j].z);
							b[i][j][k] = l;
						}
					}
					a[i][j][k] = max;
				}
			}
		}
		max = 0;
		for ( j = m; j <= n; j++ )
		{
			if ( a[m][j][20*m] > max )
			{
				max = a[m][j][20*m];
				l = j;
				pos = 0;
				xa[pos] = l;
				xb[pos] = max;
				pos++;
			}
			else if ( a[m][j][20*m] == max )
			{
				xa[pos] = j;
				xb[pos] = a[m][j][20*m];
				pos++;
			}
		}
		y = 20*m;
		x = 20*m-max;
		for ( j = m; j <= n; j++ )
		{
			for ( k = 0; k <= x; k++ )
			{
				if ( a[m][j][k+20*m] > max )
				{
					max = a[m][j][k+20*m];
					l = j;
					y = k+20*m;
					pos = 0;
					xa[pos] = l;
					xb[pos] = max;
					pos++;
				}
				else if ( a[m][j][k+20*m] == max )
				{
					xa[pos] = j;
					xb[pos] = a[m][j][k+20*m];
					pos++;
				}
			}
		}
		max = 0;
		maxa = 0;
		maxb = 0;
		for ( i = 0; i < pos; i++ )
		{
			j = 0;
			l = xa[i];
			y = xb[i];
			M = m;
			suma = 0;
			sumb = 0;
			while ( l != 0 )
			{
				xc[j] = v[l].num;
				suma += v[l].x;
				sumb += v[l].y;
				x = v[l].z;
				l = b[M][l][y];
				M--;
				y-=x;
				j++;
			}
			if ( suma + sumb > maxa + maxb )
			{
				maxa = suma;
				maxb = sumb;
				xt = xc;
				xc = xd;
				xd = xt;
			}
		}
		printf("Jury #%d\n",tc);
		tc++;
		printf("Best jury has value %d for prosecution and value %d for defence:\n",maxa,maxb);
		qsort(xd,m,sizeof(xd[0]),comp);
		for ( j = 0; j < m; j++ )
			printf(" %d",xd[j]);
		printf(" \n");
	}
	return 0;
}
