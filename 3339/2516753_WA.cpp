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
	if ( c->position != d->position )
		return c->position-d->position;
	else if ( c->num != d->num )
		return c->num-d->num;
	else
		return d->year-c->year;
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
		i = 0;
		while ( a[i].position != 'D' && i < 22)
			i++;
		while ( d > 0 && i < 22)
		{
			if ( a[i].position == 'D' )
			{
				a[i].year *= -1;
				d--;
			}
			else
				break;
			i++;
		}
		if ( d>0 )
		{
			printf("IMPOSSIBLE TO ARRANGE\n");
			continue;
		}
		while ( a[i].position != 'M' && i < 22)
			i++;
		while (m>0&& i < 22 )
		{
			if ( a[i].position == 'M' )
			{
				a[i].year *= -1;
				m--;
			}
			else
				break;
			i++;
		}
		if ( m> 0 )
		{
			printf("IMPOSSIBLE TO ARRANGE\n");
			continue;
		}
		while ( a[i].position != 'S' && i < 22 )
			i++;
		while ( i < 22 && s > 0 )
		{
			if ( a[i].position == 'S' )
			{
				a[i].year *= -1;
				s--;
			}
			else
				break;
			i++;
		}
		if ( s > 0 )
		{
			printf("IMPOSSIBLE TO ARRANGE\n");
			continue;
		}
		for ( i =0 ; i < 22; i++ )
			if ( a[i].position == 'G' )
				break;
		if ( i == 22 )
		{
			printf("IMPOSSIBLE TO ARRANGE\n");
			continue;
		}
		g = i;
		cap = i;
		for ( i = 0; i < 22; i++ )
		{
			if ( a[i].year < 0 && abs(a[i].year) > abs(a[cap].year) )
				cap = i;
			else if ( a[i].year < 0 && abs(a[i].year) == abs(a[cap].year) && a[i].num > a[cap].num)
				cap = i;
		}
		printf("%d %s %c\n",a[cap].num,a[cap].name,a[cap].position);
		if ( g != cap )
		{
			printf("%d %s %c\n",a[g].num,a[g].name,a[g].position);
			a[cap].year *= -1;
		}
		for ( i = 0; i < 22; i++ )
		{
			if ( a[i].year < 0 )
				printf("%d %s %c\n",a[i].num,a[i].name,a[i].position);
		}
	}
	return 0;
}
