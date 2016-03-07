#include <iostream>
#include <stdlib.h>
using namespace std;
struct wf
{
	char name[30];
	int num;
	int year;
	char position;
}a[30];
int cmp( const void *a, const void *b )
{
	struct wf *c = (wf*)a;
	struct wf *d = (wf*)b;
	return c->num - d->num;
}
int worldfinal( char *a )
{
	int x = (a[0]-'0')*1000+(a[1]-'0')*100+(a[2]-'0')*10+a[3]-'0';
	int y = (a[5]-'0')*1000+(a[6]-'0')*100+(a[7]-'0')*10+a[8]-'0';
	return (y-x+1);
}
int main ()
{
	int i,m,d,s,g,cap;
	char ch;
	char year[30];
	while ( cin>>a[0].num && a[0].num != 0)
	{
		g = -1;
		cin>>a[0].name>>a[0].position;
		while ( scanf("%c",&ch) && ch == ' ' )
		{
			scanf(" %s",&year);
			a[0].year+=worldfinal(year);
		}
		for ( i = 1; i < 22; i++ )
		{
			cin>>a[i].num>>a[i].name>>a[i].position;
			a[i].year = 0;
			while ( scanf("%c",&ch) && ch == ' ' )
			{
				scanf(" %s",&year);
				a[i].year+=worldfinal(year);
			}
		}
		qsort(a,22,sizeof(a[0]),cmp);
		m = d = s = g = 0;
		while ( scanf("%c",&ch) && ch != '-' )
		{
			d*=10;
			d+=(ch-'0');
		}
		while ( scanf("%c",&ch) && ch != '-' )
		{
			m*=10;
			m+=(ch-'0');
		}
		while ( scanf("%c",&ch) && ch >= '0' && ch <= '9' )
		{
			s*=10;
			s+=(ch-'0');
		}
		g = 1;
		for ( i = 0; i < 22; i++ )
		{
			if ( a[i].position == 'G' && g > 0 )
			{
				cap = i;
				a[i].year *= -1;
				g--;
			}
			else if ( a[i].position == 'S' && s > 0 )
			{
				a[i].year *= -1;
				s--;
			}
			else if ( a[i].position == 'D' && d > 0 )
			{
				a[i].year *= -1;
				d--;
			}
			else if ( a[i].position == 'M' && m > 0 )
			{
				a[i].year *= -1;
				m--;
			}
		}
		if ( s == 0 && m == 0 && d == 0 && g == 0 )
		{
			for ( i = 0; i < 22; i++ )
			{
				if ( a[i].year < 0 )
				{
					if ( abs(a[i].year) > abs(a[cap].year) )
						cap = i;
					else if ( abs(a[i].year) == abs(a[cap].year) && a[i].num > a[cap].num)
						cap = i;
				}
			}
			printf("%d %s %c\n",a[cap].num,a[cap].name,a[cap].position);
			a[cap].year *= -1;
			for ( i = 0; i < 22; i++ )
			{
				if ( a[i].year < 0 && a[i].position == 'G' )
					printf("%d %s %c\n",a[i].num,a[i].name,a[i].position);
			}
			for ( i = 0; i < 22; i++ )
			{
				if ( a[i].year < 0 && a[i].position == 'D' )
					printf("%d %s %c\n",a[i].num,a[i].name,a[i].position);
			}
			for ( i = 0; i < 22; i++ )
			{
				if ( a[i].year < 0 && a[i].position == 'M' )
					printf("%d %s %c\n",a[i].num,a[i].name,a[i].position);
			}
			for ( i = 0; i < 22; i++ )
			{
				if ( a[i].year < 0 && a[i].position == 'S' )
					printf("%d %s %c\n",a[i].num,a[i].name,a[i].position);
			}
		}
		else
			printf("IMPOSSIBLE TO ARRANGE\n");
		printf("\n");
	}
	return 0;
}

